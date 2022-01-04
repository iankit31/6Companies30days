class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9,sum = 0;
        int i =0,j=0,n = nums.size();
        while(i<n)
        {
            sum += nums[i];
           while(sum >= target)
           {
               ans = min(ans,i-j+1);
               sum -= nums[j];
               j++;
           }
            i++;
        }
        if(ans == 1e9)
            ans = 0;
        return ans;
    }
};