class Solution {
public:
    bool checkValidString(string s) {
        int openMin = 0, openMax = 0;

        for (char& ch : s)
        {
            if (ch == '(') {
                ++openMin; ++openMax;
            }
            else if (ch == ')') {
                --openMin; --openMax;
            }
            else {
                --openMin; ++openMax;
            }

            if (openMax < 0) return false;
            openMin = max(openMin, 0);
        }

        return openMin == 0;
    }
};
