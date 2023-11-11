#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
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
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node* insert_at_index(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i != index-1){
        p = p -> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct Node* insert_at_end(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p -> next != NULL){
        p = p -> next;
    }
    ptr -> data = data;
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

struct Node* insert_after_node(struct Node* head, struct Node* previous_node, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = previous_node -> next;
    previous_node -> next = ptr;
    return head;
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
    // head = insert_at_begining(head, 3);
    // head = insert_at_index(head, 18, 3);
    // head = insert_at_end(head, 57);
    // head = insert_after_node(head, second, 29);
    traversal(head);

    return 0;
}
