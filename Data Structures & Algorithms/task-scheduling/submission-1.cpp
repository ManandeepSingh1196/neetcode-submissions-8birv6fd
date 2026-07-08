class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> frq(26, 0);
        for (char curr : tasks)
            frq[curr - 'A']++;

        sort(frq.begin(), frq.end(), std::greater<int>());

        int maxFrq = frq[0];
        int idleTime = (maxFrq - 1) * n;

        for (int idx = 1; idx < 26; ++idx)
            idleTime -= min(maxFrq - 1, frq[idx]);

        return max(0, idleTime) + tasks.size();
    }
};
