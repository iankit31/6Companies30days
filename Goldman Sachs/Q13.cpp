// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int i;
    Solution(){i=0;}
    string decodedString(string s){
        // code here
         string ans="";         // initally empty string
        int num = 0;        // number of times to be repeated
        while(i<s.size())
        {
            // if character simply add 
            if(s[i]>= 'a' && s[i]<='z')    
            {
                ans += s[i];
                i++;
            }
            
            // if digit combine with num
            else if(s[i]>='0' && s[i]<='9')
            {
                num = num*10 + int(s[i] - '0');
                i++;
            }
            
            // if [ increment pointer and call recursively
            else if(s[i] == '[')
            {
                i++;    // skipping [
                
                string temp = decodedString(s);
                // repeating the recursive result num times
                for(int i=0; i<num; i++)    
                    ans += temp;
                
                // reset num
                num = 0;
                
                i++;    // skipping ]
            }
            else    // if encounter ] of parent recursive call return
                return ans;
        }
        
        // after finishing the string return ans
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends