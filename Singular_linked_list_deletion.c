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

// Delete head
struct Node* delete_head(struct Node* head){
    struct Node* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// Delete a node at particular index
struct Node* delete_at_index(struct Node* head, int index){
    struct Node* p = head;
    int i = 0;
    while(i != index-1){
        p = p -> next;
        i++;
    }
    struct Node* q = p -> next;
    p -> next = q-> next;
    free(q);
    return head;
}

// Delete end node
struct Node* delete_end(struct Node* head){
    struct Node* p = head;
    struct Node* q = p -> next;
    while(q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    free(q);
    p -> next = NULL;
    return head;
}

// Delete a particular value
struct Node* delete_a_value(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = p -> next;
    while(q -> data != value && q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    if(q -> data == value){
        p -> next = q -> next;
        free(q);
    }
    else{
        printf("%d is not present in linked list\n", value);
    }
    return head;
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
    fourth -> next = NULL;

    traversal(head); // Before implementing deletion
    // uncomment any line to see the deletion
    // head = delete_head(head);
    // head = delete_at_index(head, 2);
    // head = delete_end(head);
    // head = delete_a_value(head, 38);
    traversal(head); // After implementing deletion

    return 0;
}
