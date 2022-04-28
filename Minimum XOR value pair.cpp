// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    int minxorpair(int N, int arr[]) {
        int a = arr[0], b = arr[1];
        int minXor = a ^ b;
        
        for (int i = 2; i < N; ++i) {
            if ((minXor ^ a ^ arr[i]) < minXor && (minXor ^ a ^ arr[i]) < (minXor ^ b ^ arr[i])) {
                minXor = minXor ^ a ^ arr[i];
                a = arr[i];
            } else if ((minXor ^ b ^ arr[i]) < minXor) {
                minXor = minXor ^ b ^ arr[i];
                b = arr[i];
            }
        }
        
        return minXor;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends