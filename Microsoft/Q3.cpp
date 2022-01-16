//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n = matrix.size();
    for(int x = 0;x<(n/2);x++)
    {
        for(int y = x;y<n-1-x;y++)
        {
            int temp = matrix[x][y];
            
            matrix[x][y] = matrix[y][n-1-x];
            matrix[y][n-1-x] = matrix[n-1-x][n-1-y];
            matrix[n-1-x][n-1-y] = matrix[n-1-y][x];
            matrix[n-1-y][x] = temp;
        }
    }
    
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends