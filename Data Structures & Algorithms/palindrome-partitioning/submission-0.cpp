class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtracking(s, 0, path);
        return res;
    }

private:
    void backtracking(const string& s, int start, vector<string>& path) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtracking(s, end + 1, path);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};