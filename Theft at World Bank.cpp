// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    vector<pair<long long, long long>> items;
	    for (int i = 0; i < N; ++i) {
	        if (ceil((long double)sqrt(w[i])) != floor((long double)sqrt(w[i]))) {
	            items.push_back({p[i], w[i]});
	        }
	    }
	    
	    sort(items.begin(), items.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b) -> bool {
	        return (long double)a.first / a.second > (long double)b.first / b.second;
	    });
	    
	    long double result = 0;
	    for (int i = 0; i < items.size() && C > 0; ++i) {
	        if (items[i].second <= C) {
	            result += items[i].first;
	            C -= items[i].second;
	        } else {
	            result += ((long double)items[i].first / items[i].second) * C;
	            C = 0;
	        }
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends