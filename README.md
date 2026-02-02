![Clover](/Resources/Branding/Clover-Logo.png? "Clover")

## Clover Engine

> **Early Development Notice**  
> Clover is currently in **early development** and is **not production-ready**. This means:
> - Core systems are still being designed and implemented.
> - APIs, architecture, and project structure are **subject to change** at any time.
> - Features may be incomplete, unstable, or removed without warning.
> - Documentation may be outdated or missing.
>
> Use with caution — this project is intended for experimentation, learning, and contribution, not for shipping games at this stage.

## Getting Started
Clone this repository:
``` bash
git clone --recursive https://github.com/viskasssssss/Clover
```
Run __GenerateProjects.bat__ to generate Visual Studio Solution

## About
Clover Engine is a modern, data-oriented game engine focused on performance, flexibility, and developer experience. Inspired by the design principles of high-performance engines, Clover aims to provide a clean, modular, and extensible foundation for building 2D and 3D games.

While heavily inspired by [TheCherno's Hazel Engine](https://github.com/TheCherno/Hazel), Clover diverges with its own goals — including improved ECS integration, better resource management, and a stronger focus on editor usability and tooling.

### Current Status

As of now, Clover supports:
- 2D rendering with OpenGL backend
- Basic windowing and input handling

The core infrastructure is under active refactoring to support upcoming features such as full 3D rendering, multi-API backends, and an integrated editor.

### Current Goals (Subject to Change)
- Rendering backend abstraction (Vulkan/DX11 in progress)
- Implement 3D rendering pipeline (mesh loading, transforms, cameras)
- In-editor scripting and scene management 
- Runtime gameplay logic support

### Want to Contribute?
We welcome contributions! However, please keep in mind that since the engine is in early stages, large architectural changes may be made. It's best to open an issue or discussion first to align with the current vision.

---