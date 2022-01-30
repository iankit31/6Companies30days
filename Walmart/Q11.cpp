
class Solution {
public:
    #define ll long long int
    int maxPerformance(int n, vector<int>& speed, vector<int>& effi, int k) {
        int mod = 1e9+7;
       // int n = speed.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({effi[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        multiset<int> ms;
        ll ans = 0,sum=0;
        for(int i=0;i<n;i++)
        {
            ms.insert(vp[i].second);
            sum+= vp[i].second;
            ans = max(ans,sum*vp[i].first);
            
            if(ms.size() == k)
            {
                sum -= *ms.begin();
                ms.erase(ms.begin());
            }
        }
        
        return (ans%mod);
    }
};