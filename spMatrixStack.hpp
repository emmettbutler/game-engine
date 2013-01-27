#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "spList.hpp"

class spMatrixStack{
    public:
        spMatrixStack();
        void Push(glm::mat4 transformation);
        glm::mat4 *Pop();
        void PrettyPrint();
    private:
        spList *transform_list;
};
