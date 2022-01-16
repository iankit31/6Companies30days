// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int n,m;
    vector<int> dx = {1,1,-1,-1,0,0,1,-1};
    vector<int> dy = {1,-1,-1,1,1,-1,0,0};
    
    bool isvalid(int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
            
        return true;
    }
    int dfs(vector<vector<int>>&grid,int x,int y)
    {
        grid[x][y] = 0;
        int res = 1;
        for(int i=0;i<8;i++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(isvalid(newx,newy) && grid[newx][newy])
            {
                res += dfs(grid,newx,newy);
            }
        }
        
        return res;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends