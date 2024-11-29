/*!************************************************************************
\file star.h
\author Team Namu(Seungheon Jeon, Sunghwan Lee, Junseop Nam, Dongjun Hyun, Seonghyun Lee)
\par Course: CS200/fall
\par Final project
\date 12-05-2023
**************************************************************************/

#pragma once
#include <vector>
#include "Mesh.h"
#include "Affine.h"
#include "Render.h"

class star {
public:
    star() = default;
    star(Mesh& m, const Vector& position, float scale_size = 1);
    void draw(const Matrix& world_to_clip, Render& r);

private:
    Mesh* mesh_ptr;
    Affine to_world;
    Vector color;
    Vector position;
    float scale_size = 1;
    std::vector<Hcoord> temp_clip_verts;
};