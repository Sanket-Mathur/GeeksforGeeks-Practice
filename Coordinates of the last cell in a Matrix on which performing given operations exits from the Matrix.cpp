//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int m = matrix.size(), n = matrix[0].size();
        
        int posX = 0, posY = 0, momX = 0, momY = 1;
        if (matrix[0][0]) {
            matrix[0][0] = 0;
            setDir(momX, momY);
        }

        while(isValid(posX + momX, posY + momY, m, n)) {
            posX += momX;
            posY += momY;
            
            if (matrix[posX][posY]) {
                matrix[posX][posY] = 0;
                setDir(momX, momY);
            }
        }
        
        return make_pair(posX, posY);
    }
    
    void setDir(int &x, int &y) {
        if (x == -1) {
            x = 0;
            y = 1;
        } else if (x == 1) {
            x = 0;
            y = -1;
        } else if (y == -1) {
            x = -1;
            y = 0;
        } else {
            x = 1;
            y = 0;
        }
    }

    bool isValid(int posX, int posY, int m, int n) {
        return posX >= 0 && posX < m && posY >= 0 && posY < n;
    }
};

//{ Driver Code Starts.


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
}
// } Driver Code Ends