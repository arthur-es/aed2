#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

typedef struct {
    Node *root;
} Tree;

void insert(Tree *tree, int valueToInsert);
void insertLeft(Node *nodeToInsert, int valueToInsert);
void insertRight(Node *nodeToInsert, int valueToInsert);

void printPosOrderTree(Node *root);
void printInOrderTree(Node *root);
void printPreOrderTree(Node *root);

int main () {
    int option, value;
    Tree tree;
    tree.root = NULL;

    do{
        printf("\n0 - SAIR\n1 - INSERIR\n2 - IMPRIMIR ARVORE EM-ORDEM\n3 - IMPRIMIR ARVORE PRE-ORDEM\n4 - IMPRIMIR ARVORE POS-ORDEM\n");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &value);
            insert(&tree, value);
            break;
        case 2:
            printf("ARVORE EM-ORDEM: ");
            printInOrderTree(tree.root);
            break;
        case 3:
            printf("ARVORE PRE-ORDEM: ");
            printPreOrderTree(tree.root);
            break;
        case 4:
            printf("ARVORE POS-ORDEM: ");
            printPosOrderTree(tree.root);
            break;
        default:
            printf("\nOpcao invalida!...");
            break;
        }
    } while(option != 0);

    return 0;
}

void insertLeft(Node *nodeToInsert, int valueToInsert){
    if(nodeToInsert->left == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->value = valueToInsert;
        newNode->left = NULL;
        newNode->right = NULL;
        nodeToInsert->left = newNode;
    } else {
        if(valueToInsert < nodeToInsert->left->value){
            insertLeft(nodeToInsert->left, valueToInsert);
        } else {
            insertRight(nodeToInsert->left, valueToInsert);
        }
    }
}

void insertRight(Node *nodeToInsert, int valueToInsert){
    if(nodeToInsert->right == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->value = valueToInsert;
        newNode->left = NULL;
        newNode->right = NULL;
        nodeToInsert->right = newNode;
    } else {
        if(valueToInsert < nodeToInsert->right->value){
            insertLeft(nodeToInsert->right, valueToInsert);
        } else {
            insertRight(nodeToInsert->right, valueToInsert);
        }
    }
}

void insert(Tree *tree, int valueToInsert){
    if(tree->root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->value = valueToInsert;
        newNode->left = NULL;
        newNode->right = NULL;
        tree->root = newNode;
    }
    else {
        if(valueToInsert < tree->root->value){
            insertLeft(tree->root, valueToInsert);
        } else {
            insertRight(tree->root, valueToInsert);
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

void printPreOrderTree(Node *root){
    if(root == NULL){
        return;
    }

    printf("%d ", root->value);
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}

void printPosOrderTree(Node *root){
    if(root == NULL){
        return;
    }

    printPosOrderTree(root->left);
    printPosOrderTree(root->right);
    printf("%d ", root->value);
}