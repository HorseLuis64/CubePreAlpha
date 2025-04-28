#pragma once

#include<iostream>

namespace msh
{
    class Cube
    {
        public:
            // Vertex positions and texture coordinates for a cube (8 unique vertices)
            float vertices[120] = {
                // Posición           // UV
                // Cara frontal
                -0.5f, -0.5f,  0.5f,   0.0f, 0.0f, // abajo izquierda
                 0.5f, -0.5f,  0.5f,   1.0f, 0.0f, // abajo derecha
                 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, // arriba derecha
                -0.5f,  0.5f,  0.5f,   0.0f, 1.0f, // arriba izquierda
            
                // Cara trasera
                 0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
                 0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
            
                // Cara izquierda
                -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
            
                // Cara derecha
                 0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
                 0.5f, -0.5f, -0.5f,   1.0f, 0.0f,
                 0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
                 0.5f,  0.5f,  0.5f,   0.0f, 1.0f,
            
                // Cara superior
                -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,
                 0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
                 0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
            
                // Cara inferior
                -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
                 0.5f, -0.5f, -0.5f,   1.0f, 0.0f,
                 0.5f, -0.5f,  0.5f,   1.0f, 1.0f,
                -0.5f, -0.5f,  0.5f,   0.0f, 1.0f
            };
            

            // Indices for drawing the cube using triangles
            unsigned int indices[36] = {
                // Back face
                0, 1, 2,   2, 3, 0,       // Frente
                4, 5, 6,   6, 7, 4,       // Atrás
                8, 9,10,  10,11, 8,       // Izquierda
               12,13,14,  14,15,12,       // Derecha
               16,17,18,  18,19,16,       // Arriba
               20,21,22,  22,23,20  
            };
    };

    class Sphere
    {
        
    };

    class Pyramid
    {
        public:
            // Vertex positions for a pyramid (5 unique vertices)
            float vertices[25] = {
    // Base (vértices y UVs)
            -1.0f, 0.0f, -1.0f,  0.0f, 0.0f, // Vértice 0
            1.0f, 0.0f, -1.0f,  1.0f, 0.0f, // Vértice 1
            1.0f, 0.0f,  1.0f,  1.0f, 1.0f, // Vértice 2
            -1.0f, 0.0f,  1.0f,  0.0f, 1.0f, // Vértice 3
            // Pico (vértice y UV)
            0.0f, 3.0f,  0.0f,  0.5f, 0.5f  // Vértice 4 (pico)
            };

            // Indices for drawing the pyramid using triangles
            unsigned int indices[18] = {
                // Base face
                0, 1, 4, // Cara 1
                1, 2, 4, // Cara 2
                2, 3, 4, // Cara 3
                3, 0, 4, // Cara 4
            
                // Base cuadrada
                0, 1, 2, // Cara de la base 1
                0, 2, 3  // Cara de la base 2
            };
    };
}