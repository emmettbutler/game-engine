#include "spMatrixStack.hpp"

spMatrixStack::spMatrixStack(){
    this->transform_list = new spList();
}

void spMatrixStack::Push(glm::mat4 transformation){
    this->transform_list->Append(&transformation);
}

glm::mat4 *spMatrixStack::Pop(){
    spListNode *popped = (spListNode *)this->transform_list->GetTail();
    this->transform_list->RemoveTail();
    return (glm::mat4 *)popped->GetData();
}

void spMatrixStack::PrettyPrint(){
    this->transform_list->PrettyPrint();
}

int main(int argc, char *argv[]){
    spMatrixStack *my_stack = new spMatrixStack();
    glm::mat4 a = glm::mat4(1.0);
    glm::mat4 b = glm::mat4(6.0);
    my_stack->Push(a);
    my_stack->PrettyPrint();
    my_stack->Push(b);
    my_stack->PrettyPrint();
    my_stack->Pop();
    my_stack->PrettyPrint();
}
