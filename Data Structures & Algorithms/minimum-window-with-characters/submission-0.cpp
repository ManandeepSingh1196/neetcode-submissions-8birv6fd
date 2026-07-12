class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;

        for (char c : t)
            countT[c]++;

        int need = countT.size(), have = 0;
        int left = 0, right = 0;

        pair<int, int> ans = {-1, -1};  

        while (right < s.size()) 
        {
            char c = s[right];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c])
                have++;

            while (have == need) 
            {
                if (ans.first == -1 || (right - left) < (ans.second - ans.first)) 
                    ans = {left, right};
                

                window[s[left]]--;

                if (countT.count(s[left]) &&
                    window[s[left]] < countT[s[left]])
                    have--;

                left++;
            }

            right++;
        }

        return ans.first == -1 ? "" : s.substr(ans.first, ans.second - ans.first + 1);
    }
};