// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> res;
        priority_queue<pair<int,int>>pq;
        int i=0,j=0;
        
        while(i<n)
        {
            if(i-j+1<k)
            {
                pq.push({arr[i],i});
                i++;
            }
            else
            {
                pq.push({arr[i],i});
                auto mx = pq.top().first;
                
                res.push_back(mx);
                while(!pq.empty())
                {
                    if(pq.top().second <= j)
                    {
                        pq.pop();
                    }
                    else
                        break;
                }
                i++,j++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends