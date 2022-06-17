// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int, int> snakes, ladders;
        for (int i = 0; i < 2 * N; i += 2) {
            if (arr[i] < arr[i + 1]) {
                ladders[arr[i] - 1] = arr[i + 1] - 1;
            } else {
                snakes[arr[i] - 1] = arr[i + 1] - 1;
            }
        }
        
        vector<int> board(30, INT_MAX);
        board[0] = 0;
        
        int safe = 1;
        for (int i = 0; i < 30; i++) {
            if (board[i] != INT_MAX) {
                for (int j = 1; j < 7 && i + j < 30; ++j) {
                    if (snakes.find(i + j) == snakes.end()) {
                        board[i + j] = min(board[i + j], board[i] + 1);
                    }
                }
                
                if (ladders.find(i) != ladders.end()) {
                    board[ladders[i]] = min(board[ladders[i]], board[i]);
                }
            }
        }
        
        return board[29];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends