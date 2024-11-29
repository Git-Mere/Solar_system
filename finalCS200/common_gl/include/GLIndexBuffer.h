/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once

#include "GLHandle.h"
#include <GL/glew.h>
#include <span>

struct GLIndexElement
{
    enum Type : unsigned
    {
        UInt   = GL_UNSIGNED_INT,
        UShort = GL_UNSIGNED_SHORT,
        UByte  = GL_UNSIGNED_BYTE,
        None   = 0
    };
};

class [[nodiscard]] GLIndexBuffer
{
    GLIndexElement::Type element_type   = GLIndexElement::None;
    GLsizei              count          = 0;
    GLHandle             indices_handle = 0;

public:
    /**
    * @brief Constructs a GLIndexBuffer with the provided indices.
    * This constructor creates an indices buffer with the given indices and sets the count and element type.
    * @param indices A span of unsigned int integers representing the indices.
    */
    GLIndexBuffer() = default;

    /**
    * @brief Constructs a GLIndexBuffer with the provided indices.
    * This constructor creates an indices buffer with the given indices and sets the count and element type.
    * @param indices A span of unsigned short integers representing the indices.
    */
    GLIndexBuffer(std::span<const unsigned int> indices);

    /**
    * @brief Constructs a GLIndexBuffer with the provided indices.
    * This constructor creates an indices buffer with the given indices and sets the count and element type.
    * @param indices A span of unsigned characters representing the indices.
    */
    GLIndexBuffer(std::span<const unsigned short> indices);

    /**
    * @brief Constructs a GLIndexBuffer with an array of unsigned char indices.
    * This constructor creates an index buffer from the provided span of unsigned char indices,
    * calculates the count of indices, and sets the element type to UByte.
    * @param indices A span of unsigned char indices.
    */
    GLIndexBuffer(std::span<const unsigned char> indices);

    /**
    * @brief Destructor for GLIndexBuffer.
    * This destructor releases the OpenGL buffer associated with the indices.
    */
    ~GLIndexBuffer();

    GLIndexBuffer(const GLIndexBuffer&) = delete;
    GLIndexBuffer& operator=(const GLIndexBuffer&) = delete;

    /**
    * @brief Move constructor for GLIndexBuffer.
    * This constructor moves the resources from 'temp' to the new GLIndexBuffer.
    * It transfers the indices handle, count, and element type, and then sets the
    * original GLIndexBuffer 'temp' to a valid but unspecified state.
    * @param temp An r-value reference to a GLIndexBuffer.
    */
    GLIndexBuffer(GLIndexBuffer&& temp) noexcept;

    /**
    * @brief Move assignment operator for GLIndexBuffer.
    * This operator moves the resources from 'temp' to the current GLIndexBuffer.
    * It transfers the indices handle, count, and element type, and then sets the
    * original GLIndexBuffer 'temp' to a valid but unspecified state. It then returns
    * a reference to the modified GLIndexBuffer.
    * @param temp An r-value reference to a GLIndexBuffer.
    * @return A reference to the modified GLIndexBuffer.
    */
    GLIndexBuffer& operator=(GLIndexBuffer&& temp) noexcept;

    /**
    * @brief Binds or unbinds the GLIndexBuffer.
    * If 'bind' is true, this function binds the GLIndexBuffer by binding the
     * element array buffer to the stored indices handle. If 'bind' is false, it
    * unbinds the GLIndexBuffer by binding the element array buffer to 0.
    * @param bind Boolean flag indicating whether to bind or unbind.
     */
    void Use(bool bind = true) const;

    [[nodiscard]] GLHandle GetHandle() const noexcept
    {
        return indices_handle;
    }

    [[nodiscard]] GLsizei GetCount() const noexcept
    {
        return count;
    }

    [[nodiscard]] GLIndexElement::Type GetElementType() const noexcept
    {
        return element_type;
    }
    template<typename T>
    void create_indices_buffer(std::span<T>indices)
    {
        glCreateBuffers(1, &indices_handle);
        glNamedBufferStorage(indices_handle, sizeof(T) * indices.size(), indices.data(), GL_DYNAMIC_STORAGE_BIT);
    }
};
