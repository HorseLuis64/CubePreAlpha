#pragma once
#include<libs/graphics/glad.h>
#include<libs/graphics/stb_image.h>

namespace tx
{
    class Texture
    {
        public:
            Texture(bool automaticTex = true);
            ~Texture();

            void createImage(const char* dir);

            void genTex(int size = 1);
            void texParami(GLenum target, GLenum pname, GLint param, GLenum texNumber = GL_TEXTURE0 );
            void addTexImage2D(GLenum target, GLint level, GLint imageFormat, GLint border, GLint exportFormat, GLenum type);
        private:
            unsigned int nTexs = 0;
            unsigned int textures[10];
            int Imgwidth;
            int Imgheight; 
            int ImgNrChannels;
            unsigned char* imgData;

    };
}