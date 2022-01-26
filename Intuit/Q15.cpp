class Solution {
public:
    bool check(vector<int>&piles, int k,int h)
    {
        int time = 0,n = piles.size();
        for(int i=0;i<n;i++)
        {
            time += (piles[i] + (k-1))/k;
        }
        return time <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 1e9;
        int low = 1,high = ans,mid;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(check(piles,mid,h))
            {
                ans = mid;
                high = mid-1;
            }else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};