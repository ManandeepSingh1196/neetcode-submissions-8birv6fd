class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> heap (nums.begin(), nums.end());

        for (int idx = 0; idx < k - 1; ++idx)
            heap.pop();

        return heap.top();
    }
};
