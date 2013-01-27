#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

class spMatrixStack{
    public:
        spMatrixStack();
        void Push(glm::mat4 transformation);
        void Pop();
    private:
        spList *transform_list;
};
