/*
 * Rudy Castan, Junseop Nam
 * CS200
 * Fall 2022
 */
#include "GLTexture.h"
#include <stb_image.h>

/**
 * Destructor for GLTexture class.
 * Deletes the GPU texture.
 *
 * @return None.
 */
GLTexture::~GLTexture() noexcept
{
	delete_texture();
}

/**
 * Destructor for GLTexture class.
 * Deletes the GPU texture.
 *
 * @return None.
 */
GLTexture::GLTexture(GLTexture&& other) noexcept
{
	texture_handle = other.texture_handle;
	width = other.width;
	height = other.height;

	other.texture_handle = 0;
	other.width = 0;
	other.height = 0;
}

/**
 * Move assignment operator for GLTexture class.
 * Moves the OpenGL texture resource from 'other' to the current instance.
 *
 * @param other - An r-value reference to another GLTexture object.
 * @return A reference to the current GLTexture object.
 */
GLTexture& GLTexture::operator=(GLTexture&& other) noexcept
{
	GLTexture temp(std::move(other));

	texture_handle = temp.texture_handle;
	width = temp.width;
	height = temp.height;

	return *this;
}

/**
 * Loads an image from a file and initializes the GLTexture object with it.
 *
 * @param image_filepath - The path to the image file.
 * @param flip_vertical - Indicates if the image should be flipped vertically on load.
 * @return True if the image was successfully loaded and initialized, false otherwise.
 */
bool GLTexture::LoadFromFileImage(const std::filesystem::path& image_filepath, bool flip_vertical) noexcept
{
    stbi_set_flip_vertically_on_load(flip_vertical);

    int desired_channels = 4;
    unsigned char* image_data = stbi_load(image_filepath.string().c_str(), &width, &height, nullptr, desired_channels);

    if (!image_data)
    {
        return false;
    }

    bool memory = LoadFromMemory(width, height, reinterpret_cast<RGBA*>(image_data));

    stbi_image_free(image_data);

    return memory;
}

/**
 * Initializes the GLTexture object with image data provided in memory.
 *
 * @param image_width - The width of the image.
 * @param image_height - The height of the image.
 * @param colors - Pointer to RGBA color data.
 * @return True if initialization was successful, false otherwise.
 */
bool GLTexture::LoadFromMemory(int image_width, int image_height, const RGBA* colors) noexcept
{
    glDeleteTextures(1, &texture_handle);

    width = image_width;
    height = image_height;

    glGenTextures(1, &texture_handle);
    glBindTexture(GL_TEXTURE_2D, texture_handle);

    glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);

    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, colors);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        return false;
    }

    return true;
}

/**
 * Binds the texture to a specific texture unit.
 *
 * @param texture_unit - The texture unit to bind the texture to.
 */
void GLTexture::UseForSlot(unsigned int texture_unit) const noexcept
{
	glBindTextureUnit(texture_unit, texture_handle);
}

/**
 * Sets the texture filtering mode.
 *
 * @param how_to_filter - The filtering mode to apply (NearestPixel or Bilinear).
 */
void GLTexture::SetFiltering(Filtering how_to_filter) noexcept
{
	if (texture_handle == 0)
		return;

	filtering = how_to_filter;

	glBindTexture(GL_TEXTURE_2D, texture_handle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (filtering == Filtering::NearestPixel) ? GL_NEAREST : GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (filtering == Filtering::NearestPixel) ? GL_NEAREST : GL_LINEAR);
}

/**
 * Sets the texture wrapping mode for the specified coordinate axis.
 *
 * @param how_to_wrap - The wrapping mode to apply (Repeat, ClampToEdge, ClampToBorder, MirroredRepeat, MirrorClampToEdge).
 * @param coord - The coordinate axis to apply the wrapping mode (S or T).
 */
void GLTexture::SetWrapping(Wrapping how_to_wrap, Coordinate coord) noexcept
{
    if (texture_handle == 0)
        return;

    glBindTexture(GL_TEXTURE_2D, texture_handle);

    GLenum axis = (coord == Coordinate::S) ? GL_TEXTURE_WRAP_S : GL_TEXTURE_WRAP_T;

    GLenum mode{};
    switch (how_to_wrap)
    {
    case Wrapping::Repeat:
        mode = GL_REPEAT;
        break;
    case Wrapping::ClampToEdge:
        mode = GL_CLAMP_TO_EDGE;
        break;
    case Wrapping::ClampToBorder:
        mode = GL_CLAMP_TO_BORDER;
        break;
    case Wrapping::MirroredRepeat:
        mode = GL_MIRRORED_REPEAT;
        break;
    case Wrapping::MirrorClampToEdge:
        mode = GL_MIRROR_CLAMP_TO_EDGE;
        break;

    }

    glTexParameteri(GL_TEXTURE_2D, axis, mode);
}

/**
 * Deletes the GPU texture handle, setting it to 0, and resets width and height.
 */
void GLTexture::delete_texture() noexcept
{
    if (texture_handle != 0)
    {
        glDeleteTextures(1, &texture_handle);
        texture_handle = 0; // so we don't accidentally double delete it
    }

    width = 0;
    height = 0;
}