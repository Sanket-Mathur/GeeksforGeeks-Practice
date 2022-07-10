// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    sort(a, a + n);
    vector<int> result(n);
    
    int index = 0;
    for (int i = n - 1; i >= n / 2; --i) {
        result[index] = a[i];
        index += 2;
    }
    
    index = 1;
    for (int i = 0; i < n / 2; ++i) {
        result[index] = a[i];
        index += 2;
    }
    
    int position = 0;
    for (int i = 0; i < n; ++i) {
        position += i % 2 == 0 ? result[i] : -result[i];
    }
    
    return position == 0 ? vector<int> (1, -1) : result;
}
