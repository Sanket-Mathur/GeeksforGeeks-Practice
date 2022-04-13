// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        string result;
        
        int carry = 0;
        while (n > 0 && m > 0) {
            int sum = a[n - 1] + b[m - 1] + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
            
            --n;
            --m;
        }
        
        while (n > 0) {
            int sum = a[n - 1] + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
            
            --n;
        }
        while (m > 0) {
            int sum = b[m - 1] + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
            
            --m;
        }
        
        while (carry > 0) {
            result += to_string(carry % 10);
            carry /= 10;
        }
        
        int zeros = 0;
        for (int i = result.length() - 1; i >= 0 && result[i] == '0'; --i) {
            ++zeros;
        }
        
        return string(result.rbegin() + zeros, result.rend());
    }
};

// { Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}  // } Driver Code Ends