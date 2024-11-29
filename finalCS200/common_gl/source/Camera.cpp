
#include "Camera.h"
#include <cmath>

Camera::Camera(vec2 camera_position, vec2 camera_up) noexcept 
:Position(camera_position), IsFirstPerson(false), up(camera_up), right(perpendicular_to(up)), orientation(static_cast<float>(atan2(up.y, up.x)))
{
}

void Camera::SetUp(vec2 camera_up) noexcept
{
    up = camera_up;
    right = vec2 ( -up.y, up.x );
    orientation = std::atan2(float(up.y), float(up.x));
}

void Camera::SetOrientation(float angle_radians) noexcept
{
    up = vec2{ std::cos(orientation), std::sin(orientation) };
    right = perpendicular_to(up);
    orientation = angle_radians;
}

void Camera::MoveUp(float distance) noexcept
{
    Position += up * distance;
}

void Camera::MoveRight(float distance) noexcept
{
    Position += right * distance;
}

void Camera::Rotate(float angle_radians) noexcept
{
    SetOrientation(orientation + angle_radians);
}

mat3 Camera::BuildCameraToWorld() const noexcept
{
    const vec2 translation = IsFirstPerson ? Position : vec2{ Position.x, Position.y };

    return mat3{ {right.x, up.x, translation.x},
                 {right.y, up.y, translation.y},
                 {0.0f,    0.0f, 1.0f} };
}

mat3 Camera::BuildWorldToCamera() const noexcept
{
    const vec2 translation = IsFirstPerson ? vec2(- Position.x, -Position.y ) : vec2{-Position.x, -Position.y};

    return mat3{ {right.x, up.x, translation.x},
                 {right.y, up.y, translation.y},
                 {0.0f,    0.0f, 1.0f} };
}
