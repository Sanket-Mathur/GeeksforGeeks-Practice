// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;
        
        for (int i = 2; i < sqrt(n) + 1; ++i) {
            if (primes[i]) {
                for (int j = i * i; j < n + 1; j += i) {
                    primes[j] = false;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 2; i < n + 1; ++i) {
            if (primes[i] && primes[i - 2]) {
                ++cnt;
            }
        }
        
        return cnt;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends