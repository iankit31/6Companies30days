class Solution {
public:
    string s;
    vector<vector<bool>>vis;
    bool ans;
    int n,m;
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    bool valid(int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return true;
    }
    
    void dfs(int x,int y,int ind,vector<vector<char>>& board)
    {
        if(board[x][y] != s[ind])
            return;
        vis[x][y] = true;
        if(ind == s.length()-1)
        {
            ans = true;
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            if(valid(x+dx[i],y+dy[i]))
            {
                 if(!vis[x+dx[i]][y+dy[i]] && board[x+dx[i]][y+dy[i]] == s[ind+1])
                {
                    dfs(x+dx[i],y+dy[i],ind+1,board);
                }
            }
        }
        vis[x][y] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        ans = false;
        n = board.size();
        m = board[0].size();
        vis = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                 vis = vector<vector<bool>>(n,vector<bool>(m,false));
                 dfs(i,j,0,board); 
                if(ans)
                    return ans;
            }
        }
        
        return ans;
    }
};