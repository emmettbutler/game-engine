#include "spSprite.hpp"
#include "spMatrixTransform.hpp"
using namespace spm;

void spSprite::init(){
    this->shaderID = LoadShaders( "shaders/spVanillaSprite.vs", "shaders/spVanillaSprite.fs" );

    const GLfloat g_vertex_buffer_data[] = {
        -1.0f,-1.0f,0.0f,
         1.0f,-1.0f,0.0f,
        -1.0f, 1.0f,0.0f,
         1.0f,-1.0f,0.0f,
        -1.0f, 1.0f,0.0f,
         1.0f, 1.0f,0.0f,
    };

    // render a texture on a square
    const GLfloat g_uv_buffer_data[] = {
        0.0f,0.0f,
        1.0f,0.0f,
        0.0f,1.0f,
        1.0f,0.0f,
        0.0f,1.0f,
        1.0f,1.0f,
    };

    glGenBuffers(1, &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &this->uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    this->MVPID = glGetUniformLocation(this->shaderID, "MVP");
    this->vertexPosition_modelspaceID = glGetAttribLocation(this->shaderID, "vertexPosition_modelspace");
    this->vertexUVID = glGetAttribLocation(this->shaderID, "vertexUV");

    this->Texture = loadTGA_glfw("textures/heart_sprite.tga");
    this->TextureID  = glGetUniformLocation(this->shaderID, "myTextureSampler");
}

spSprite::spSprite(){
    this->init();
}

spSprite::spSprite(float x, float y){
    this->init();
    this->x = x;
    this->y = y;

    this->translation = spm::translation(glm::vec3(x, y, 0.0f));
    this->rotation = glm::mat4(1.0f);
    this->scale = spm::scale(glm::vec3(1.0f, 1.0f, 0.0f));
}

void spSprite::SetTransform(float xTrans, float yTrans, float angle){
    // pass
    // create a translation matrix, scale matrix
    // store them in this->translation...
}

glm::mat4 spSprite::GetTransform(){
    return this->translation * this->rotation * this->scale;
}

void spSprite::Draw(glm::mat4 viewProjection){
    glUseProgram(this->shaderID);

    this->MVP = viewProjection * this->GetTransform();
    glUniformMatrix4fv(this->MVPID, 1, GL_FALSE, &MVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    glUniform1i(TextureID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glVertexAttribPointer(this->vertexPosition_modelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
    glVertexAttribPointer(this->vertexUVID, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 2*3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void spSprite::Dealloc(){
    glDeleteBuffers(1, &this->vertexbuffer);
    glDeleteBuffers(1, &this->uvbuffer);
    glDeleteProgram(this->shaderID);
    glDeleteTextures(1, &this->TextureID);
}
