// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
	    if (word1 == word2) {
	        return 0;
	    }
	    
	    bool counting = false;
	    int cnt = 0, minCnt = INT_MAX;
	    string first;
	    for (string word : s) {
	        if (word == word1 || word == word2) {
	            if (counting && word != first) {
	                 minCnt = min(minCnt, cnt);
	            }
	            counting = true;
	            first = word;
	            cnt = 0;
	        }
	        
	        if (counting) {
	            ++cnt;
	        }
	    }
	    
	    return minCnt;
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

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}  // } Driver Code Ends