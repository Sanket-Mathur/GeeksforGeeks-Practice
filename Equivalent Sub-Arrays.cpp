// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_set<int> unique;
        for (int i = 0; i < n; ++i) {
            unique.insert(arr[i]);
        }
        
        int size = unique.size();
        
        unordered_map<int, int> currCount;
        int start = 0, end = 0;
        int subarrCount = 0;
        
        while (end < n) {
            if (currCount.size() < size) {
                currCount[arr[end++]]++;
            } else {
                subarrCount += n - end + 1;
                if (currCount[arr[start]] == 1) {
                    currCount.erase(arr[start++]);
                } else {
                    currCount[arr[start++]]--;
                }
            }
        }
        
        while (currCount.size() == size) {
            subarrCount++;
            if (currCount[arr[start]] == 1) {
                currCount.erase(arr[start++]);
            } else {
                currCount[arr[start++]]--;
            }
        }
        
        return subarrCount;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends