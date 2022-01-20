// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&coins,int left,int right)
    {
        if(left == right)
            return coins[left];
        
        if(left + 1 == right)
            return max(coins[left],coins[right]);
        if(dp[left][right] != INT_MAX)
            return dp[left][right];
        int start = coins[left] + min(solve(coins,left+2,right),solve(coins,left+1,right-1));
        int end = coins[right] + min(solve(coins,left,right-2),solve(coins,left+1,right-1));
        
        return dp[left][right] = max(start,end);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    dp = vector<vector<int>>(n,vector<int>(n,INT_MAX));
	    return solve(A,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends