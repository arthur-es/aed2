#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} Node;

Node* insert(Node *root, int valueToInsert);

void printPosOrderTree(Node *root);
void printInOrderTree(Node *root);
void printPreOrderTree(Node *root);
int getTreeSize(Node *root);
int searchInTree(Node *root, int key);

int main () {
    int option, value;
    int treeSize = 0;
    int valueToSearch = 0;
    int valueFound = 0;

    Node *root = NULL;

    do{
        printf("\n\nMENU:\n[ 0 ] SAIR\n[ 1 ] INSERIR\n[ 2 ] IMPRIMIR ARVORE EM-ORDEM\n[ 3 ] IMPRIMIR ARVORE PRE-ORDEM\n[ 4 ] IMPRIMIR ARVORE POS-ORDEM\n[ 5 ] TAMANHO DA ARVORE\n[ 6 ] PROCURAR NA ARVORE\n\n");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\nSaindo...");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("ARVORE EM-ORDEM: ");
            printInOrderTree(root);
            break;
        case 3:
            printf("ARVORE PRE-ORDEM: ");
            printPreOrderTree(root);
            break;
        case 4:
            printf("ARVORE POS-ORDEM: ");
            printPosOrderTree(root);
            break;
        case 5:
            treeSize = getTreeSize(root);
            printf("TAMANHO DA ARVORE: %d\n", treeSize);
            break;
        case 6:
            printf("Qual valor voce quer procurar na arvore?: ");
            scanf("%d", &valueToSearch);
            printf("Procurando %d...\n", valueToSearch);
            printf("Resultado da busca: %d\n", searchInTree(root, valueToSearch));
            break;
        default:
            printf("\nOpcao invalida!...");
            break;
        }
    } while(option != 0);

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

int getTreeSize(Node *root){
    if(root == NULL){
        return 0;
    }

    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

int searchInTree(Node *root, int key){
    if(root == NULL){
        return -1;
    } else {
        if(root->value == key){
            return root->value;
        } else {
            if(key < root->value){
                return searchInTree(root->left, key);
            } else {
                return searchInTree(root->right, key);
            }
        }
    }
}
