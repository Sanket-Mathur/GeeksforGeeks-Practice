// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        string s = str1;
        s.erase(0, 2);
        s += str1[0];
        s += str1[1];
        
        if (s == str2) {
            return true;
        }
        
        s = str1;
        s.erase(str1.length() - 2, 2);
        s = str1[str1.length() - 1] + s;
        s = str1[str1.length() - 2] + s;
        
        if (s == str2) {
            return true;
        }
        
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends