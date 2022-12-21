//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    long long ExtractNumber(string S) {
        long long result = -1;
        string tempNumber = "";
        
        bool flag = false;
        for (auto i : S) {
            if (i >= '0' && i <= '8') {
                if (!flag) {
                    tempNumber.push_back(i);
                }
            } else if (i == '9') {
                tempNumber = "";
                flag = true;
            } else {
                if (tempNumber.length() > 0) {
                    result = max(result, stoll(tempNumber));
                    tempNumber = "";
                }
                flag = false;
            }
        }
        
        return tempNumber.length() > 0 ? max(result, stoll(tempNumber)) : result;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.ExtractNumber(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends