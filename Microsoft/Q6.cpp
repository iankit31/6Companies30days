//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    unordered_map<int,vector<char>> keypad;
    vector<string> res;
    void func(int ind,int a[],int n,string s)
    {
        if(ind == n)
        {
            res.push_back(s);
            return;
        }
        for(auto x:keypad[a[ind]])
        {
            s.push_back(x);
            func(ind+1,a,n,s);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        keypad[2] = {'a','b','c'};
        keypad[3] = {'d','e','f'};
        keypad[4] = {'g','h','i'};
        keypad[5] = {'j','k','l'};
        keypad[6] = {'m','n','o'};
        keypad[7] = {'p','q','r','s'};
        keypad[8] = {'t','u','v'};
        keypad[9] = {'w','x','y','z'};
        string s = "";
        func(0,a,n,s);
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends