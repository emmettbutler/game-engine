#include <stdio.h>
#include "spList.hpp"

int main(int argc, char *argv[]){
    spList *myList = new spList();
    int a = 1, b = 2, c = 69;
    printf("Testing linked list\n");
    printf("Append an item\n");
    myList->Append(&a);
    myList->PrettyPrint();
    printf("Append an item\n");
    myList->Append(&b);
    myList->PrettyPrint();
    printf("Prepend an item\n");
    myList->Prepend(&c);
    myList->PrettyPrint();
    printf("Check tail\n");
    printf("%p\n", myList->GetTail()->GetData());
    printf("Remove tail\n");
    myList->RemoveTail();
    myList->PrettyPrint();
    printf("Remove head\n");
    myList->RemoveHead();
    myList->PrettyPrint();
}
