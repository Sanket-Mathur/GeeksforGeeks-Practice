// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

stack<int> minStack;

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        s.push(arr[i]);
        
        if (minStack.empty()) {
            minStack.push(arr[i]);
        } else {
            minStack.push(min(minStack.top(), arr[i]));
        }
    }
    
    return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    while (!s.empty()) {
        s.pop();
        cout << minStack.top() << " ";
        minStack.pop();
    }
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}

  // } Driver Code Ends