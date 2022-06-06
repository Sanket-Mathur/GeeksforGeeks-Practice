// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_map<int, int> mem;
        int faults = 0;
        
        for (int i = 0; i < N; ++i) {
            if (mem.find(pages[i]) == mem.end()) {
                faults++;
                
                if (mem.size() >= C) {
                    int leastKey = -1, leastValue = INT_MAX;
                    for (pair<int, int> p : mem) {
                        if (leastValue > p.second) {
                            leastKey = p.first;
                            leastValue = p.second;
                        }
                    }
                    
                    mem.erase(leastKey);
                }
            }
            
            mem[pages[i]] = i;
        }
        
        return faults;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends