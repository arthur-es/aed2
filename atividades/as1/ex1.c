#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

Node* insert(Node *root, int valueToInsert);
Node* delete(Node *root, int key);

void printInOrderTree(Node *root);
int isEven(int value);

int main () {
    Node *root = NULL;

    int i;
    int valuesToInsert[] = { 105,55,60,110,301,200 };
    int sizeOfArray = sizeof(valuesToInsert) / sizeof(int);

    printf("Qtd. de valores para inserir na arvore: %d \n", sizeOfArray);

    for(i = 0; i < sizeOfArray; i++) {      
        printf("Inserindo valor: %d...\n", valuesToInsert[i]);  
        root = insert(root, valuesToInsert[i]);  
    }  

    printf("Valores inseridos na arvore: ");
    printInOrderTree(root);

    printf("\n\nDeletando todos os valores pares...\n");
    for(i = 0; i < sizeOfArray; i++) {      
        if(isEven(valuesToInsert[i])){
            printf("%d [PAR] -> DELETANDO...\n", valuesToInsert[i]);
            delete(root, valuesToInsert[i]);
        } else {
            printf("%d [IMPAR]\n", valuesToInsert[i]);
        }
    }  

    printf("\nArvore apos delecao de valores pares: ");
    printInOrderTree(root);

    return 0;
}


Node* insert(Node *root, int valueToInsert){
    if(root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->value = valueToInsert;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else {
        if(valueToInsert < root->value){
            root->left = insert(root->left, valueToInsert);
        } 
        if(valueToInsert > root->value){
            root->right = insert(root->right, valueToInsert);
        } 
        return root;
    }
}

Node* delete(Node *root, int key){
    if(root == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if(root->value == key){
            // Removes leaf nodes (nodes that has no children)
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            } else {
                // Removes nodes that has only 1 child
                if(root->left == NULL || root->right == NULL){
                    Node *temporatyNode;
                    if(root->left != NULL){
                        temporatyNode = root->left;
                    } else {
                        temporatyNode = root->right;
                    }
                    free(root);
                    return temporatyNode;
                } else {
                    Node *temporaryNode = root->left;
                    while(temporaryNode->right != NULL){
                        temporaryNode = temporaryNode->right;
                    }

                    root->value = temporaryNode->value;
                    temporaryNode->value = key;
                    root->left = delete(root->left, key);
                    return root;
                }
            }
        } else {
            if(key < root->value){
                root->left = delete(root->left, key);
            } else {
                root->right = delete(root->right, key);
            }
            return root;
        }

    }
}

void printInOrderTree(Node *root){
    if(root == NULL){
        return;
    }

    printInOrderTree(root->left);
    printf("%d ", root->value);
    printInOrderTree(root->right);
}

int isEven(int value){
    if(value % 2 == 0){
        return 1; 
    } else {
        return 0;
    }
}