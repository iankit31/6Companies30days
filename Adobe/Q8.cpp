//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0;
        int fg = 0;
        for(auto x:str)
        {
            if(fg == 0 )
            {
                if(x == '-')
                {
                    fg = 2;
                    continue;
                }
                else
                {
                    fg = 1;
                }
            }
            if(x-'0'>=0 && x-'0'<= 9)
            {
                ans = ans*10 + (x-'0');
            }
            else
            {
                return -1;
            }
            
        }
        if(fg == 2)
        {
            ans*=-1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends