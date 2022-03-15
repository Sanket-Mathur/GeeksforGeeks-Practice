// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> number = {1};
        for (int i = 2; i <= N; ++i) {
            multiply(number, i);
        }
        
        return vector<int> (number.rbegin(), number.rend());
    }
    
    void multiply(vector<int> &number, int n) {
        int carry = 0;
        for (int i = 0; i < number.size(); ++i) {
            int num = number[i] * n + carry;
            carry = num / 10;
            number[i] = num % 10;
        }
        
        while (carry > 0) {
            number.push_back(carry % 10);
            carry /= 10;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends