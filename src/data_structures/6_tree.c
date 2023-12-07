#ifndef MAIN
#define MAIN
#define LOCAL_MAIN
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../utils/error_codes.h"
#include "../utils/operation_codes.h"
#include "tree.h"
#include "linked_list_headless_generic.m"
#include "./4_queue.c"

DECLARE_HEADLESS_TYPE(HeadlessLinkedQueue, Queue*);
IMPLEMENT_HEADLESS_FUNCTIONS(HeadlessLinkedQueue, Queue*);


BinaryTree* btree_create (int value) {
    BinaryTree* node = malloc(sizeof(BinaryTree));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

BinaryTree* btree_insert (BinaryTree* root, int value) {
    if (root == NULL) return btree_create(value);

    if (value < root->value) {
        root->left = btree_insert(root->left, value);

    } else if (value > root->value) {
        root->right = btree_insert(root->right, value);
    }

    return root;
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

#ifdef LOCAL_MAIN

int main() {

    HeadlessLinkedQueue* output = HeadlessLinkedQueue_create(queue_create(), NULL);

    BinaryTree* root = NULL;

    root = btree_insert(root, 50);
    btree_insert(root, 30);
    btree_insert(root, 20);
    btree_insert(root, 40);
    btree_insert(root, 70);
    btree_insert(root, 60);
    btree_insert(root, 80);

    btree_print(root, 0, '-');
}

#endif
