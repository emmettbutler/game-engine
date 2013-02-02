#include "spMatrixStack.hpp"

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
