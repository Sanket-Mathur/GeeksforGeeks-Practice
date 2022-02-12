// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        vector<pair<int, int>> events;
        for (int i = 0; i < N; ++i) {
            events.push_back(make_pair(start[i], end[i]));
        }
        
        sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        int i = 0, day = 0, count = 0;
        
        
        priority_queue<int, vector<int>, greater<int>> pq;
        while (!pq.empty() || i < N) {
            if (pq.empty()) {
                day = events[i].first;
            }
            
            while (i < N && events[i].first <= day) {
                pq.push(events[i++].second);
            }
            pq.pop();
            
            ++count;
            ++day;
            
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }            
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends