#include <iostream>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *create_node(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;

    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}

void traverse_pre_order(Node *root) {
    if (root != NULL) {
        std::cout<<" "<<root->value;
        traverse_pre_order(root->left);
        traverse_pre_order(root->right);
    }
}

void traverse_in_order(Node *root) {
    if (root != NULL) {
        traverse_in_order(root->left);
        std::cout<<" "<<root->value;
        traverse_in_order(root->right);
    }
}

void traverse_post_order(Node *root) {
    if (root != NULL) {
        traverse_post_order(root->left);
        traverse_post_order(root->right);
        std::cout<<" "<< root->value;
    }
}

int btree_sum_value(Node *root) {
    if (root == NULL) {
        return 0;
    }

    return (root->value + btree_sum_value(root->left) + btree_sum_value(root->right)); 
}

int btree_height(Node * root) {
    if (root == NULL) {
        return 0;
    }

    int left = btree_height(root->left);
    int right = btree_height(root->right);
    
    if (left >= right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

void print_leaf(Node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            std::cout<<root->value<<" ";
        }

        print_leaf(root->left);
        print_leaf(root->right);
    }
}

Node *find_lca(Node *root, Node *p, Node *q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    Node *left = find_lca(root->left, p, q);
    Node *right = find_lca(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return left != NULL ? left : right;
}

int main() {
    Node *tree = create_node(1);
    tree->left = create_node(2);
    tree->right = create_node(3);
    tree->left->left = create_node(4);
    tree->left->right = create_node(5);
    tree->right->left = create_node(6);
    tree->right->right = create_node(7);

    std::cout<<"Sum value : ";
    std::cout<<btree_sum_value(tree)<<"\n";

    std::cout<<"Height of tree : ";
    std::cout<<btree_height(tree)<<"\n";
    
    std::cout<<"Pre Order : ";
    traverse_pre_order(tree);
    std::cout<<"\n";

    std::cout<<"In Order : ";
    traverse_in_order(tree);
    std::cout<<"\n";

    std::cout<<"Post Order : ";
    traverse_post_order(tree);
    std::cout<<"\n";

    std::cout<<"Print Leaf : ";
    print_leaf(tree);
    std::cout<<"\n";

    std::cout<<"LCA : ";
    Node *lca = find_lca(tree, tree->left->left, tree->right->left);
    std::cout<<lca->value;

    return 0;
}