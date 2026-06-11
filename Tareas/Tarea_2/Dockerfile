# VS Code en navegador + utilidades (imagen mantenida con s6-overlay)
FROM ghcr.io/linuxserver/code-server:latest

# Paquetes para C++ y utilidades de desarrollo
USER root
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential g++ gdb cmake ninja-build make \
    clang clangd lldb \
    valgrind \
    git pkg-config \
    clang-format \
    && rm -rf /var/lib/apt/lists/*

# Carpeta de trabajo (la imagen usa /config como HOME)
WORKDIR /config/workspace
RUN mkdir -p /config/workspace
