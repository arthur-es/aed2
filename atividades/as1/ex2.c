#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

Node* insert(Node *root, int valueToInsert);

void printInOrderTree(Node *root);
int getLeafCount(Node *root);

int main () {
    Node *root = NULL;

    int i, count;
    int valuesToInsert[] = { 105,55,60,110,301,200,40 };
    int valuesToDelete[6];
    int sizeOfArray = sizeof(valuesToInsert) / sizeof(int);

    printf("Qtd. de valores para inserir na arvore: %d \n", sizeOfArray);

    for(i = 0; i < sizeOfArray; i++) {      
        printf("Inserindo valor: %d...\n", valuesToInsert[i]);  
        root = insert(root, valuesToInsert[i]);  
    }  

    printf("Valores inseridos na arvore: ");
    printInOrderTree(root);

    printf("\n\nQuantidade de nos-folha existentes na arvore: %d\n", getLeafCount(root));

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

void printInOrderTree(Node *root){
    if(root == NULL){
        return;
    }

    printInOrderTree(root->left);
    printf("%d ", root->value);
    printInOrderTree(root->right);
}

int getLeafCount(Node *root)
{
    if(root == NULL)    
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;        
    else
        return getLeafCount(root->left)+
            getLeafCount(root->right);
}