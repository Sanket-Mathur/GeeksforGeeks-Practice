// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    static map<char, int> table;
    static bool sortHelper(const char &a, const char &b) {
        return table[a] < table[b];
    }

	void matchPairs(char nuts[], char bolts[], int n) {
	    sort(nuts, nuts + n, sortHelper);
	    sort(bolts, bolts + n, sortHelper);
	}

};

map<char, int> Solution::table = {
    {'!', 0}, 
    {'#', 1}, 
    {'$', 2},
    {'%', 3},
    {'&', 4},
    {'*', 5},
    {'@', 6},
    {'^', 7},
    {'~', 8}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends