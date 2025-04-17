#define STB_IMAGE_IMPLEMENTATION
#include<graphics/texture.h>

namespace tx
{
    Texture::Texture(bool automaticTex)
    {
        if(automaticTex)
        {
            genTex();
        }
    }

    Texture::~Texture(){}

    void Texture::genTex(int size)
    {
        glGenTextures(size, &textures[nTexs]);
        nTexs++;
    }

    void Texture::texParami(GLenum target, GLenum pname, GLint param, GLenum texNumber)
    {
        glActiveTexture(texNumber);
        glBindTexture(GL_TEXTURE_2D, textures[nTexs]);
        glTexParameteri(target, pname, param);
        
    }

    void Texture::addTexImage2D(GLenum target, GLint level, GLint imageFormat, GLint border, GLint exportFormat, GLenum type)
    {
        glTexImage2D(target, level, imageFormat, Imgwidth, Imgheight, border, exportFormat, type, imgData);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(imgData);
    }

    void Texture::createImage(const char* dir)
    {
        imgData = stbi_load(dir, &Imgwidth, &Imgheight, &ImgNrChannels, 0);
    }
}