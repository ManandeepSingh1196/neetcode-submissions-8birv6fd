class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;

        int low = 0, high = total - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int r = mid / n;
            int c = mid % n;

            int val = matrix[r][c];

            if (val == target) return true;
            if (val < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
