// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        unordered_map<string, int> table;
        for (auto i : numbers) {
            table[to_string(i)]++;
        }
        
        long long res = 0;
        for (auto i : numbers) {
            if (matchInitial(i, X)) {
                string remain = remainingChars(i, X);
                if (table.find(remain) != table.end()) {
                    res += table[remain];
                    
                    if (remain == to_string(i)) {
                        res--;
                    }
                }
            }
        }
        
        return res;
    }
    
    bool matchInitial(int a, int b) {
        string sub = to_string(a);
        string parent = to_string(b);
        
        if (parent.length() < sub.length()) {
            return false;
        }
        
        return parent.substr(0, sub.length()) == sub;
    }
    
    string remainingChars(int a, int b) {
        string sub = to_string(a);
        string parent = to_string(b);
        
        return parent.substr(sub.length());
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends