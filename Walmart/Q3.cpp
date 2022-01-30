class Solution {
public:
    bool winnerOfGame(string c) {
        int n = c.size();
        int a=0,b=0;
        for(int i=1;i<n-1;i++)
        {
            if(c[i] == 'A')
            {
                a += c[i] == c[i-1] && c[i] == c[i+1];  
            }
            else
            {
                b += c[i] == c[i-1] && c[i] == c[i+1];  
            }
        }
        
        if(a>b)
            return true;
        return false;
    }
};