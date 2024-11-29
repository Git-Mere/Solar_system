/*!************************************************************************
\file Meshes.h
\author Team Namu(Seungheon Jeon, Sunghwan Lee, Junseop Nam, Dongjun Hyun, Seonghyun Lee)
\par Course: CS200/fall
\par Final project
\date 12-05-2023
**************************************************************************/

#pragma once
#include "Mesh.h"


class PlanetMesh1 : public Mesh {
public:
    int VertexCount(void) { return 14; }
    Point GetVertex(int i) { return vertices[i]; }
    Vector Dimensions(void) { return Vector(2, 2, 2); }
    Point Center(void) { return Point(0, 0, 0); }
    int FaceCount(void) { return 24; }
    Face GetFace(int i) { return faces[i]; }
    int EdgeCount(void) { return 36; }
    Edge GetEdge(int i) { return edges[i]; }
private:
    static Point vertices[14];
    static Face faces[24];
    static Edge edges[36];
};


class Regular_Dodecahedron_Mesh : public Mesh {
public:
    int VertexCount(void) { return 20; }
    Point GetVertex(int i) { return vertices[i]; }
    Vector Dimensions(void) { return Vector(2, 2, 2); }
    Point Center(void) { return Point(0, 0, 0); }
    int FaceCount(void) { return 36; }
    Face GetFace(int i) { return faces[i]; }
    int EdgeCount(void) { return 30; }
    Edge GetEdge(int i) { return edges[i]; }
private:
    static Point vertices[20];
    static Face faces[36];
    static Edge edges[30];
};


class Truncated_Icosahedron_Mesh : public Mesh {
public:
    int VertexCount(void) { return 60; }
    Point GetVertex(int i) { return vertices[i]; }
    Vector Dimensions(void) { return Vector(2, 2, 2); }
    Point Center(void) { return Point(0, 0, 0); }
    int FaceCount(void) { return 116; }
    Face GetFace(int i) { return faces[i]; }
    int EdgeCount(void) { return 90; }
    Edge GetEdge(int i) { return edges[i]; }
private:
    static Point vertices[60];
    static Face faces[116];
    static Edge edges[90];
};