// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        vector<int> count(26, 0);
        int sum = 0;
        
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= '0' && str[i] <= '9')
                sum += (str[i] - '0');
            else
                count[str[i] - 'A'] += 1;
        }
        
        string result = "";
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                result += (char)('A' + i);
            }
        }
        result += to_string(sum);
        
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends