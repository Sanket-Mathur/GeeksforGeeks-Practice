// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        vector<int> combined(array1.size() + array2.size(), 0);
        int i = 0, j = 0, k = 0;
        
        while (i < array1.size() && j < array2.size()) {
            if (array1[i] < array2[j]) {
                combined[k++] = array1[i++];
            } else {
                combined[k++] = array2[j++];
            }
        }
        while (i < array1.size()) {
            combined[k++] = array1[i++];
        }
        while (j < array2.size()) {
            combined[k++] = array2[j++];
        }
        
        return combined.size() % 2 == 1 ? combined[combined.size() / 2] : (double)(combined[combined.size() / 2 - 1] + combined[combined.size() / 2]) / 2;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends