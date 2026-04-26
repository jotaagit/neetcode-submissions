class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<string> seen;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];
                if (val != '.') {
                    string row = "r" + to_string(r) + val;
                    string col = "c" + to_string(c) + val;
                    string box = "b" + to_string(r / 3) + to_string(c / 3) + val;
                    if (seen.count(row) || seen.count(col) || seen.count(box)) return false;
                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
            }
        }
        return true;
    }
};