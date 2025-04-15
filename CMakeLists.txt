cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Cube_project VERSION 1.0)

# Política de GLM (opcional, pero está bien que la dejes)
cmake_policy(SET CMP0072 NEW)

# Buscar OpenGL
find_package(OpenGL REQUIRED)

# Buscar todos los archivos .cpp y .c dentro de src y include, incluyendo subcarpetas
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
file(GLOB_RECURSE C_SOURCES "include/*.c")

# Combinar todos los archivos fuente en una sola lista
set(SOURCES ${CPP_SOURCES} ${C_SOURCES})

# Crear el ejecutable
add_executable(Cube_project ${SOURCES})

# Incluir el directorio 'include' para que los headers se encuentren
target_include_directories(Cube_project PUBLIC include)

# Linkear librerías
target_link_libraries(Cube_project 
    glfw
    OpenGL::GL
)
