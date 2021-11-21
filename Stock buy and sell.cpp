// { Driver Code Starts

// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    queue<pair<int, int>> result;
    for (int i = 0; i < n-1; ++i) {
        if (price[i] < price[i + 1]) {
            if (result.empty() || price[result.back().second] > price[i])
                result.push(make_pair(i, i + 1));
            else
                result.back().second = i + 1;
        } else if (price[i] == price[i + 1] && !result.empty() && price[result.back().second] == price[i]) {
            result.back().second = i + 1;
        }
    }
    
    if (result.empty()) {
        cout << "No Profit";
    } else {
        while (!result.empty()) {
            pair<int, int> front = result.front();
            result.pop();
            cout << "(" << front.first << " " << front.second << ") ";
        }
    }
    cout << endl;
}