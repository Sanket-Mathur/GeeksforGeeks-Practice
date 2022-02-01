// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++
class NodeDetails {
public:
    Node* node;
    int min;
    int max;
    
    NodeDetails(Node* node, int min, int max) {
        this->node = node;
        this->min = min;
        this->max = max;
    }
};

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    queue<NodeDetails*> q;
    
    Node* node = new Node(arr[0]);
    NodeDetails* x = new NodeDetails(node, INT_MIN, INT_MAX);
    q.push(x);
    
    for (int i = 1; i < n; ++i) {
        Node* node = new Node(arr[i]);
        NodeDetails* top = q.front();
        
        while (!(arr[i] < top->node->data && arr[i] > top->min && top->node->left == NULL) && 
        !(arr[i] > top->node->data && arr[i] < top->max && top->node->right == NULL)) {
            q.pop();
            top = q.front();
        }
        
        if (arr[i] < top->node->data) {
            top->node->left = node;
            NodeDetails* y = new NodeDetails(node, top->min, top->node->data);
            q.push(y);
        } else {
            top->node->right = node;
            NodeDetails* y = new NodeDetails(node, top->node->data, top->max);
            q.push(y);
        }
    }
    
    return x->node;
}
