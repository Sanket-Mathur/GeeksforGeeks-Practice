// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
        sort(Y, Y + N);
        
        long long ones = 0, twos = 0;
        for (int i = 0; i < N; ++i) {
            if (Y[i] == 1) {
                ++ones;
            } else if (Y[i] == 2) {
                ++twos;
            }
        }
        
        long long cnt = 0;
        for (int i = 0; i < M; ++i) {
            if (X[i] == 1) {
                continue;
            } else if (X[i] == 2) {
                X[i] = 4;
            } else if (X[i] == 3) {
                cnt += twos;
            }
            
            cnt += ones;
            cnt += Y + N - upper_bound(Y, Y + N, X[i]);
        }
        
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends