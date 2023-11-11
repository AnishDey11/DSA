#include <stdio.h>
#include <stdlib.h>

// Creating node
struct Node{
    int data;
    struct Node* next;
};

// Traversal
void traversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;

    head = (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = first;

    first -> data = 11;
    first -> next = second;

    second -> data = 23;
    second -> next = third;

    third -> data = 38;
    third -> next = NULL;

    traversal(head);

    return 0;
}
