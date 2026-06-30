class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool xCheck = false, yCheck = false, zCheck = false;

        for (const auto& coord : triplets)
        {
            xCheck |= (coord[0] == target[0] && coord[1] <= target[1] && coord[2] <= target[2]);
            yCheck |= (coord[0] <= target[0] && coord[1] == target[1] && coord[2] <= target[2]);
            zCheck |= (coord[0] <= target[0] && coord[1] <= target[1] && coord[2] == target[2]);
        
            if (xCheck && yCheck && zCheck) return true;
        }

        return false;
    }
};
