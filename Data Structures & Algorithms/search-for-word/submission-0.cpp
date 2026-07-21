class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(i, j, 0, board, word))
                    return true;

        return false;
    }

private: 
    bool dfs(int x, int y, int idx, auto& board, string& word) {

        if (idx == word.size()) return true;

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;

        if (board[x][y] != word[idx])
            return false;

        char temp = board[x][y];
        board[x][y] = '#';

        bool found =
            dfs(x - 1, y, idx + 1, board, word) ||
            dfs(x + 1, y, idx + 1, board, word) ||
            dfs(x, y - 1, idx + 1, board, word) ||
            dfs(x, y + 1, idx + 1, board, word);

        board[x][y] = temp;

        return found;
    }
};
