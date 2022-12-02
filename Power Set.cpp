//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> result;
		    string str;
		    
		    for (int i = 0; i < s.length(); ++i) {
		        findSubstr(s, i, str, result);
		    }
		    
		    sort(result.begin(), result.end());
		    return result;
		}
		
		void findSubstr(string s, int i, string str, vector<string> &result) {
		    if (i == s.length()) {
		        return;
		    }
		    
		    str.push_back(s[i]);
		    result.push_back(str);
		    
		    for (int j = i + 1; j < s.length(); ++j) {
		        findSubstr(s, j, str, result);
		    }
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends