//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if (N < M) {
            return -1;
        }
        
        int beg = *max_element(A, A + N);
        int end = accumulate(A, A + N, 0);
        
        int res = -1, mid;
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            if (isValid(A, mid, N, M)) {
                res = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        
        return res;
    }
    
    bool isValid(int A[], int mid, int N, int M) {
        int student = 1, sum = 0;
        for (int i = 0; i < N; ++i) {
            sum = sum + A[i];
            if (sum > mid) {
                student++;
                sum = A[i];
            }
            
            if (student > M) {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends