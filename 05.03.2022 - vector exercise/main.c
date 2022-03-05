#include <stdio.h>
#include <stdlib.h>

// Stack - LIFO / FILO
// Vector - int* data, size_t size, size_t capacity

struct vector {
    int* data;
    size_t size;
    size_t capacity;
};

void init(struct vector* v, size_t capacity) {
    v->capacity = capacity;
    v->size = 0;
    v->data = (int*)malloc(sizeof(int) * capacity);
}

void delete(struct vector* v) {
    v->size = 0;
    v->capacity = 0;
    free(v->data);
}

void resize(struct vector* v) {
    // 1, 2, 3, 4  <--- 5 -> 1. Запазвате си елементите (темп място)
                            // 2. изтривате паммета за *data
                            // 3. заделяте наново памет за *data
                            // 4. слагате предишните елементи в ново заделената памет

    v->capacity *= 2;
    v->data = (int*) realloc(v->data, sizeof(int) * v->capacity);
}

int is_empty(struct vector* v) {
    // !0 --> NOT 0 --> 1
    if (!v->size) {
        printf("Size: %ld\n", v->size);
        return 1;
    }
    
    // Nachin 2
    return 0;
    
    // if (v->size == 0) {
    //     return 1;
    // }
    
    // return 0;
    
    // Nachin 3 s trinaren oprator
    //return v->size == 0 ? 1 : 0;
}

// 0 - if successful
// -1 - if error occurs
int push_back(struct vector* v, int element) {
    if (v->size == v->capacity) {\
        printf("Calling resize() function ...\n");
        resize(v);
    }
    
    v->data[v->size++] = element;
    return 0;
}


// returns the last element if successful
// return -1 if there are any errors

int remove_back(struct vector* v) {
    if(v->size == 0)  {
        printf("There are no elements in the vector!\n");
        return -1;
    }
    
    v->size--;
    return v->data[v->size];
}

int main() {
    struct vector v;

    init(&v, 2);

    printf("%ld\n", v.capacity);
    
    printf("%d\n", push_back(&v, 5)); //0
    printf("%d\n", push_back(&v, 10)); //0
    
    printf("%d\n", push_back(&v, 15)); //0
    
    printf("%d\n", remove_back(&v)); //15
    printf("%d\n", remove_back(&v)); //10
    printf("%d\n", remove_back(&v)); //5
    
    printf("%d\n", remove_back(&v)); //-1

    delete(&v);
    
    // Used to show how is_empty is working
    struct vector v1;
    v1.size = -1;
    printf("Result of is_empty(): %d\n", is_empty(&v1));
    v1.size = 0;
    printf("Result of is_empty(): %d\n", is_empty(&v1));
    
    // Diffrences between true and false using the ! (NOT) operator
    int a = 1, b = 0;
    
    printf("%d\n", !a);
    printf("%d\n", !b);

    return 0;
}

// NOT !
// NOT FALSE (0)   -> TRUE (1)
// NOT TRUE (1)   -> FALSE (0)

// OR ||
// 0 OR 0 -> 0 (FALSE)
// 0 OR 1 -> 1 (TRUE)
// 1 OR 0 -> 1 (TRUE)
// 1 OR 1 -> 1 (TRUE)

// AND &&
// 0 AND 0 -> 0 (FALSE)
// 0 AND 1 -> 0 (FALSE)
// 1 AND 0 -> 0 (FALSE)
// 1 AND 1 -> 1 (TRUE)

// XOR, NXOR, NAND