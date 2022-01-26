
	
class Solution {
public:
    // all posible direction
    int dx[]={-1,0,1,0};
    int dy[]={ 0,1,0,-1};
    // Check if the next move is Valid
    bool isValid(int x,int y,int n,vector<vector<int>>& dis){
        if(x<0 || x>=n || y<0 || y>=n || dis[x][y]!=-1) return false;
        return true;
    }
    int bfs(vector<vector<int>>& grid){
        queue< pair<int,int> > q;
        vector< vector<int> > dis(grid.size(),vector<int>(grid.size(),-1));
		
        // Combined the visited grid with distance grid by inititalizing distance grid with -1.
		//If the current cell is unvisited then it's value will be -1.
		
		// Push all the land cells into queue and mark their value on distance grid as 0.
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }    
        int ans=-1; //Variable to store the max Distance
		
	// Applied BFS
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            int cx=f.first;
            int cy=f.second;
            
            for(int i=0;i<4;i++){
                if(isValid(cx+dx[i],cy+dy[i],grid.size(),dis)){
                    q.push({cx+dx[i],cy+dy[i]});
                    dis[cx+dx[i]][cy+dy[i]]=dis[cx][cy]+1;
                    ans=max(ans,dis[cx+dx[i]][cy+dy[i]]);
                }
            }
        }
        return ans;
    }
    int maxDistance(vector<vector<int>>& grid) {
       return bfs(grid);
    }
};