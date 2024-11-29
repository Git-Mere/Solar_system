/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once

#include "GLHandle.h"
#include "GLIndexBuffer.h"
#include "GLVertexBuffer.h"
#include <GL/glew.h>
#include <memory>
#include <vector>

struct GLAttributeLayout
{
    enum ComponentType : GLenum
    {
        Float = GL_FLOAT,
        Int   = GL_INT,
        Bool  = GL_BOOL
    };
    ComponentType component_type = ComponentType::Float;
    enum NumComponents : GLint
    {
        _1 = 1,
        _2 = 2,
        _3 = 3,
        _4 = 4
    };
    NumComponents component_dimension = NumComponents::_1;
    // Is this the 1st, 2nd, 3rd... (0, 1, 2...) "in attribute" of the vertex shader?
    GLuint vertex_layout_location = 0;
    // should be false for float types
    // if normalized is GL_TRUE, then integer data is normalized to the range [-1, 1]
    // If normalized is GL_FALSE then integer data is directly converted to floating point.
    GLboolean normalized = GL_FALSE;
    // byte offset to read the very 1st attribute
    // should be 0 for parallel array and struct of arrays
    // should be offsetof(Vertex, field) for array of structs
    GLuint relative_offset = 0;
    // byte offset into where we are in the buffer
    //  do we start at the beginning or somewhere in the middle for this attribute?
    GLintptr offset = 0;
    // how many bytes to step to the next attribute
    GLsizei stride = 0;
};
struct GLPrimitive
{
    enum Type : GLenum
    {
        Points        = GL_POINTS,
        Lines         = GL_LINES,
        LineLoop      = GL_LINE_LOOP,
        LineStrip     = GL_LINE_STRIP,
        Triangles     = GL_TRIANGLES,
        TriangleStrip = GL_TRIANGLE_STRIP,
        TriangleFan   = GL_TRIANGLE_FAN,
    };
};

class [[nodiscard]] GLVertexArray
{
    GLHandle                    vertex_array_handle = 0;
    std::vector<GLVertexBuffer> vertex_buffers;
    GLIndexBuffer               index_buffer;
    GLsizei                     num_indices       = 0;
    GLIndexElement::Type        indices_type      = GLIndexElement::None;
    GLPrimitive::Type           primitive_pattern = GLPrimitive::Triangles;
    GLsizei                     num_vertices      = 0;

public:
    /**
     * @brief Constructs a GLVertexArray object with the specified primitive pattern.
    * This constructor creates a GLVertexArray object with the given primitive pattern.
    * It also generates a vertex array handle and assigns it to the object.
    * @param the_primitive_pattern The primitive pattern for the vertex array.
    */
    explicit GLVertexArray(GLPrimitive::Type the_primitive_pattern = GLPrimitive::Triangles);

    /**
    * @brief Destroys the GLVertexArray object.
    * This destructor releases the associated vertex array handle.
    */
    ~GLVertexArray();

    GLVertexArray(const GLVertexArray&) = delete;
    GLVertexArray& operator=(const GLVertexArray&) = delete;

    /**
    * @brief Move constructor for GLVertexArray.
    * @param temp Temporary GLVertexArray to be moved.
    * This move constructor transfers ownership of resources from `temp` to the new GLVertexArray object.
    */
    GLVertexArray(GLVertexArray&& temp) noexcept;

    /**
    * @brief Move assignment operator for GLVertexArray.
    * @param temp Temporary GLVertexArray to be moved.
    * @return Reference to the modified GLVertexArray.
    * This move assignment operator transfers ownership of resources from `temp` to the current GLVertexArray object.
    */
    GLVertexArray& operator=(GLVertexArray&& temp) noexcept;

    /**
    * @brief Binds or unbinds the GLVertexArray.
    * @param bind True to bind, false to unbind.
    * If `bind` is true, this function binds the GLVertexArray.
    * If `bind` is false, it unbinds the currently bound GLVertexArray.
    */
    void Use(bool bind = true) const;

    /**
    * @brief Adds a GLVertexBuffer to the GLVertexArray.
    * @param vertex_buffer The GLVertexBuffer to be added.
    * @param buffer_layout An initializer list of GLAttributeLayouts specifying the layout of the vertex buffer.
    * This function enables the vertex attribute specified in each GLAttributeLayout in the GLVertexArray,
    * associates it with the provided GLVertexBuffer, sets up the attribute format, and binds the attribute
    * to the specified vertex buffer binding index.
    */
    void AddVertexBuffer(GLVertexBuffer&& vertex_buffer, std::initializer_list<GLAttributeLayout> buffer_layout);

    /**
    * @brief Sets the index buffer for the GLVertexArray.
    * @param the_indices The GLIndexBuffer to be used as the index buffer.
    * This function associates the provided GLIndexBuffer with the GLVertexArray for indexed rendering.
    * It also updates the count of indices, vertices, and the type of indices in the GLVertexArray.
    */
    void SetIndexBuffer(GLIndexBuffer&& the_indices);

    [[nodiscard]] GLHandle GetHandle() const noexcept
    {
        return vertex_array_handle;
    }

    [[nodiscard]] const auto& GetVertexBuffers() const
    {
        return vertex_buffers;
    }

    [[nodiscard]] const auto& GetIndexBuffer() const
    {
        return index_buffer;
    }

    [[nodiscard]] GLsizei GetIndicesCount() const noexcept
    {
        return num_indices;
    }

    [[nodiscard]] GLIndexElement::Type GetIndicesType() const noexcept
    {
        return indices_type;
    }

    [[nodiscard]] GLPrimitive::Type GetPrimitivePattern() const
    {
        return primitive_pattern;
    }
    void SetPrimitivePattern(GLPrimitive::Type the_primitive_pattern)
    {
        primitive_pattern = the_primitive_pattern;
    }

    [[nodiscard]] GLsizei GetVertexCount() const
    {
        return num_vertices;
    }
    void SetVertexCount(int vertex_count)
    {
        num_vertices = vertex_count;
    }
};

/**
 * @brief Draws the elements of a GLVertexArray using an index buffer.
 * @param vertex_array The GLVertexArray containing the geometry to be drawn.
 * This function uses the index buffer associated with the GLVertexArray to render the geometry.
 * It uses the primitive pattern, index count, and index type specified in the GLVertexArray.
 */
void GLDrawIndexed(const GLVertexArray& vertex_array) noexcept;

/**
 * @brief Draws the vertices of a GLVertexArray without using an index buffer.
 * @param vertex_array The GLVertexArray containing the vertices to be drawn.
 * This function renders the vertices directly from the vertex buffer of the GLVertexArray.
 * It uses the primitive pattern, vertex count, and vertex type specified in the GLVertexArray.
 */
void GLDrawVertices(const GLVertexArray& vertex_array) noexcept;
