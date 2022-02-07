// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        
        int upper = 0, lower = 0;
        while (sortedStr[lower] < 97) {
            ++lower;
        }
        
        for (int i = 0; i < n; ++i) {
            if (str[i] < 97) {
                str[i] = sortedStr[upper++];
            } else {
                str[i] = sortedStr[lower++];
            }
        }
        
        return str;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends