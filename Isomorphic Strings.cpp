// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if (str1.length() != str2.length()) {
            return false;
        }
        
        int mapping[256], check[256];
        memset(mapping, -1, sizeof(mapping));
        memset(check, -1, sizeof(check));
        
        for (int i = 0; i < str1.length(); ++i) {
            if (mapping[(int)str1[i]] == -1) {
                mapping[(int)str1[i]] = (int)str2[i];
                
                if (check[(int)str2[i]] != -1) {
                    return false;
                } else {
                    check[(int)str2[i]] = (int)str1[i];
                }
            } else if (mapping[(int)str1[i]] != (int)str2[i]) {
                return false;
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends