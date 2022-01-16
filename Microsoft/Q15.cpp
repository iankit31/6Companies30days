// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topo(int u,vector<bool> &vis,unordered_set<int> dag[], string &s)
    {
        vis[u] = true;
        
        for(auto v:dag[u])
        {
            if(!vis[v])
            {
                topo(v,vis,dag,s);
            }
        }
        s.insert(s.begin(),'a'+char(u));
    }
    string findOrder(string dict[], int N, int K) {
        //code here
       unordered_set<int> dag[K];
       string s1,s2;
       int i1,i2;
       int n1,n2;
       for(int i = 0;i<N-1;i++)
       {
           s1 = dict[i];
           s2 = dict[i+1];
           
           i1 = 0,i2 = 0;
           n1 = s1.length(),n2 = s2.length();
           while(i1<n1 && i2<n2)
           {
               if(s1[i1] == s2[i2])
               {
                   i1++,i2++;
               }
               else
               {
                   dag[s1[i1]-'a'].insert(s2[i2]-'a');
                   break;
               }
           }
       }
       
       string s = "";
       vector<bool> vis(K,false);
       
       for(int i=0;i<K;i++)
       {
           if(!vis[i])
                topo(i,vis,dag,s);
       }
       return s;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends