// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix) {
        int i = 0, j = 0, ver = 0, hor = 1;
        while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                
                if (ver == -1) {
                    ver = 0;
                    hor = 1;
                } else if (hor == 1) {
                    ver = 1;
                    hor = 0;
                } else if (ver == 1) {
                    ver = 0;
                    hor = -1;
                } else {
                    ver = -1;
                    hor = 0;
                }
            }
            
            i += ver;
            j += hor;
        }
        
        return make_pair(i - ver, j - hor);
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends