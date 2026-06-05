class Solution {
private:
    unordered_set<int> visiting;
    unordered_set<int> done;

    bool dfs(const vector<vector<int>>& graph, int course) {
        if (visiting.count(course))
            return false; 

        if (done.count(course))
            return true;   

        visiting.insert(course);

        for (int prereq : graph[course]) {
            if (!dfs(graph, prereq))
                return false;
        }

        visiting.erase(course);
        done.insert(course);

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(graph, course))
                return false;
        }

        return true;
    }
};