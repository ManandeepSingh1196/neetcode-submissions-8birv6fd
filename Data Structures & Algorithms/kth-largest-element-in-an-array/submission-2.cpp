class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> heap (nums.begin(), nums.end());

        while (k > 1)
        {
            heap.pop(); --k;
        }

        return heap.top();
    }
};
