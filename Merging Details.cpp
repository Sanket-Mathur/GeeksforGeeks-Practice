//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        map<string, int> mail_id;
        vector<vector<string>> ret;
        vector<set<string>> mail;
        vector<string> name;
        
        mail.push_back(set<string>());
        name.push_back("");
        
        for (auto d : details)  {
        	int id = 0;
        	for (int i = 1; i < d.size(); ++i) {
        		id = max(id, mail_id[d[i]]);
        	}
        	  
        	if (id == 0) {
        		id = name.size();
        		name.push_back(d[0]);
        		mail.push_back(set<string>());
        	}
        
        	for (int i = 1; i < d.size(); ++i) {
        		mail_id[d[i]] = id;
        		mail[id].insert(d[i]);
        	}
        }
        
        for (int i = 1; i < name.size(); ++i) {
        	ret.push_back({name[i]});
        	
        	for (auto& m : mail[i])
        		ret.back().push_back(m);
        }
        
        sort(ret.rbegin(), ret.rend());
        return ret;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends