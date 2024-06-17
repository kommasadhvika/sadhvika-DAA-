#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int val) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}
int existPathUtil(struct Node*root,int arr[],int n,int index) {
    if (root==NULL||index==n) {
        return 0;
    }
    if (root->left==NULL&&root->right==NULL) {
        if (root->val==arr[index]&&index==n-1) {
            return 1;
        }
        return 0;
    }
    return (index<n&&root->val==arr[index] &&
            (existPathUtil(root->left,arr,n,index+1) ||
             existPathUtil(root->right,arr,n,index+1)));
}
int existPath(struct Node*root,int arr[],int n) {
    if (root==NULL) {
        return (n==0);
    }

    return existPathUtil(root,arr,n,0);
}
int main() {
    int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root=createNode(5);
    root->left=createNode(3);
    root->right=createNode(8);
    root->left->left=createNode(2);
    root->left->right=createNode(4);
    root->left->left->left=createNode(1);
    root->right->left=createNode(6);
    root->right->left->right=createNode(7);

    if (existPath(root, arr, n)) {
        printf("Path Exists\n");
    } else {
        printf("Path does not Exist\n");
    }
    return 0;
}
