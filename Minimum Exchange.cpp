//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    int cnt1 = 0, cnt2 = 0;

    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 'A') {
                if((i + j) % 2 == 0) {
                    cnt1++;
                } else {
                    cnt2++;
                }
            } else {
                if((i + j) % 2 == 0) {
                    cnt2++;
                } else {
                    cnt1++;
                }
            }
        }
    }

    int ans = min(cnt1, cnt2);
    if(ans % 2 == 0) {
        return ans / 2;
    }
    return min(ans, (m * n - ans) / 2);
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends