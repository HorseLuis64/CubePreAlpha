#include<graphics/buffer.h>

namespace bf
{
    Buffer::Buffer(bool autoBuffers)
    {
        if(autoBuffers)
        {
            genVAO();
            genVBO();
            genEBO();
        }
    }

    Buffer::~Buffer(){} 

    void Buffer::genVAO()
    {
        glGenVertexArrays(1, &vaos[nVaos]);
        glBindVertexArray(vaos[nVaos]);
        
    }
    void Buffer::addVAttribP(GLuint index, GLint nArgs, GLenum type, GLboolean normalized, GLsizei stride, const void* init)
    {
        glVertexAttribPointer(index, nArgs, type, normalized, stride, init);
        glEnableVertexAttribArray(index);
    }

    void Buffer::genVBO()
    {
        glGenBuffers(1, &buffers[0]);
        glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
        nVaos++;
    }
    void Buffer::addVBO(float vertices[], int size, GLenum usage)
    {
        glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
    }

    void Buffer::genEBO()
    {
        glGenBuffers(1, &buffers[1]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    }
    void Buffer::addEBO(unsigned int indices[],int size, GLenum usage)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices,  usage);
    }


}