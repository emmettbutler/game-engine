#include <stdio.h>
#include "spList.hpp"

spList::spList(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

void spList::PrettyPrint(){
    spListNode *node = this->head;
    while(node != NULL){
        printf("%s", node->ToString());
        if(node->GetNext() != NULL){
            printf(" -> ");
        }
        node = node->GetNext();
    }
    printf("\n");
}

void spList::Append(void *data){
    spListNode *inserting = new spListNode(data);
    inserting->SetPrev(this->tail);
    if(this->tail != NULL){
        this->tail->SetNext(inserting);
    } else {
        this->head = inserting;
    }
    this->tail = inserting;
    this->count++;
}

void spList::Prepend(void *data){
    spListNode *inserting = new spListNode(data);
    inserting->SetNext(this->head);
    if(this->head!= NULL){
        this->head->SetPrev(inserting);
    } else {
        this->tail = inserting;
    }
    this->head = inserting;
    this->count++;
}

void spList::RemoveHead(){
    delete this->head;
    this->head = this->head->GetNext();
}

void spList::RemoveTail(){
    delete this->tail;
    this->tail = this->tail->GetPrev();
}

spListNode::spListNode(void *data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

spListNode::spListNode(void *data, spListNode *prev, spListNode *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

void *spListNode::GetData(){
    return this->data;
}

void spListNode::SetData(void *data){
    this->data = data;
}

spListNode *spListNode::GetNext(){
    return this->next;
}

void spListNode::SetNext(spListNode* next){
    this->next = next;
}

spListNode *spListNode::GetPrev(){
    return this->prev;
}

void spListNode::SetPrev(spListNode* prev){
    this->prev = prev;
}

char *spListNode::ToString(){
    return (char *)this->data;
}

int main(int argc, char *argv[]){
    spList *myList = new spList();
    int a = 1, b = 2, c = 69;
    printf("Testing linked list\n");
    myList->Append(&a);
    myList->PrettyPrint();
    myList->Append(&b);
    myList->PrettyPrint();
    myList->Prepend(&c);
    myList->PrettyPrint();
}
