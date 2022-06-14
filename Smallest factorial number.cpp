// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
            int low = 0, high = 5  * n;
            int mid, cnt;
            
            while (low <= high) {
                mid = low + (high - low) / 2;
                cnt = count5s(mid);
                
                if (cnt >= n) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            return low;
        }
        
        int count5s(int num) {
            int cnt = 0;
            while (num) {
                cnt += num / 5;
                num /= 5;
            }
            
            return cnt;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends