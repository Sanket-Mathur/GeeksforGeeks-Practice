// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>

class Solution
{
    unordered_map<int, cpp_int> table;
    
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        if (n <= 1)
            return 1;
        if (table.find(n) != table.end())
            return table[n];
        
        cpp_int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += findCatalan(i - 1) * findCatalan(n - i);
        }
        
        table[n] = res;
        return res;
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends