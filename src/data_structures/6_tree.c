#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "../utils/operation_codes.h"
#include "tree.h"


BinaryTree* btree_create (int value) {
    BinaryTree* node = malloc(sizeof(BinaryTree));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

BinaryTree* btree_insert (BinaryTree* btree, int value) {
    if (btree == NULL) return btree_create(value);

    if (value < btree->value) {
        btree->left = btree_insert(btree->left, value);

    } else if (value >= btree->value) {
        btree->right = btree_insert(btree->right, value);
    }

    return btree;
}

BinaryTree* btree_remove (BinaryTree* btree) {
    if (btree == NULL) return NULL;

    if (btree->left == NULL) {
        BinaryTree* new_root = btree->right;
        free(btree);
        return new_root;
    }

    if (btree->right == NULL) {
        BinaryTree* new_root = btree->left;
        free(btree);
        return new_root;
    }

    BinaryTree* smallest_right_parent = btree;
    BinaryTree* smallest_right = btree->right;

    while (smallest_right->left != NULL) {
        smallest_right_parent = smallest_right;
        smallest_right = smallest_right->left;
    }

    if (smallest_right_parent != btree) {
        smallest_right_parent->left = smallest_right->right;
        smallest_right->right = btree->right;
    }

    smallest_right->left = btree->left;

    free(btree);
    return smallest_right;
}


int btree_print (BinaryTree* root, int indent, char dir) {
    if (root == NULL) return 0;

    int left_indent = btree_print(root->left, indent + 1, 'L');

    printf("%d | %c: ", indent, dir);
    for (int i = 0; i < indent; i++) printf(" ");
    printf("%d\n", root->value);

    btree_print(root->right, indent + left_indent, 'R');

    return indent + left_indent + 1;
}

int main() {
    BinaryTree* btree = NULL;

    btree = btree_insert(btree, 50);
    printf("\nInitial Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 30);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 20);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 40);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 70);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 60);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    btree_insert(btree, 80);
    printf("\nAfter Insert:\n"); btree_print(btree, 0, '-');

    // BinaryTreeVisualization* btree_visualization = BinaryTreeVisualization_create(
    //     VisualizationLayer_create("", NULL),
    //     NULL
    // );

    // btree_prepare_visualization(btree, btree_visualization, 0, 1);

    // btree_structured_print(btree_visualization);

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');

    btree = btree_remove(btree);
    printf("\nAfter Remove:\n"); btree_print(btree, 0, '-');
}
