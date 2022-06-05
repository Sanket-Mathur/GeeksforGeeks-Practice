// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        vector<string> result;
        
        helper(s, "", "", 0, result, 0);
        
        return result;
    }

    void helper(string &s, string curr, string num, int index, vector<string> &result, int cnt) {
        if (num.length() > 0 && (stoi(num) > 255 || to_string(stoi(num)).length() != num.length())) {
            return;
        } else if (index == s.length()) {
            if (cnt == 2 && num.length() > 0) {
                result.push_back(curr + '.' + num);
            }
            return;
        }
        
        if (curr.length() == 0 && num.length() > 0) {
            helper(s, num, "", index, result, cnt);
        } else if (num.length() > 0) {
            helper(s, curr + '.' + num, "", index, result, cnt + 1);
        }
        
        num += s[index];
        helper(s, curr, num, index + 1, result, cnt);
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends