#include "spSprite.hpp"
#include "spGame.hpp"

void spSprite::init(const char *texture){
    this->shaderID = LoadShaders( "shaders/spVanillaSprite.vs", "shaders/spVanillaSprite.fs" );

    int width, height;
    this->currentTexture = loadPngImage(texture, width, height);

    this->setupQuad(width, height);
    this->setShaderParams();
}

void spSprite::setShaderParams(){
    this->MVPID = glGetUniformLocation(this->shaderID, "MVP");
    this->vertexPosition_modelspaceID = glGetAttribLocation(this->shaderID, "vertexPosition_modelspace");
    this->vertexUVID = glGetAttribLocation(this->shaderID, "vertexUV");

    this->TextureID  = glGetUniformLocation(this->shaderID, "myTextureSampler");

    this->shrink_filter = GL_NEAREST;
    this->exp_filter = GL_NEAREST;
}

void spSprite::AddAnimationFrames(char **frames){
    int width, height;
    for(int i = 0; i < 3; i++){
        this->anims[i] = loadPngImage(frames[i], width, height);
    }
    this->animTimer = 0;
    this->frameNum = 2;
    this->frameCounter = 0;
    this->animRate = .8;
}

void spSprite::PlayAnimation(float elapsed){
    if(elapsed < 0.0f) return;
    this->animTimer += elapsed;
    if(this->animTimer < this->animRate){
        return;
    }
    this->animTimer = 0;

    if(this->frameCounter < this->frameNum){
        this->frameCounter++;
    } else {
        this->frameCounter = 0;
    }
    this->currentTexture = this->anims[this->frameCounter];
}

void spSprite::setupQuad(int width, int height){
    const GLfloat g_vertex_buffer_data[] = {
        -width,-height,0.0f,
         width,-height,0.0f,
        -width, height,0.0f,
         width,-height,0.0f,
        -width, height,0.0f,
         width, height,0.0f,
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
}

spSprite::spSprite(){
    this->init("textures/unitsprite.png");
}

spSprite::spSprite(float x, float y, const char *texture){
    this->init(texture);
    this->x = x;
    this->y = y;

    this->scale = spm::vec2(1.0f, 1.0f);

    this->anims = new GLuint[3];

    this->translation = spm::translation(spm::vec3(x, y, 0.0f));
    this->rotation = spm::rotation(0.0f);
    this->scale_mat = spm::scale(spm::vec3(this->scale.m[0], this->scale.m[1], 0.0f));

}

void spSprite::SetAngle(const float angle){
    this->rotation = spm::rotation(angle);
    this->angle = angle;
}

float spSprite::GetAngle(){
    return this->angle;
}

spm::vec2 spSprite::GetPosition(){
    return spm::vec2(this->x, this->y);
}

void spSprite::SetPosition(spm::vec2 pos){
    this->x = pos.m[0];
    this->y = pos.m[1];
    this->translation = spm::translation(spm::vec3(this->x, this->y, 0.0f));
}

void spSprite::SetTransform(spm::vec2 position, float angle){
    // TODO - add rotation
    this->translation = spm::translation(spm::vec3(position.m[0], position.m[1], 0.0f));
    this->rotation = spm::rotation(angle);
}

spm::mat4 spSprite::GetTransform(){
    spm::mat4 transform;
    transform = this->scale_mat * this->rotation * this->translation;
    return transform;
}

void spSprite::SetScale(spm::vec2 newScale){
    this->scale = newScale;
    this->scale_mat = spm::scale(spm::vec3(newScale.m[0], newScale.m[1], 0.0f));
}

spm::vec2 spSprite::GetScale(){
    return this->scale;
}

void spSprite::Draw(void *frame){
    glUseProgram(this->shaderID);

    spGame *myFrame = (spGame *)frame;
    spm::mat4 viewProjection = myFrame->calculateViewProjection();
    spm::mat4 trans = this->GetTransform();
    this->MVP = trans * viewProjection;
    glUniformMatrix4fv(this->MVPID, 1, GL_FALSE, &MVP.m[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->currentTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->shrink_filter);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->exp_filter);
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
