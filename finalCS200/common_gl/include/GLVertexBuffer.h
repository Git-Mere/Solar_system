/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once

#include <GL/glew.h>
#include <GLHandle.h>
#include <span>


class [[nodiscard]] GLVertexBuffer
{
    GLsizei  size          = 0;
    GLHandle buffer_handle = 0;

public:
    /**
    * @brief Constructs a GLVertexBuffer with the specified size in bytes.
    * @param size_in_bytes The size of the buffer in bytes.
    * This constructor generates a buffer handle, binds it to GL_ARRAY_BUFFER, allocates storage
    * for the buffer, and then unbinds the buffer. The storage is allocated with dynamic usage.
    */
    explicit GLVertexBuffer(GLsizei size_in_bytes);

    template <typename T, auto N = std::dynamic_extent>
    GLVertexBuffer(std::span<T, N> buffer_data) : GLVertexBuffer(static_cast<GLsizei>(buffer_data.size_bytes()))
    {
        send_buffer_data_to_gpu(buffer_data.data(), size, 0);
    }

    /**
    * @brief Destructor for GLVertexBuffer.
    * This destructor deletes the buffer handle, freeing the associated GPU memory.
     */
    ~GLVertexBuffer();

    /**
    * @brief Move constructor for GLVertexBuffer.
    * This constructor performs a move operation, transferring ownership of the buffer handle.
    * The source GLVertexBuffer is left in a valid but unspecified state.
    */
    GLVertexBuffer(const GLVertexBuffer&) = delete;

    /**
    * @brief Move assignment operator for GLVertexBuffer.
    * This operator transfers ownership of the buffer handle from the source GLVertexBuffer to this one.
    * The source GLVertexBuffer is left in a valid but unspecified state.
    * @param temp The source GLVertexBuffer to move from.
    * @return A reference to this GLVertexBuffer.
    */
    GLVertexBuffer& operator=(const GLVertexBuffer&) = delete;
    GLVertexBuffer(GLVertexBuffer&& temp) noexcept;
    GLVertexBuffer& operator=(GLVertexBuffer&& temp) noexcept;

    /**
     * @brief Binds or unbinds the GLVertexBuffer.
     * @param bind If true, binds the GLVertexBuffer; if false, unbinds it.
     * Binds the GLVertexBuffer to the GL_ARRAY_BUFFER target if `bind` is true.
     * Unbinds the GLVertexBuffer if `bind` is false.
    */
    void Use(bool bind = true) const;

    template <typename T, auto N = std::dynamic_extent>
    void SetData(std::span<T, N> buffer_data, GLsizei starting_offset = 0) const
    {
        send_buffer_data_to_gpu(buffer_data.data(), static_cast<GLsizei>(buffer_data.size_bytes()), starting_offset);
    }

    [[nodiscard]] GLHandle GetHandle() const noexcept
    {
        return buffer_handle;
    }

    [[nodiscard]] GLsizei GetSizeBytes() const noexcept
    {
        return size;
    }

private:
    /**
    * @brief Sends data to the GPU for the GLVertexBuffer.
    * @param data Pointer to the data to be sent.
    * @param size_bytes Size of the data in bytes.
    * @param starting_offset Starting offset in the buffer.
    * Binds the GLVertexBuffer to the GL_ARRAY_BUFFER target, sends the specified data
    * to the GPU starting from the provided offset, and then unbinds the buffer.
    */
    void send_buffer_data_to_gpu(const void* data, GLsizei size_bytes, GLsizei starting_offset) const;
};
