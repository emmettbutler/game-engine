#include "spSprite.hpp"

spSprite::spSprite(float x, float y){
    this->x = x;
    this->y = y;
    this->transformStack = new spMatrixStack();
    glm::mat4 Model = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 1.0f, 0.0f));
    Model = glm::rotate(glm::mat4(1.0f), 80.0f, vec3(0.0f, 0.0f, 1.0f));
    this->transformStack->Push(Model);
}

glm::mat4 spSprite::GetTransform(){
    return this->transformStack->CalculateTransform();
}

void spSprite::Draw(){

}
