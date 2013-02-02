#include <stdlib.h>
using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

class spListNode{
    public:
        spListNode(glm::mat4 data);
        spListNode(glm::mat4 data, spListNode *prev, spListNode *next);
        glm::mat4 GetData();
        void SetData(glm::mat4 data);
        spListNode *GetNext();
        void SetNext(spListNode *next);
        spListNode *GetPrev();
        void SetPrev(spListNode *prev);
        char *ToString();
    private:
        glm::mat4 data;
        spListNode *next, *prev;
};

class spList{
    public:
        spList();
        void Append(glm::mat4 data);
        void Prepend(glm::mat4 data);
        void RemoveHead();
        void RemoveTail();
        void PrettyPrint();
        spListNode *GetHead();
        spListNode *GetTail();
    private:
        spListNode *head, *tail;
        int count;
};

