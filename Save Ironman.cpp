//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}

// } Driver Code Ends



bool saveIronman(string ch)
{
    int i = 0, j = ch.length() - 1;
    while (i <= j) {
        if (ch[i] == ' ' || !isalnum(ch[i])) {
            ++i;
            continue;
        }
        if (ch[j] == ' ' || !isalnum(ch[j])) {
            --j;
            continue;
        }
        
        if (tolower(ch[i]) != tolower(ch[j])) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
