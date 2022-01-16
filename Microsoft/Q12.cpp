#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int> > ans;
        sort(arr.begin(),arr.end());
        int l,r,sum,sum1,req;
        int n = arr.size();
        map<pair<pair<int,int>,pair<int,int>>,int>mp;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                l = j+1;
                r = n-1;
                sum = arr[i] + arr[j];
                req = k-sum;
                while(l<r)
                {
                    sum1 = arr[l] + arr[r];
                    if(sum1<req)
                    {
                        l++;
                    }
                    else if(sum1>req)
                    {
                        r--;
                    }
                    else
                    {
                        v = {arr[i],arr[j],arr[l],arr[r]};
                        sort(v.begin(),v.end());
                        if(mp[{{v[0],v[1]},{v[2],v[3]}}] == 0)
                        {
                            mp[{{v[0],v[1]},{v[2],v[3]}}] = 1;
                            ans.push_back(v);
                        }
                        l++,r--;
                    }
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends