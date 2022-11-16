//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int A[], int n, int X)  
{
    unordered_set<int> uni;
    for (int i = n - 1; i > -1; --i) {
        if (uni.find(X - A[i]) != uni.end()) {
            return true;
        }
        
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                uni.insert(A[i] + A[j] + A[k]);
            }
        }
    }
    
    return false;
}