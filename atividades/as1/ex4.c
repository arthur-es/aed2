#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

Node* insert(Node *root, int valueToInsert);
void printInOrderTree(Node *root);
int isBinarySearchTree(Node *root);

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

    printf("\n\nA arvore eh binaria? %d\n", isBinarySearchTree(root));

    return 0;
}

int isBinarySearchTree(Node *root)
{
  if (root == NULL)
    return 1;
     
  if (root->left != NULL && root->left->value > root->value)
    return 0;
     
  if (root->right != NULL && root->right->value < root->value)
    return 0;
   
  if (!isBinarySearchTree(root->left) || !isBinarySearchTree(root->right))
    return 0;
     
  return 1;
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






