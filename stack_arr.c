#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int is_empty(struct stack* ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct stack* ptr){
    if(ptr -> top == ptr -> size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int data){
    if(is_full(ptr)){
        printf("Stack Overflow. %d can't be inserted in stack.\n", data);
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = data; 
    }
}

int pop(struct stack* ptr){
    if(is_empty(ptr)){
        printf("Stack Underflow.\n");
        return -1;
    }
    else{
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        return val;
    }
}

void _pop(struct stack* ptr){
    if(is_empty(ptr)){
        printf("Stack Underflow.\n");
    }
    else{
        int val = ptr -> arr[ptr -> top];
        ptr -> top--;
        printf("Poped %d from stack.\n", val);
    }
}

int main(){
    struct stack* sp = (struct stack*) malloc(sizeof(struct stack));
    sp -> size = 50;
    sp -> top = -1;
    sp -> arr = (int*) malloc(sp -> size*sizeof(int));
    
    // push(sp, 56);
    // for(int i = 0; i < 50; i++){
    //     push(sp, 56);
    // }

    push(sp, 1);
    push(sp, 4);
    push(sp, 3);
    push(sp, 6);
    push(sp, 7);
    push(sp, 145);
    push(sp, 19);
    push(sp, 80);
    push(sp, 14);
    push(sp, 9);
    push(sp, 79);

    // printf("Poped %d from stack.\n", pop(sp));
    _pop(sp);

    printf("Full: %d\n", is_full(sp));
    printf("Empty: %d\n", is_empty(sp));
    
    return 0;
}
