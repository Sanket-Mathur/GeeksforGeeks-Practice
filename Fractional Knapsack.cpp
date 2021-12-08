// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, [](const Item &a, const Item &b) -> bool {
            return ((double)a.value / a.weight) > ((double)b.value / b.weight);
        });
        
        int ind = 0, w = 0;
        double result = 0.0;
        
        while (arr[ind].weight + w <= W && ind < n) {
            result += arr[ind].value;
            w += arr[ind].weight;
            ++ind;
        }
        
        if (w < W && ind < n)
            result += ((double)arr[ind].value / arr[ind].weight) * (W - w);
        
        return result;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends