// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    if (K > num || K == 0) {
        return head;
    } else if (K > num / 2) {
        K = num - K + 1;
    } else if (K == num / 2) {
        Node *prev = NULL;
        while (head) {
            Node *next = head->next;
            head->next = prev;
            prev = head;
            
            if (next)
                head = next;
            else
                break;
        }
        return head;
    }
    
    Node *firstK = head;
    Node *lastK = NULL;
    Node *curr = head;
    
    int c = 1;
    while (curr && c < num - K) {
        if (c == K) {
            head = curr->next;
            curr->next = NULL;
            curr = head;
        } else {
            curr = curr->next;
        }
        
        ++c;
    }
    lastK = curr->next;
    curr->next = NULL;
    
    while (firstK) {
        Node *temp = firstK->next;
        firstK->next = curr->next;
        curr->next = firstK;
        firstK = temp;
    }
    
    while (lastK) {
        Node *temp = lastK->next;
        lastK->next = head;
        head = lastK;
        lastK = temp;
    }
    
    // while (head) {
    //     cout << head->data << " ";
    //     head = head->next;
    // }
    // cout << endl;
    
    return head;
}
