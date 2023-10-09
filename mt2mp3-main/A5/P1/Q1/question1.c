#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

struct node *element(struct node *dll, int i){
    if(i==0){
        return dll;
    }
    else{
        struct node* current_ptr=dll;

        for(int j=0;j<i;j++){
            if(current_ptr->next){
                current_ptr = current_ptr->next;
            }
            else{
                return NULL;
            }
        }
        return current_ptr;
    }
}

struct node *add(struct node *dll, int i, int value){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    struct node* current_node = (element(dll,i));
    new->value=value;

    if(i==0){
        new->next=dll;
        new->prev=NULL;
        dll->prev=new;
        
        return new;
    }
    else if(i>0 && current_node){
        struct node* previous_node = current_node->prev;

        previous_node->next=new;
        current_node->prev=new;
        new->next=current_node;
        new->prev=previous_node;
    }
    else{
        struct node* current_node=dll;
        while(current_node->next){
            current_node = current_node->next;
        }
        new->next=NULL;
        new->prev=current_node;
        current_node->next=new;
    }
    return dll;
}

struct node *delete(struct node *dll, int i){
    struct node *current_node = element(dll,i);
    if(current_node){
        if(i==0){
            struct node *next_node = current_node->next;
            free(dll);
            if(next_node){
                next_node->prev=NULL;
            }
            else{
                return NULL;
            }
            return next_node;
        }
        else{
            struct node *next_node = current_node->next;
            struct node *previous_node = current_node->prev;
            free(current_node);

            if(next_node){
                next_node->prev=previous_node;
                previous_node->next=next_node;
            }
            else{
                previous_node->next=NULL;
            }
            return dll;
        }
    }
    else{
        return dll;
    }
}

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 
