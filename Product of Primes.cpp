// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long primeProduct(long long L, long long R){
        long long result = 1;
        for (long long i = L; i <= R; ++i) {
            if (isPrime(i)) {
                result = (result * i) % 1000000007;
            }
        }
        
        return result;
    }
    
    bool isPrime(long long i) {
        for (int j = 2; j*j <= i; ++j) {
            if (i % j == 0) {
                return false;
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends