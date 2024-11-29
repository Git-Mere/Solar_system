/*
 * Rudy Castan, Junseop Nam
 * CS200
 * Fall 2022
 */
#include "CameraView.h"

 /**
  * @brief Sets the size of the framebuffer.
  *
  * @param the_framebuffer_size The size of the framebuffer as a 2D vector.
  *
  * This function updates the size of the framebuffer used by the camera view.
  */
void CameraView::SetFramebufferSize(vec2 the_framebuffer_size) noexcept
{
    framebuffer_size = the_framebuffer_size;
}

/**
 * @brief Sets the size of the framebuffer using pixel width and height.
 *
 * @param new_pixel_width The width of the framebuffer in pixels.
 * @param new_pixel_height The height of the framebuffer in pixels.
 *
 * This function updates the size of the framebuffer used by the camera view.
 */
void CameraView::SetFramebufferSize(int new_pixel_width, int new_pixel_height) noexcept
{
    SetFramebufferSize(vec2{ float(new_pixel_width), float(new_pixel_height) });
}

/**
 * @brief Retrieves the size of the camera view.
 *
 * @return A 2D vector representing the size of the camera view.
 *
 * This function returns the dimensions of the camera view.
 */
vec2 CameraView::GetViewSize() const
{
    return framebuffer_size;
}

/**
 * @brief Sets the zoom level of the camera view.
 *
 * @param new_zoom The new zoom level to set.
 *
 * This function adjusts the zoom level of the camera view, but ensures it is non-zero.
 */
void CameraView::SetZoom(float new_zoom) noexcept
{
    if (new_zoom != 0.0f)
    {
        zoom = new_zoom;
    }
}

/**
 * @brief Builds a transformation matrix to convert from camera space to normalized device coordinates (NDC).
 *
 * @return The transformation matrix.
 *
 * This function constructs a 3x3 transformation matrix that scales by the inverse of the zoom factor and translates
 * by half of the negated framebuffer size, effectively mapping the camera space to NDC.
 */
mat3 CameraView::BuildCameraToNDC() const noexcept
{
    vec2 vactor = CalcViewSizeWithZoom();
    return { {2 / vactor.x, 0.0f        , 0.0f},
             {0.0f        , 2 / vactor.y, 0.0f},
             {0.0f        , 0.0f        , 1.0f} };
}

/**
 * @brief Builds a transformation matrix to convert from window device coordinates to camera space.
 *
 * @return The transformation matrix.
 *
 * This function constructs a 3x3 transformation matrix that scales by the inverse of the zoom factor and translates
 * by half of the negated framebuffer size, effectively mapping window device coordinates to camera space.
 */
mat3 CameraView::BuildWindowDeviceToCamera() const noexcept
{
    float scale = zoom;
    vec2 translate = vec2(-framebuffer_size.x / 2.0f, framebuffer_size.y / 2.0f);

    return mat3::build_scale(vec2{ 1.0f / scale, 1.0f / scale }) * mat3::build_translation(translate * (-1));
}