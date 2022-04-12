// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int max1Row = 0, ind = 0;
            for (; ind < M; ++ind) {
                if (Mat[0][ind] == 1) {
                    break;
                }
            }
            
            for (int i = 1; i < N; ++i) {
                if (ind == 0) {
                    return max1Row;
                }
                
                if (Mat[i][ind - 1] == 1) {
                    max1Row = i;
                    while (ind > 0 && Mat[i][ind - 1] == 1) {
                        ind--;
                    }
                }
            }
            
            return max1Row;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends