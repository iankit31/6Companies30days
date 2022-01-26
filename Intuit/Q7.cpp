class Solution {
public:
    bool check(vector<int>w,int mx,int d)
    {
        int n = w.size();
        int sum = 0;
        int l=0,r=0;
        while(r<n)
        {
            sum+=w[r];
            if(sum>mx)
            {
                sum = 0;
                d--,r--;
            }
            r++;
        }
        
        return d>0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,mx=0;
        for(auto x:weights)
        {
            sum += x;
            mx = max(mx,x);
        }
        int l = mx,r = sum,md;
        int capacity = sum;
        while(l<=r)
        {
            
            md = l + (r-l)/2;
           
            if(check(weights,md,days))
            {
                capacity = md;
                r = md - 1;
            }
            else
                l = md+1;
        }
        return capacity;
        
    }
};