// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> posTemp, negTemp;
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0) {
                posTemp.push_back(arr[i]);
            } else {
                negTemp.push_back(arr[i]);
            }
        }
        
        int index = 0;
        for (int i = 0; i < posTemp.size(); ++i) {
            arr[index++] = posTemp[i];
        }
        for (int i = 0; i < negTemp.size(); ++i) {
            arr[index++] = negTemp[i];
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends