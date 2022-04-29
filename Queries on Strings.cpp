// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<vector<int>> counts(str.length(), vector<int> (26, 0));
	    for (int i = 0; i < str.length(); ++i) {
	        for (int j = i; j < str.length(); ++j) {
	            counts[j][str[i] - 'a']++;
	        }
	    }
	    
	    vector<int> result;
	    for (int i = 0; i < Query.size(); ++i) {
	        int cnt = 0;
	        int L = Query[i][0], R = Query[i][1];
	        
	        for (int j = 0; j < 26; ++j) {
	            if (L == 1) {
	                cnt += counts[R-1][j] > 0 ? 1 : 0;
	            } else {
	                cnt += counts[R-1][j] > counts[L-2][j] ? 1 : 0;
	            }
	        }
	        
	        result.push_back(cnt);
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends