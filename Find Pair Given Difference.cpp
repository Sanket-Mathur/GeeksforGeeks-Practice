//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    unordered_set<int> set;
    for (int i = 0; i < size; ++i) {
        if (set.find(arr[i] - n) != set.end() || set.find(arr[i] + n) != set.end()) {
            return true;
        }
        set.insert(arr[i]);
    }
    
    return false;
}