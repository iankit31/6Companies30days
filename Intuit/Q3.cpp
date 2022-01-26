// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int stoii(string s)
{
    int num = 0;
    for(int i=0;i<s.length();i++)
    {
        num = num*10 + (s[i]-'0');
    }
    return num;
}
int missingNumber(const string& s)
{
    // Code here
    int n = s.length();
    int l,i,j;
    string temp;
    for(int len = 1;len<=6;len++)
    {
        l = len;
        temp = "";
        i=0;
        while(i<n && l--)
        {
            temp += s[i];
            i++;
        }
        int prev = stoii(temp);
        int count=0,j=i,miss,flag=0;
        
        temp = "";
        while(j<n)
        {
            temp += s[j];
            j++;
            if(prev + 1 == stoii(temp))
            {
                prev = stoii(temp);
                temp = "";
            }
            else if(prev + 2 == stoii(temp))
            {
                count++;
                miss=prev+1;
                prev=stoii(temp);
                temp="";
            }
            else if(prev < stoii(temp))
            {
                flag = 1;
            }  
        }
        if(count == 1 && flag != 1)
        {
            return miss;
        }
    }
    return -1;
}