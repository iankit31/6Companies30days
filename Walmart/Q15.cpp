class Solution {
public:
    unsigned int intAbs(int num)
    {
        if(num == INT_MIN)
            return (unsigned int)INT_MAX + 1;
        else
            return abs(num);   
    }
    
    char mostSignBit(unsigned int num)
    {
        int num_msb = 31;
        while(!(num & (1 << num_msb)))
            --num_msb;  
        
        return num_msb;
    }
    
    int divide(int dividend, int divisor) {
        
         if(dividend == 0)
            return 0;
        
        if(dividend == INT_MIN and divisor == -1)
            return INT_MAX;
        
        
        unsigned int dividendAbs = intAbs(dividend);
        unsigned int divisorAbs = intAbs(divisor);

        char dividendAbs_msb = mostSignBit(dividendAbs);
        char divisorAbs_msb = mostSignBit(divisorAbs);

        int res = 0;
       
        for(int i = dividendAbs_msb - divisorAbs_msb; i >= 0; i--)
        {
            unsigned int divisorAbs_shift = divisorAbs << i; 
            if(divisorAbs_shift <= dividendAbs)
            {   
                dividendAbs -= divisorAbs_shift;
                res |= 1 << i;
            }   
        }
        
        // check overflow case
        if(res == INT_MIN)
            return INT_MIN;
       
        else
            return (dividend ^ divisor) < 0 ? ~res + 1 : res;
    }
};