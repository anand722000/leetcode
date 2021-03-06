#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (root == NULL || root == p || root == q) {
        /* edge cases: if return NULL then no p or q node in this path */
        return root;
    }

    /* l is the LCA in the left branch but not root->left */
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    /* r is the LCA in the right branch but not root->right */
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l != NULL && r != NULL) {
        return root;
    } else {
        /* if not return root node, the return value is fixed */
        return l != NULL ? l : r;
    }
}

int main(int argc, char **argv)
{
    struct TreeNode root, node1, node2, node11, node12, node21, node22, node121, node122;
    root.val = 3;
    node1.val = 5;
    node2.val = 1;
    node11.val = 0;
    node12.val = 4;
    node21.val = 7;
    node22.val = 9;
    node121.val = 3;
    node122.val = 5;
    root.left = &node1;
    root.right = &node2;
    node1.left = &node11;
    node1.right = &node12;
    node2.left = &node21;
    node2.right = &node22;
    node11.left = NULL;
    node11.right = NULL;
    node12.left = &node121;
    node12.right = &node122;
    node21.left = NULL;
    node21.right = NULL;
    node22.left = NULL;
    node22.right = NULL;
    node121.left = NULL;
    node121.right = NULL;
    node122.left = NULL;
    node122.right = NULL;

    struct TreeNode *ancestor = lowestCommonAncestor(&root, &node11, &node22);
    printf("%d\n", ancestor->val);
    return 0;
}
