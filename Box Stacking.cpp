// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<vector<int>> combined;
        for (int i = 0; i < n; ++i) {
            combined.push_back({
                length[i],
                width[i],
                height[i],
                length[i] * width[i]
            });
            combined.push_back({
                max(height[i], width[i]),
                min(height[i], width[i]),
                length[i],
                height[i] * width[i]
            });
            combined.push_back({
                max(height[i], length[i]),
                min(height[i], length[i]),
                width[i],
                height[i] * length[i]
            });
        }
        
        sort(combined.begin(), combined.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[3] > b[3];
        });
        
        vector<int> maxLength(combined.size(), 0);
        for (int i = 0; i < combined.size(); ++i) {
            maxLength[i] = combined[i][2];
        }
        
        int j = 0, i = 1;
        while (i < combined.size()) {
            while (j < i) {
                if ((combined[i][0] < combined[j][0] && combined[i][1] < combined[j][1]) || 
                (combined[i][0] < combined[j][1] && combined[i][1] < combined[j][0])) {
                    maxLength[i] = max(maxLength[i], maxLength[j] + combined[i][2]);
                }
                j++;
            }
            j = 0;
            i++;
        }
        
        return *max_element(maxLength.begin(), maxLength.end());
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends