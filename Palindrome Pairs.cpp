// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        unordered_map<string, int> table;
        for (int i = 0; i < N; ++i) {
            string str = arr[i];
            reverse(str.begin(), str.end());
            
            if (table.find(str) == table.end())
                table[str] = i;
            else
                table[str] = -1;
        }
        
        for (int i = 0; i < N; ++i) {
            string str = arr[i];
            
            string prefix = "", suffix = str;
            
            for (int j = 0, k = str.length()-1; j < str.length(); ++j, --k) {
                prefix += str[j];
                suffix.erase(0, 1);
                
                if (table.find(prefix) != table.end() && isPalin(suffix)) {
                    if (table[prefix] == -1 || table[prefix] != i)
                        return true;
                }
                if (table.find(suffix) != table.end() && isPalin(prefix)) {
                    if (table[suffix] == -1 || table[prefix] != i)
                        return true;
                }
            }
        }
        
        return false;
    }
    bool isPalin(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends