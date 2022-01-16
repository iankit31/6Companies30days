// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> vs;
	
	for(int i=1;i<=N;i++)
	{
	    int j = i;
	    string s = "";
	    while(j)
	    {
	        if(j%2 == 0)
	        {
	            s += '0';
	        }
	        else
	            s += '1';
            
            j/=2;
	    }
	    reverse(s.begin(),s.end());
	    vs.push_back(s);
	}
	return vs;
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
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends