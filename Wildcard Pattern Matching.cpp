// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int star = -1, matched = -1;
        int i = 0, j = 0;
        
        while (i < str.size()) {
            if (j < pattern.size() && (str[i] == pattern[j] || pattern[j] == '?')) {
                ++i;
                ++j;
            } else if (pattern[j] == '*') {
                star = j++;
                matched = i;
            } else if (star != -1) {
                j = star + 1;
                i = ++matched;
            } else {
                return 0;
            }
        }
        
        while (j < pattern.size() && pattern[j] == '*') {
            ++j;
        }
        
        return (int)(j == pattern.size());
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends