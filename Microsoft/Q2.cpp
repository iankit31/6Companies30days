#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 vector<vector<int>> graph;
     vector<int> vis;
    bool dfstodetectcucle(int i)
    {
        if(vis[i] == 2)
            return true;
        vis[i] = 2;
        for(auto x:graph[i])
        {
            if(vis[x] != 1)
            {
                if(dfstodetectcucle(x))
                    return true;
            }
             
        }
        vis[i] = 1;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int n = N;
         graph = vector<vector<int>>(n);
         vis = vector<int>(n,0);
        
        for(auto x:prerequisites)
        {
            graph[x.first].push_back(x.second);
        }
        
        for(int i = 0;i<n;i++)
        {
           if(vis[i] == 0)
           {
               if(dfstodetectcucle(i))
                    return false;
           }
        }
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends