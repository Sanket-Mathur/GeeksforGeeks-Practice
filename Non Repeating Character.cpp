// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char,int> rep;
        
        for(char &c:S) {
            if(rep.find(c)==rep.end()) {
                rep[c]=0;
            } else {
                rep[c]++;
            }
        }
        
        for(char &a:S) {
            if(rep[a]==0) {
                return a;
            }
        }
        
        return '$';
    }
    
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends