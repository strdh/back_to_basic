#include <iostream>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<struct Node> left;
    std::unique_ptr<struct Node> right;
};

typedef struct Node Node;

std::unique_ptr<Node> create_node(int value) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode->value = value;

    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

void traverse_pre_order(std::unique_ptr<Node> &root) {
    if (root != nullptr) {
        std::cout<<root->value<<" ";
        traverse_pre_order(root->left);
        traverse_pre_order(root->right);
    }
}



int main() {
    std::unique_ptr<Node> tree1 = create_node(8);
    tree1->left = create_node(3);
    tree1->right = create_node(10);
    tree1->left->left = create_node(1);
    tree1->left->right = create_node(6);
    tree1->left->right->left = create_node(4);

    std::unique_ptr<Node> tree2 = create_node(8);
    tree2->left = create_node(3);
    tree2->right = create_node(10);
    tree2->left->left = create_node(1);
    tree2->left->right = create_node(6);
    tree2->left->right->left = create_node(2);

    std::cout<<"Tree 1: ";
    traverse_pre_order(tree1);
    std::cout<<"\n";
    // std::cout<<"Is bstree -> "<<is_bstree(tree1)<<"\n";

    std::cout<<"Tree 2: ";
    traverse_pre_order(tree2);
    std::cout<<"\n";
    // std::cout<<"Is bstree -> "<<is_bstree(tree2)<<"\n";

    return 0;
}