// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string result;
        bool leading = true;

        for (char i : s) {
            if (i == '.') {
                leading = true;
                if (result.length() == 0 || result[result.length() - 1] == '.') {
                    result += '0';
                }

                result += i;
            } else if (leading) {
                if (i != '0') {
                    result += i;
                    leading = false;
                }
            } else {
                result += i;
            }
        }
        
        if (result.length() == 0 || result[result.length() - 1] == '.') {
            result += '0';
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends