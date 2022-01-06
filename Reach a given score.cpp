// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
void fillTable(long long int table[], int i, int pr, int n) {
    if (i > n)
        return;
    
    table[i] += 1;
    
    if (pr <= 3)
        fillTable(table, i + 3, 3, n);
    if (pr <= 5)
        fillTable(table, i + 5, 5, n);
    if (pr <= 10)
        fillTable(table, i + 10, 10, n);
}

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	fillTable(table, 3, 3, n);
	fillTable(table, 5, 5, n);
	fillTable(table, 10, 10, n);
	
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends