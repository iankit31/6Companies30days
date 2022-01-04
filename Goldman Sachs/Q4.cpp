// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string s = "";
  int n = src.length();
  
  int i=0;
  while(i<n)
  {
      char c = src[i];
      int cnt = 0;
      while(i< n && c == src[i]){
          cnt++,i++;
      }
      
      s += c;
      s += '0' + cnt;
  }
  return s;
}     
 
