#include<stdio.h>
#include<stdlib.h>
/////////////////////////////////////////////
/// Implement as many methods as you can ///
///////////////////////////////////////////

struct stack {
    int* data;
    size_t size;
    size_t capacity;
};

// Allocate memory for as many elements as is
// the value of the argument capacity.
// Initialize size to be 0 because your stack is empty.
void init(struct stack* s, size_t capacity);

// Free memory for the data array.
// Make size = 0 & capacity = 0.
void delete(struct stack* s);

// Returns 1 if stack is empty.
// Returns 0 if stack is not empty.
int is_empty(struct stack* s);

// Returns 1 if stack is full (size == capacity).
// Returns 1 if stack is not full.
int is_full(struct stack* s);

// Returns 0 if successful.
// Returns -1 if there are any errors.
// Use resize if the stack is full.
int push_back(struct stack* s, int element);

// Returns the top element if successful.
// Returns -1 if there are any errors.
int pop_back(struct stack* s);

// Resizes the data array if it is full.
// Returns -1 if there are errors with malloc
// Returns 0 if everything is O.K.
// Use is_full() function
// Look up how to use realloc.
void resize(struct stack* s);

// Driver code, DO NOT edit!
int main() {
    struct stack s;

    init(&s, 2);
    
    printf("%d\n", push_back(&s, 5)); //0
    printf("%d\n", push_back(&s, 10)); //0
    
    resize(&s);
    
    printf("%d\n", push_back(&s, 15)); //0
    
    printf("%d\n", pop_back(&s)); //15
    printf("%d\n", pop_back(&s)); //10
    
    printf("%d\n", is_empty(&s)); // 0
    printf("%d\n", is_full(&s)); // 0
    
    printf("%d\n", pop_back(&s)); //5
    printf("%d\n", is_empty(&s)); // 1

    delete(&s);
    return 0;
}