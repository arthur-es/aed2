#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

Node* insert(Node *root, int valueToInsert);
int findMax(Node* root);
void printInOrderTree(Node *root);

int main () {
    Node *root = NULL;

    int i;
    int valuesToInsert[] = { 105,55,60,110,301,200,40 };
    int sizeOfArray = sizeof(valuesToInsert) / sizeof(int);

    printf("Qtd. de valores para inserir na arvore: %d \n", sizeOfArray);

    for(i = 0; i < sizeOfArray; i++) {      
        printf("Inserindo valor: %d...\n", valuesToInsert[i]);  
        root = insert(root, valuesToInsert[i]);  
    }  

    printf("Valores inseridos na arvore: ");
    printInOrderTree(root);

    printf("\n\nMaior valor encontrado na arvore: %d\n", findMax(root));

    return 0;
}

int findMax(Node* root)
{
    if (root == NULL){
        return -999999999; // set lowest possible value
    }
 
    int res = root->value;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
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






