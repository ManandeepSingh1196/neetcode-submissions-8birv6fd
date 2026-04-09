class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int lookup[256] = {0};   // 256, not 255
        int start = 0, maxLength = 0, curr = 0;

        for (auto ch : s) {
            unsigned char uc = static_cast<unsigned char>(ch);
            if (lookup[uc] == 0) {
                ++curr;
                lookup[uc] = 1;
            } else {
                while (lookup[uc] == 1) {
                    unsigned char us = static_cast<unsigned char>(s[start]);
                    lookup[us] = 0;
                    ++start;
                    --curr;
                }

                ++curr;
                lookup[uc] = 1;
            }
            if (curr > maxLength) maxLength = curr;
        }
        return maxLength;
    }
};
