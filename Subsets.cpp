// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>> subsets(vector<int>& A)
    {
        vector<vector<int>> result;
        vector<int> current;
        
        result.push_back(vector<int> ());
        
        findSubsets(A, 0, result, current);
        
        sort(result.begin(), result.end());
        return result;
    }
    
    void findSubsets(vector<int> &A, int i, vector<vector<int>> &result, vector<int> current) {
        if (i >= A.size()) {
            return;
        }
        
        findSubsets(A, i + 1, result, current);
        
        current.push_back(A[i]);
        result.push_back(current);
        
        findSubsets(A, i + 1, result, current);
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends