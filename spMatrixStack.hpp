#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "spList.hpp"

class spMatrixStack{
    public:
        spMatrixStack();
        void Push(glm::mat4 transformation);
        glm::mat4 Pop();
        glm::mat4 GetModelMatrix();
        glm::mat4 CalculateTransform();
        void PrettyPrint();
    private:
        spList *transform_list;
};
