# Solar System

A solar system rendered with a hand-rolled graphics engine built on top of OpenGL.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue) ![GLSL](https://img.shields.io/badge/GLSL-shader-green)

## Features

- Planet and star rendering driven by a custom lightweight graphics engine written from scratch
- Full transformation pipeline — affine, projection, and clipping math implemented without external math libraries
- Free-roaming 3D camera controlled with `W` / `S` keys and mouse look
- Per-vertex lighting and color computed in GLSL vertex and fragment shaders
- Varied planet geometry including a Snub Dodecahedron mesh

## Demo

![gif](https://piskel-imgstore-b.appspot.com/img/4b3e3f5e-ec05-11ef-933a-b3fea4fe7937.gif)

![banner](banner.png)

## Built With

- **C++** — primary implementation language for all engine subsystems (camera, mesh, renderer)
- **GLSL** — vertex and fragment shaders executed directly on the GPU
- **OpenGL / GLEW** — cross-platform graphics API with extension function loading
- **SDL2** — window creation, event loop, and OpenGL context management
- **ImGui** — runtime debug UI overlay
- **stb_image** — texture image loading

## Getting Started

### Prerequisites

- Windows
- Visual Studio 2019 or later (MSVC)
- GPU driver with OpenGL support

> SDL2 and GLEW DLLs and library files are already included under `finalCS200/external/`.

### Installation

```bat
git clone https://github.com/Git-Mere/Solar_system.git
cd Solar_system
```

### Build & Run

1. Open `finalCS200/opengl-dev.sln` in Visual Studio
2. Set the solution configuration to **Release** or **Debug**
3. Set `HW` as the startup project, then press **F5** to build and run

### Controls

| Input | Action |
|-------|--------|
| `W` | Move forward |
| `S` | Move backward |
| Mouse | Rotate view |

## What I Learned

**Implementing affine and projection matrices without a math library**

Most OpenGL tutorials assume a library like glm. Here I had to write `Affine.cpp`, `Projection.cpp`, and `Clip.cpp` by hand. Applying matrix multiplication in the wrong order produced either a blank screen or a flipped scene, so I verified each stage — model → world → camera → clip space — by computing expected NDC coordinates manually. Working through each failure made the full transformation pipeline concrete rather than a black box.

**Designing RAII wrappers for OpenGL buffer objects**

Binding buffers directly on each draw call caused state collisions between objects. I wrapped `GLVertexArray`, `GLVertexBuffer`, and `GLIndexBuffer` in RAII classes and registered vertex attribute layouts once at construction time on the VAO. This eliminated an entire class of state-management bugs and made draw call code straightforward to reason about.

**Hierarchical transforms for orbital mechanics**

Planets orbit the sun; moons orbit their parent planet. I solved this by accumulating the parent's transform matrix into each child before rendering. Separating solar-body logic into `planet.cpp` and `star.cpp` kept the hierarchy explicit and prevented transform leakage between objects at different levels of the tree.

## License

No license file is included in this repository. Third-party libraries (SDL2, GLEW, ImGui, stb) are distributed under their respective licenses found in `finalCS200/external/copyright/`.