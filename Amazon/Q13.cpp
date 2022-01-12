class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        bool flag  = false;
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        int time=0;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){


                if(grid[i][j]==2)
                    q.push({i,j,0});
            }
        }
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int count=0;
            for(int i=0;i<4;i++){

                int r= curr[0]+dir[i][0];
                int c=curr[1]+dir[i][1];

                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                    int t=curr[2]+1;
                    grid[r][c]=2;

                    q.push({r,c,t});

                    time=max(time,t);
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    flag=true;  
            }
        }
    
    if(flag)
        return -1;
    return time;
 
 
    }
};