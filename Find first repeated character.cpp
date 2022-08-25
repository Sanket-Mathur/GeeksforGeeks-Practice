//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    vector<bool> ch(26, false);
    for (int i = 0; i < s.length(); ++i) {
        if (ch[s[i] - 'a']) {
            return string(1, s[i]);
        }
        ch[s[i] - 'a'] = true;
    }
    return "-1";
}