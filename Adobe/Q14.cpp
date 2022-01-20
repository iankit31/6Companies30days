#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class element{
       public:
           int value,index,row;
           
           element(int val,int indexnum,int rownum)
           {
               value=val;
               index=indexnum;
               row=rownum;
           }
   }; 
    struct compare{
       bool operator()(element a,element b)
       {
           return a.value>b.value;
       }
   };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
                   int mn=INT_MAX,mx=INT_MIN,range=INT_MAX;
         
         priority_queue<element,vector<element>,compare> q;
         
         int low,high;
         
         for(int i=0;i<k;i++)
         {
             q.push(element(KSortedArray[i][0],0,i));
             mn=min(mn,KSortedArray[i][0]);
             mx=max(mx,KSortedArray[i][0]);
         }
         
         while(!q.empty())
         {
             element temp=q.top();
             q.pop();
             
             int maybemin=temp.value;
             if(range>(mx-maybemin))
             {
                 mn=maybemin;
                 range=mx-mn;
                 low=mn;
                 high=mx;
             }
             if((temp.index)==n-1)
               break;
             
             temp.index=temp.index+1;
             q.push(element(KSortedArray[temp.row][temp.index],temp.index,temp.row));
             mx=max(mx,KSortedArray[temp.row][temp.index]);
             
         }
         return {low,high};
          
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends