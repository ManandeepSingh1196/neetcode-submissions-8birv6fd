class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int size = temperatures.size();
        vector<int> results(size, 0);

        int iter = size - 2;
        while (iter >= 0)
        {
            int next = iter + 1;

            while (next < size && temperatures[next] <= temperatures[iter]) {
                if (results[next] == 0) { next = size; break; }
                next += results[next];
            }

            if (next < size) 
                results[iter] = next - iter;

            --iter;
        }

        return results;
    }
};
