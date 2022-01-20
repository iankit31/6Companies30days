// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr,arr+n,0);
        if(sum%2)
            return 0;
        int tr = sum/2,i,j;
        bool dp[n+1][tr+1];
        
        for(i=0;i<=n;i++)
            dp[i][0] = true;
        for(i=1;i<=tr;i++)
            dp[0][i] = false;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=tr;j++)
            {
                if(j<arr[i-1])
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                
            }
        }
        return dp[n][tr];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends