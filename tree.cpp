#include <iostream>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *createNode(int value) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->value = value;

    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}

void traversePreOrder(node *start) {
    if (start != NULL) {
        std::cout<<" "<<start->value;
        traversePreOrder(start->left);
        traversePreOrder(start->right);
    }
}

void traverseInOrder(node *start) {
    if (start != NULL) {
        traverseInOrder(start->left);
        std::cout << " " << start->value;
        traverseInOrder(start->right);
    }
}

void traversePostOrder(node *start) {
    if (start != NULL) {
        traversePostOrder(start->left);
        traversePostOrder(start->right);
        std::cout << " " << start->value;
    }
}

int sumTreeValue(node *start) {
    if (start == NULL) {
        return 0;
    }

    return (start->value + sumTreeValue(start->left) + sumTreeValue(start->right)); 
}

int treeHeight(node * start) {
    if (start == NULL) {
        return 0;
    }

    int left = treeHeight(start->left);
    int right = treeHeight(start->right);
    
    if (left >= right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

int main() {
    node *tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right->left = createNode(6);
    tree->right->right = createNode(7);

    std::cout<<"Sum value : ";
    std::cout<<sumTreeValue(tree)<<"\n";

    std::cout<<"Height of tree : ";
    std::cout<<treeHeight(tree)<<"\n";
    
    std::cout<<"Pre Order : ";
    traversePreOrder(tree);
    std::cout<<"\n";

    std::cout<<"In Order : ";
    traverseInOrder(tree);
    std::cout<<"\n";

    std::cout<<"Post Order : ";
    traversePostOrder(tree);
    std::cout<<"\n";

    return 0;
}