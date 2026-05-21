class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result;

        for (int idx = 0; idx < 32; ++idx)
            result = (result << 1) | (n >> idx) & 1;

        return result;
    }
};
