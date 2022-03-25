// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    vector<int> sorted(arr, arr + n);
    sort(sorted.begin(), sorted.end());
    
    for (int i = 0; i < n; ++i) {
        int low = 0, high = n - 1;
        int mid = low + (high - low) / 2;
        while (low < high) {
            if (sorted[mid] == arr[i]) {
                break;
            } else if (sorted[mid] > arr[i]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
            mid = low + (high - low) / 2;
        }
        
        while (mid < n - 1 && sorted[mid] == sorted[mid + 1]) {
            mid++;
        }
        
        if (mid < n - 1) {
            arr[i] = sorted[mid + 1];
        } else {
            arr[i] = -10000000;
        }
    }
    
    return arr;
}
