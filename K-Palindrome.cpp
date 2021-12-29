#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
bool checkKPalin(string &s, int k, int i, int j) {
    if (k < 0) return false;
    if (i >= j) return true;
    
    if (s[i] == s[j]) {
        return checkKPalin(s, k, i+1, j-1);
    } else {
        return checkKPalin(s, k-1, i, j-1) || checkKPalin(s, k-1, i+1, j);
    }
}

bool is_k_palin(string s,int k)
{
    return checkKPalin(s, k, 0, s.size() - 1);
}