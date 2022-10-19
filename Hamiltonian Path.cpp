//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<vector<int>> graph(N, vector<int> ());
        unordered_set<int> visited;
        
        for (int i = 0; i < M; ++i) {
            graph[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
            graph[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
        }
        
        for (int i = 0; i < N; ++i) {
            if (checkPath(graph, visited, i)) {
                return true;
            }
        }
        return false;
    }
    
    bool checkPath(vector<vector<int>> &graph, unordered_set<int> visited, int currentNode) {
        if (visited.find(currentNode) != visited.end()) {
            return false;
        }
        
        visited.insert(currentNode);
        if (visited.size() == graph.size()) {
            return true;
        }
        
        for (int i = 0; i < graph[currentNode].size(); ++i) {
            if (checkPath(graph, visited, graph[currentNode][i])) {
                return true;
            }
        }
        
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends