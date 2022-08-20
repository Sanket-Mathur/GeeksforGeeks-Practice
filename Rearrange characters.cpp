//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<pair<int, char>> heap;
        unordered_map<char, int> counts;
        
        for (int i = 0; i < str.length(); ++i) {
            counts[str[i]]++;
        }
        
        for (pair<char, int> p : counts) {
            heap.push(make_pair(p.second, p.first));
        }
        
        string result = "";
        while (heap.size() > 1) {
            pair<int, char> t1 = heap.top();
            heap.pop();
            pair<int, char> t2 = heap.top();
            heap.pop();
            
            result.push_back(t1.second);
            result.push_back(t2.second);
            
            if (t1.first > 1) {
                heap.push(make_pair(t1.first - 1, t1.second));
            }
            if (t2.first > 1) {
                heap.push(make_pair(t2.first - 1, t2.second));
            }
        }
        
        if (!heap.empty()) {
            if (heap.top().first > 1) {
                return "-1";
            }
            result.push_back(heap.top().second);
        }
        return result;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends