class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int>ans;
        for(auto x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int>Q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                Q.push(i);
            }
        }
        
        while(!Q.empty())
        {
            auto curr = Q.front();
            Q.pop();
            ans.push_back(curr);
            
            for(auto nextCourse:graph[curr])
            {
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0)
                {
                    Q.push(nextCourse);
                }
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
       return {};
    }
};