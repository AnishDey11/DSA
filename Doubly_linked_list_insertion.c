#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void traversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node* insert_at_begining(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    head -> prev = ptr;
    ptr -> prev = NULL;
    return ptr;
}

struct Node* insert_at_end(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node* p = head;
    while(p -> next != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    ptr -> prev = p;
    return head;
}

int main(){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* first = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 3;
    head -> prev = NULL;
    head -> next = first;

    first -> data = 18;
    first -> prev = head;
    first -> next = second;

    second -> data = 27;
    second -> prev = first;
    second -> next = third;

    third -> data = 38;
    third -> prev = second;
    third -> next = fourth;

    fourth -> data = 45;
    fourth -> prev = third;
    fourth -> next = NULL;

    traversal(head);
    // head = insert_at_begining(head, 1);
    // head = insert_at_end(head, 87);
    traversal(head);

    return 0;
}
