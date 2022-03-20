// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        vector<bool> alphabets(26, false);
        for (int i = 0; i < a.length(); ++i) {
            alphabets[a[i] - 'a'] = true;
        }
        
        int index = 0;
        for (int i = 0; i < a.length(); ++i) {
            while (index < 26 && !alphabets[index]) {
                index++;
            }
            
            if ((int)(a[i] - 'a') > index) {
                swapChars(a, a[i], (char)(index + 'a'));
                break;
            } else if ((int)(a[i] - 'a') == index) {
                index++;
            }
        }
        
        return a;
    }
    
    void swapChars(string &s, char a, char b) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == a) {
                s[i] = b;
            } else if (s[i] == b) {
                s[i] = a;
            }
        }
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends