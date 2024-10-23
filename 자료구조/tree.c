#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;
typedef struct Tree{
    int level;
    int height;
    TreeNode* root;
}Tree;

TreeNode* create_node(element item){
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n1->data = item;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}
Tree* create_tree(void){
    Tree* t1 = (Tree*)malloc(sizeof(Tree));
    t1->root = NULL;
    t1->level = 0;
    t1->height = 0;
    return t1;
}
void inorder(TreeNode* temp){
    if (temp != NULL) {
        inorder(temp->left);
        printf("[%d] ", temp->data);
        inorder(temp->right);
    }
}
void t_preorder(TreeNode* temp){
    if (temp != NULL) {
        printf("[%d] ", temp->data);
        t_preorder(temp->left);
        t_preorder(temp->right);
    }
}
void t_postorder(TreeNode* temp){
    if (temp != NULL) {
        t_postorder(temp->left);
        t_postorder(temp->right);
        printf("[%d] ", temp->data);
    }
}
TreeNode* find_min(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
TreeNode* insert_node(TreeNode* node, int item){ //1. 탐색 2. 삽입
    if (node == NULL) {
        return create_node(item);
    }
    if (node->data < item) {
        node->left = insert_node(node->left, item);
    } else if (node->data > item) {
        node->right = insert_node(node->right, item);
    }
    return node;
}
TreeNode* delete_node(TreeNode* root, int item){ 
    if (root == NULL) return root;
    if (item < root->data) {
        root->left = delete_node(root->left, item);
    } else if (item > root->data) {
        root->right = delete_node(root->right, item);
    } else {
        //삭제할 노드가 단말 노드인 경우
        if (root->right == NULL && root->left == NULL){
            free(root);
        }
        //삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우
        else if (root->right == NULL){
                TreeNode* temp = root->left;
                free(root);
                return temp;
        }else if (root->left == NULL){
                TreeNode* temp = root->right;
                free(root);
                return temp;
        } 
        //삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우
        else{ 
            // 오른쪽 서브트리에서 가장 작은 노드(후임자)를 찾음
            TreeNode* temp = find_min(root->right);
            // 현재 노드의 데이터를 후임자의 데이터로 교체
            root->data = temp->data;
            // 후임자를 삭제
            root->right = delete_node(root->right, temp->data);
        }
        

    }
    return root;
    
    
}
int main (void)
{
    Tree* t = create_tree();
    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));

    n1->data = 1;
    n2->data = 4; n2->left = n1;
    n3->data = 16;
    n4->data = 25;
    n5->data = 20; n5->left = n3; n5->right = n4;
    n6->data = 15; n6->left = n2; n6->right = n5;
    
    t->root = n6;
    
    t->root = insert_node(t->root, 3);
    t->root = delete_node(t->root,25);
    t->root = delete_node(t->root,15);

    printf("중위 순회: ");
    inorder(t->root);
    printf("\n전위 순회: ");
    t_preorder(t->root);
    printf("\n후위 순회: ");
    t_postorder(t->root);
    printf("\n");

    free(n1); free(n2); free(n3); free(n4); free(n5); free(n6);
    
}
