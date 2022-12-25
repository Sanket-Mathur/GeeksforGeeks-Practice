//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long int zi = -1, zj = -1, rsum = -1, csum = -1, d1sum = 0, d2sum = 0, missingSum = -1;
        
        // checking row sums
        for (int i = 0; i < n; ++i) {
            long long int tsum = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zi = i;
                    zj = j;
                }
                
                tsum += matrix[i][j];
            }
            if (zi == i) {
                missingSum = tsum;
                continue;
            }
            
            if (rsum == -1) {
                rsum = tsum;
            } else if (rsum != tsum) {
                return -1;
            }
        }
        
        long long int result =  rsum - missingSum;
        if (result <= 0) {
            return -1;
        }
        
        // checking column sums
        for (int j = 0; j < n; ++j) {
            long long int tsum = 0;
            for (int i = 0; i < n; ++i) {
                tsum += matrix[i][j];
                if (matrix[i][j] == 0) {
                    tsum += result;
                }
            }
            
            if (csum == -1) {
                csum = tsum;
                if (csum != rsum) {
                    return -1;
                }
            } else if (csum != tsum) {
                return -1;
            }
        }
        
        // checking diagonal 
        for (int i = 0; i < n; ++i) {
            d1sum += matrix[i][i];
            d2sum += matrix[i][n - i - 1];
            
            if (matrix[i][i] == 0) {
                d1sum += result;
            }
            if (matrix[i][n - i - 1] == 0) {
                d2sum += result;
            }
        }
        if (d1sum != csum || d2sum != csum) {
            return -1;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends