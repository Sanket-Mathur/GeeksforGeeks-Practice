// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node *Tree(int in[], int post[], int is, int ie, int &pi, int n) {
    if (is > ie)
        return NULL;
    
    Node *root = new Node(post[pi]);
    --pi;
    
    if (is == ie)
        return root;
    
    int index;
    for (int i = 0; i < n; ++i) {
        if (root->data == in[i])
            index = i;
    }
    
    root->right = Tree(in, post, index+1, ie, pi, n);
    root->left = Tree(in, post, is, index-1, pi, n);
    
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int pi = n - 1;
    int is = 0, ie = n - 1;
    return Tree(in, post, is, ie, pi, n);
}
