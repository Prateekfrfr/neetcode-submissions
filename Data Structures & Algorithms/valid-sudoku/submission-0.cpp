class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_map<char, int>> rows(9);
        vector<unordered_map<char, int>> cols(9);
        vector<unordered_map<char, int>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                char num = board[i][j];
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i][num] > 0 ||
                    cols[j][num] > 0 ||
                    boxes[box][num] > 0)
                    return false;

                rows[i][num]++;
                cols[j][num]++;
                boxes[box][num]++;
            }
        }

        return true;        
    }
};
