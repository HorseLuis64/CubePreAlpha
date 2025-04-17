#pragma once

#include <graphics/glad.h>
namespace bf
{
    class Buffer
    {
        public:
            Buffer(bool autoBuffers = true);
            ~Buffer();

            void genVAO();
            void genVBO();
            void genEBO();

            void addVAttribP(GLuint index, GLint nArgs, GLenum type, GLboolean normalized, GLsizei stride, const void* init);

            void addVBO(float vertices[], int size, GLenum usage);
            void addEBO(unsigned int indices[], int size, GLenum usage);
        private:
        //TODO
        //a dynamic array by the static array
        //contradictory ik
            const int nBuffers = 1;
            int nVaos = 0;
            unsigned int buffers[10];
            unsigned int vaos[10]; 
        //finish TODO

    };
}