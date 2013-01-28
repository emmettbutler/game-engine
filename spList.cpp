#include <stdio.h>
#include "spList.hpp"

spList::spList(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

void spList::PrettyPrint(){
    spListNode *node = this->head;
    printf("%s", node->ToString());
    while(node->GetNext() != NULL){
        printf(" -> ");
        node = node->GetNext();
        printf("%s", node->ToString());
    }
    printf("\n");
}

void spList::Append(glm::mat4 data){
    spListNode *inserting = new spListNode(data);
    inserting->SetPrev(this->tail);
    if(this->tail != NULL){
        this->tail->SetNext(inserting);
    } else {
        this->head = inserting;
    }
    inserting->SetPrev(this->tail);
    this->tail = inserting;
    this->count++;
}

void spList::Prepend(glm::mat4 data){
    spListNode *inserting = new spListNode(data);
    inserting->SetNext(this->head);
    if(this->head!= NULL){
        this->head->SetPrev(inserting);
    } else {
        this->tail = inserting;
    }
    inserting->SetNext(this->head);
    this->head = inserting;
    this->count++;
}

void spList::RemoveHead(){
    spListNode *next= this->head->GetNext();
    delete this->head;
    this->head = next;
    if(this->head != NULL){
        this->head->SetPrev(NULL);
    }
}

void spList::RemoveTail(){
    spListNode *prev = this->tail->GetPrev();
    delete this->tail;
    this->tail = prev;
    if(this->tail != NULL){
        this->tail->SetNext(NULL);
    }
}

spListNode *spList::GetHead(){
    return this->head;
}

spListNode *spList::GetTail(){
    return this->tail;
}

spListNode::spListNode(glm::mat4 data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

spListNode::spListNode(glm::mat4 data, spListNode *prev, spListNode *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

glm::mat4 spListNode::GetData(){
    return this->data;
}

void spListNode::SetData(glm::mat4 data){
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
    char *buffer = (char *)malloc(100 * sizeof(char));
    sprintf(buffer, "<spListNode object at %p>", this);
    return buffer;
}

