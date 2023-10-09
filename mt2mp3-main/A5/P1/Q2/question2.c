#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode Node;
typedef struct stack Stack;
struct treenode;
struct stack;
int depth(Node *node);
Stack *makestack(Node *ptr);
Stack *push(Stack *stack, Node *ptr);
Stack *pop(Stack *stack);
int dfs(Node *node, char* name);

struct treenode{
    char *name;
    char *tea;
    Node *left;
    Node *right;
};

struct stack{
    Node *val;
    Stack *next;
};

Stack *makestack(Node *ptr){
    Stack *stack = (Stack*)(malloc(sizeof(Stack)));
    stack->val=ptr;
    stack->next=NULL;
    return stack;
}

Stack *push(Stack *stack, Node *ptr){
    Stack *new = (Stack*)(malloc(sizeof(Stack)));
    new->val=ptr;
    new->next=stack;
    return new;
}

Stack *pop(Stack *stack){
    Stack *top_stack = stack->next;
    free(stack);
    return top_stack;
}

int depth(Node *node){
    
    if(node==NULL){
        return 0;
    }
    else{
        int depth_right = depth(node->right);
        int depth_left = depth(node->left);

        if(depth_right>depth_left){
            return depth_right+1;
        }
        else{
            return depth_left +1;
        }
    }

}

int dfs(Node *node, char* name){
    Stack *search_stack = makestack(node);
    search_stack = push(search_stack, node);
    int search = 0;
    do{
        search+=1;
        if(search_stack->val->name==name){
            return search;
        }
        else{
            Node *temp_val = search_stack->val;
            search_stack = pop(search_stack);
            if(temp_val->right){
                search_stack = push(search_stack,temp_val->right);
            }
            if(temp_val->left){
                search_stack = push(search_stack,temp_val->left);
            }
        }
    }
    while(search_stack->val!=node);
    return -1;
}


/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh      Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 

int main() {
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
}