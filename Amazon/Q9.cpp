// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        vector<int> dp(10,0);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                dp[mat[i][j]]++;
            }
            
            for(int j=1;j<=9;j++)
            {
                if(dp[j] > 1)
                    return 0;
                dp[j] = 0;
            }
            
        }
        
         for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                dp[mat[j][i]]++;
            }
            
            for(int j=1;j<=9;j++)
            {
                if(dp[j] > 1)
                    return 0;
                dp[j] = 0;
            }
            
        }
        
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        dp[mat[k][l]]++;
                    }
                }
                for(int k=1;k<=9;k++)
                {
                    if(dp[k] > 1)
                        return 0;
                    dp[k] = 0;
                }
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends