#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node* head){
    struct Node* p = head;
    do{
        printf("Element: %d\n", p -> data);
        p = p -> next;
    }while(p != head);
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = first;

    first -> data = 11;
    first -> next = second;

    second -> data = 23;
    second -> next = third;

    third -> data = 38;
    third -> next = fourth;

    fourth -> data = 45;
    fourth -> next = head;

    traversal(head);

    return 0;
}
