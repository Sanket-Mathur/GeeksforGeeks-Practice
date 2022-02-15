// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    int counts[26] = {0};
    for (int i = 0; i < str1.length(); ++i) {
        counts[str1[i] - 'a'] += 1;
    }
    for (int i = 0; i < str2.length(); ++i) {
        counts[str2[i] - 'a'] -= 1;
    }

    int cnt = 0;    
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            cnt += counts[i];
        } else if (counts[i] < 0) {
            cnt -= counts[i];
        }
    }
    
    return cnt;
}