class Solution {
public:
    bool isValid(string s) {
        int stck [s.size()];
        int top = -1;

        static unsigned char val[128] = {0};
        val['('] = 1; val[')'] = '(';
        val['{'] = 1; val['}'] = '{';
        val['['] = 1; val[']'] = '[';
        

        const char* start = s.data();
        const char* end = start + s.size();

        while (start < end){
            char c = *start++;
            char v = val[c];

            if (v == 1)
                stck[++top] = c;
            else
            {
                if (top < 0 || stck[top] != v) return false;
                --top;
            }
        }
        return top == -1;
    }
};
