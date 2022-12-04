//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        int vcnt = 0, ccnt = 0;
        vector<int> vowels(26, 0), consonants(26, 0);
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < N; ++i) {
            if (vow.find(S[i]) == vow.end()) {
                ++ccnt;
                consonants[S[i] - 'a']++;
            } else {
                ++vcnt;
                vowels[S[i] - 'a']++;
            }
        }
        
        if (abs(vcnt - ccnt) > 1) {
            return "-1";
        }
        
        int vind = findNextInd(vowels, 0), cind = findNextInd(consonants, 0);
        string result;
        
        if (vcnt > ccnt || (vcnt == ccnt && vind < cind)) {
            result.push_back('a' + vind);
            vowels[vind]--;
            
            if (vowels[vind] == 0) {
                vind = findNextInd(vowels, vind);
            }
        }
        
        while (vind < 26 || cind < 26) {
            if (cind < 26) {
                result.push_back('a' + cind);
                consonants[cind]--;
                
                if (consonants[cind] == 0) {
                    cind = findNextInd(consonants, cind);
                }
            }
            if (vind < 26) {
                result.push_back('a' + vind);
                vowels[vind]--;
                
                if (vowels[vind] == 0) {
                    vind = findNextInd(vowels, vind);
                }
            }
        }
        
        return result;
    }
    
    int findNextInd(vector<int> arr, int curr) {
        int ind = curr;
        while (ind < 26 && arr[ind] == 0) {
            ind++;
        }
        
        return ind;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends