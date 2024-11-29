/*!************************************************************************
\file Meshes.cpp
\author Team Namu(Seungheon Jeon, Sunghwan Lee, Junseop Nam, Dongjun Hyun, Seonghyun Lee)
\par Course: CS200/fall
\par Final project
\date 12-05-2023
**************************************************************************/

#include "Meshes.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Mesh::Face PlanetMesh1::faces[24] = {
    Face(0, 1, 2), Face(0, 2, 3), Face(0, 3, 4), Face(0, 4, 1),
    Face(5, 1, 4), Face(5, 4, 6), Face(5, 6, 7), Face(5, 7, 1),
    Face(8, 7, 6), Face(8, 6, 10), Face(8, 10, 9), Face(8, 9, 7),
    Face(11, 3, 2), Face(11, 2, 9), Face(11, 9, 10), Face(11, 10, 3),
    Face(12, 4, 3), Face(12, 3, 10), Face(12, 10, 6), Face(12, 6, 4),
    Face(13, 2, 1), Face(13, 1, 7), Face(13, 7, 9), Face(13, 9, 2)
};

Point PlanetMesh1::vertices[14] = {
    Point(0, 0, 1.618f), Point(1, 1, 1), Point(1, -1, 1),
    Point(-1, -1, 1), Point(-1, 1, 1), Point(0, 1.618f, 0),
    Point(-1, 1, -1), Point(1, 1, -1), Point(0, 0, -1.618f),
    Point(1, -1, -1), Point(-1, -1, -1), Point(0, -1.618f, 0),
    Point(-1.618f, 0, 0), Point(1.618f, 0, 0)
};

Mesh::Edge PlanetMesh1::edges[36] = {
    Edge(0, 1), Edge(0, 2), Edge(0, 3), Edge(0, 4),
    Edge(1, 2), Edge(2, 3), Edge(3, 4), Edge(4, 1),
    Edge(5, 1), Edge(5, 4), Edge(5, 6), Edge(5, 7),
    Edge(1, 7), Edge(4, 6), Edge(6, 7),
    Edge(8, 6), Edge(8, 7), Edge(8, 9), Edge(8, 10),
    Edge(7, 9), Edge(9, 10), Edge(10, 6),
    Edge(11, 2), Edge(11, 3), Edge(11, 9), Edge(11, 10),
    Edge(2, 9), Edge(3, 10),
    Edge(12, 3), Edge(12, 4), Edge(12, 6), Edge(12, 10),
    Edge(13, 1), Edge(13, 2), Edge(13, 7), Edge(13, 9),
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mesh::Face Regular_Dodecahedron_Mesh::faces[36] = {
    Face(0, 16, 2), Face(0, 2, 14), Face(0, 14, 12),    // -> a q c o m
    Face(0, 8, 1), Face(0, 1, 17), Face(0, 17, 16),     // -> a b r q i
    Face(0, 12, 4), Face(0, 4, 10), Face(0, 10, 8),     //  -> a m e k i
    Face(14, 6, 18), Face(14, 18, 4), Face(14, 4, 12),  // -> o g s e m
    Face(1, 8, 10), Face(1, 10, 5), Face(1, 5, 13),     // -> b i k f n
    Face(17, 1, 13), Face(17, 13, 15), Face(17, 15, 3), // -> r b n p d
    Face(13, 5, 19), Face(13, 19, 7), Face(13, 7, 15),  // -> n f t h p
    Face(10, 4, 18), Face(10, 18, 19), Face(10, 19, 5), // -> k e s t f
    Face(7, 19, 18), Face(7, 18, 6), Face(7, 6, 11),    // -> h t s g l
    Face(3, 15, 7), Face(3, 7, 11), Face(3, 11, 9),     // -> d p h l j
    Face(16, 17, 3), Face(16, 3, 9), Face(16, 9, 2),    // -> q r d j c
    Face(2, 9, 11), Face(2, 11, 6), Face(2, 6, 14)  //  -> c j l g o
};

Point Regular_Dodecahedron_Mesh::vertices[20] = {
    Point(1, 1, 1), Point(-1, 1, 1), Point(1, -1, 1),
    Point(-1, -1, 1), Point(1, 1, -1), Point(-1, 1, -1),
    Point(1, -1, -1), Point(-1, -1, -1), Point(0, 1.618f, 0.618f),
    Point(0, -1.618f, 0.618f), Point(0, 1.618f, -0.618f), Point(0, -1.618f, -0.618f),
    Point(1.618f, 0.618f, 0), Point(-1.618f, 0.618f, 0), Point(1.618f, -0.618f, 0),
    Point(-1.618f, -0.618f, 0), Point(0.618f, 0, 1.618f), Point(-0.618f, 0, 1.618f),
    Point(0.618f, 0, -1.618f), Point(-0.618f, 0, -1.618f)
};


Mesh::Edge Regular_Dodecahedron_Mesh::edges[30] = {
    Edge(0, 8), Edge(8, 1), Edge(1, 17), Edge(17, 16), Edge(16, 0),
    Edge(17, 3), Edge(3, 9), Edge(9, 2), Edge(2, 16),
    Edge(1, 13), Edge(3, 15), Edge(13, 15),
    Edge(15, 7), Edge(7, 11), Edge(11, 9),
    Edge(11, 6), Edge(6, 14), Edge(14, 2), Edge(14, 12), Edge(12, 0),
    Edge(6, 18), Edge(18, 4), Edge(4, 12), Edge(13, 5), Edge(5, 10),
    Edge(8, 10), Edge(10, 4), Edge(5, 19), Edge(19, 7), Edge(19, 18)
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mesh::Face Truncated_Icosahedron_Mesh::faces[116] = {
    Face(0, 6, 7), Face(0, 7, 8), Face(0, 8, 9), Face(0, 9, 1),
    Face(0, 1, 5), Face(0, 5, 4), Face(0, 4, 3), Face(0, 3, 2),
    Face(6, 25, 26), Face(6, 26, 27), Face(6, 27, 28), Face(6, 28, 7),
    Face(24, 23, 43), Face(24, 43, 44), Face(24, 44, 26), Face(24, 26, 25),
    Face(2, 3, 21), Face(2, 21, 22), Face(2, 22, 23), Face(2, 23, 24),
    Face(5, 11, 17), Face(5, 17, 18), Face(5, 18, 19), Face(5, 19, 4),
    Face(10, 14, 15), Face(10, 15, 16), Face(10, 16, 17), Face(10, 17, 11),
    Face(9, 8, 12), Face(9, 12, 13), Face(9, 13, 14), Face(9, 14, 10),
    Face(28, 27, 46), Face(28, 46, 47), Face(28, 47, 30), Face(28, 30, 29),
    Face(12, 29, 30), Face(12, 30, 31), Face(12, 31, 32), Face(12, 32, 13),

    Face(15, 33, 34), Face(15, 34, 35), Face(15, 35, 36), Face(15, 36, 16),
    Face(19, 18, 37), Face(19, 37, 38), Face(19, 38, 39), Face(19, 39, 20),
    Face(21, 20, 39), Face(21, 39, 40), Face(21, 40, 41), Face(21, 41, 22),
    Face(43, 42, 59), Face(43, 59, 58), Face(43, 58, 45), Face(43, 45, 44),
    Face(46, 45, 58), Face(46, 58, 57), Face(46, 57, 48), Face(46, 48, 47),
    Face(32, 31, 49), Face(32, 49, 50), Face(32, 50, 34), Face(32, 34, 33),
    Face(37, 36, 35), Face(37, 35, 52), Face(37, 52, 53), Face(37, 53, 38),
    Face(53, 52, 51), Face(53, 51, 56), Face(53, 56, 55), Face(53, 55, 54),
    Face(41, 40, 54), Face(41, 54, 55), Face(41, 55, 59), Face(41, 59, 42),
    Face(49, 48, 57), Face(49, 57, 56), Face(49, 56, 51), Face(49, 51, 50),

    Face(1, 9, 10), Face(1, 10, 11), Face(1, 11, 5),
    Face(4, 19, 20), Face(4, 20, 3), Face(3, 20, 21),
    Face(0, 2, 24), Face(0, 24, 25), Face(0, 25, 6),
    Face(7, 28, 29), Face(7, 29, 8), Face(8, 29, 12),
    Face(13, 32, 33), Face(13, 33, 14), Face(14, 33, 15),
    Face(17, 16, 36), Face(17, 36, 37), Face(17, 37, 18),
    Face(23, 22, 41), Face(23, 41, 42), Face(23, 42, 43),
    Face(26, 44, 45), Face(26, 45, 46), Face(26, 46, 27),
    Face(30, 47, 48), Face(30, 48, 49), Face(30, 49, 31),
    Face(34, 50, 51), Face(34, 51, 52), Face(34, 52, 35),
    Face(39, 38, 53), Face(39, 53, 54), Face(39, 54, 40),
    Face(59, 55, 56), Face(59, 56, 57), Face(59, 57, 58)

};

Point Truncated_Icosahedron_Mesh::vertices[60] = {
    Point(0, 0.333f, 1.618f), Point(0, -0.333f, 1.618f), Point(0.539f, 0.667f, 1.412f),
    Point(1.079f, 0.333f, 1.206f), Point(1.079f, -0.333f, 1.206f), Point(0.539f, -0.667f, 1.412f),
    Point(-0.539f, 0.667f, 1.412f), Point(-1.079f, 0.333f, 1.206f), Point(-1.079f, -0.333f, 1.206f),
    Point(-0.539f, -0.667f, 1.412f), Point(-0.333f, -1.206f, 1.079f), Point(0.333f, -1.206f, 1.079f),
    Point(-1.412f, -0.539f, 0.667f), Point(-1.206f, -1.079f, 0.333f), Point(-0.667f, -1.412f, 0.539f),

    Point(-0.333f, -1.618f, 0),Point(0.333f, -1.618f, 0), Point(0.667f, -1.412f, 0.539f),
    Point(1.206f, -1.079f, 0.333f),Point(1.412f, -0.539f, 0.667f), Point(1.618f, 0, 0.333f),
    Point(1.412f, 0.539f, 0.667f),Point(1.206f, 1.079f, 0.333f), Point(0.667f, 1.412f, 0.539f),
    Point(0.333f, 1.206f, 1.079f),Point(-0.333f, 1.206f, 1.079f), Point(-0.667f, 1.412f, 0.539f),
    Point(-1.206f, 1.079f, 0.333f),Point(-1.412f, 0.539f, 0.667f), Point(-1.618f, 0, 0.333f),

    Point(-1.618f, 0, -0.333f),Point(-1.412f, -0.539f, -0.667f), Point(-1.206f, -1.079f, -0.333f),
    Point(-0.667f, -1.412f, -0.539f),Point(-0.333f, -1.206f, -1.079f), Point(0.333f, -1.206f, -1.079f),
    Point(0.667f, -1.412f, -0.539f),Point(1.206f, -1.079f, -0.333f), Point(1.412f, -0.539f, -0.667f),
    Point(1.618f, 0, -0.333f),Point(1.412f, 0.539f, -0.667f), Point(1.206f, 1.079f, -0.333f),
    Point(0.667f, 1.412f, -0.539f),Point(0.333f, 1.618f, 0), Point(-0.333f, 1.618f, 0),

    Point(-0.667f, 1.412f, -0.539f),Point(-1.206f, 1.079f, -0.333f), Point(-1.412f, 0.539f, -0.667f),
    Point(-1.079f, 0.333f, -1.206f),Point(-1.079f, -0.333f, -1.206f), Point(-0.539f, -0.667f, -1.412f),
    Point(0, -0.333f, -1.618f),Point(0.539f, -0.667f, -1.412f), Point(1.079f, -0.333f, -1.206f),
    Point(1.079f, 0.333f, -1.206f),Point(0.539f, 0.667f, -1.412f), Point(0, 0.333f, -1.618f),
    Point(-0.539f, 0.667f, -1.412f),Point(-0.333f, 1.206f, -1.079f), Point(0.333f, 1.206f, -1.079f)
};

Mesh::Edge Truncated_Icosahedron_Mesh::edges[90] = {
    Edge(0, 1), Edge(1, 5), Edge(0, 2), Edge(2, 3), Edge(3, 4), Edge(4, 5),
    Edge(0, 6), Edge(6, 7), Edge(7, 8), Edge(8, 9), Edge(1, 9), Edge(9, 10),
    Edge(10, 11), Edge(5, 11),
    Edge(11, 17), Edge(17, 18), Edge(18, 19), Edge(4, 19), Edge(19, 20), Edge(3, 21),
    Edge(20, 21), Edge(2, 24), Edge(21, 22), Edge(22, 23), Edge(23, 24),
    Edge(24, 25), Edge(6, 25), Edge(25, 26), Edge(26, 27), Edge(27, 28), Edge(7, 28),
    Edge(28, 29), Edge(29, 12), Edge(8, 12), Edge(12, 13), Edge(13, 14), Edge(10, 14),
    Edge(14, 15), Edge(15, 16), Edge(16, 17),
    Edge(29, 30), Edge(30, 31), Edge(31, 32), Edge(13, 32), Edge(32, 33), Edge(15, 33),
    Edge(33, 34), Edge(34, 35), Edge(35, 36), Edge(16, 36), Edge(36, 37), Edge(18,37),
    Edge(37, 38), Edge(38, 39), Edge(20, 39), Edge(39, 40), Edge(40, 41), Edge(22, 41),
    Edge(41, 42), Edge(42, 43), Edge(23, 43), Edge(43, 44), Edge(26, 44), Edge(44, 45),
    Edge(45, 46), Edge(27, 46), Edge(46, 47), Edge(30, 47), Edge(47, 48), Edge(48, 49),
    Edge(31, 49), Edge(49, 50), Edge(34, 50), Edge(50, 51), Edge(51, 52), Edge(52, 53),
    Edge(35, 52), Edge(38, 53), Edge(53, 54), Edge(51, 56), Edge(55, 56), Edge(54, 55),
    Edge(40, 54), Edge(55, 59), Edge(42, 59), Edge(58, 59), Edge(45, 58), Edge(57, 58),
    Edge(48, 57), Edge(56, 57)
};
