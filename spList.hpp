#include <stdlib.h>
using namespace std;

class spListNode{
    public:
        spListNode(void *data);
        spListNode(void *data, spListNode *prev, spListNode *next);
        void *GetData();
        void SetData(void *data);
        spListNode *GetNext();
        void SetNext(spListNode *next);
        spListNode *GetPrev();
        void SetPrev(spListNode *prev);
        char *ToString();
    private:
        void *data;
        spListNode *next, *prev;
};

class spList{
    public:
        spList();
        void Append(void *data);
        void Prepend(void *data);
        void RemoveHead();
        void RemoveTail();
        void PrettyPrint();
    private:
        spListNode *head, *tail;
        int count;
};

