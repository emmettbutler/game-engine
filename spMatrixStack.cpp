#include "spMatrixStack.hpp"

spMatrixStack::spMatrixStack(){
    this->transform_list = new spList();
}

void spMatrixStack::Push(glm::mat4 transformation){
    this->transform_list->Append(transformation);
}

glm::mat4 spMatrixStack::Pop(){
    glm::mat4 popped = this->transform_list->GetTail()->GetData();
    this->transform_list->RemoveTail();
    return popped;
}

glm::mat4 spMatrixStack::CalculateTransform(){
    return this->transform_list->GetHead()->GetData();
}

void spMatrixStack::PrettyPrint(){
    this->transform_list->PrettyPrint();
}
