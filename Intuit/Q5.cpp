class Solution {
public:
    bool possible(vector<int>& nums,int targetsum, int m)
    {
        int cnt = 0,currsum=0;
        for(auto x:nums)
        {
            currsum += x;
            if(x>targetsum)
                return false;
            if(currsum > targetsum)
            {
                cnt++;
                currsum = x;
            }
        }
        cnt++;
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto x:nums)
            sum += x;
        
        int low = 0,high = sum,mid;
        while(low<high)
        {
            mid = low + (high-low)/2;
            
            if(possible(nums,mid,m))
            {
                high = mid;
            }
            else
                low = mid+1;
        }
        return low;
    }
};