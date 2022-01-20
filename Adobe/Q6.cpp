class Solution {
public:
    vector<string>ans;
    void backtrack(string s,int op,int cl,int n)
    {
        if(s.length() == n*2)
        {
             ans.push_back(s);
            return;
        }   
        if(op<n)
            backtrack(s+'(',op+1,cl,n);
        if(cl<op)
            backtrack(s+')',op,cl+1,n);
        
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;
    }
};