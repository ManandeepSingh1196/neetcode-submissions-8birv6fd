class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> idxStck;
        int maxArea = 0;

        for (int idx = 0; idx < heights.size(); ++idx)
        {
            while (!idxStck.empty() && heights[idxStck.top()] > heights[idx])
            {
                int topIdx = idxStck.top();
                idxStck.pop();

                int leftSmallerIdx = idxStck.empty() ? -1 : idxStck.top();
                int width = idx - leftSmallerIdx - 1;

                maxArea = max(maxArea, heights[topIdx] * width);
            }

            idxStck.push(idx);
        }

        while (!idxStck.empty())
        {
            int topIdx = idxStck.top();
            idxStck.pop();

            int leftSmallerIdx = idxStck.empty() ? -1 : idxStck.top();
            int width = heights.size() - leftSmallerIdx - 1;

            maxArea = max(maxArea, heights[topIdx] * width);
        }

        return maxArea;
    }
};