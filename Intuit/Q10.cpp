class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool>& vis)
    {
        vis[u] = true;
        int n = vis.size();
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && isConnected[u][i])
            {
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0,n = isConnected.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        
        return ans;
    }
};