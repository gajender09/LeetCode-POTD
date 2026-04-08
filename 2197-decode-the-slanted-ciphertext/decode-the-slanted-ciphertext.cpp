class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 0) return "";

        int col = n / rows;
        string result;

        for (int i = 0; i < col; i++) {
            int j = i;

            while (j < n) {
                result += encodedText[j];
                j += col + 1;  
            }
        }

        while (!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};



// Brute Force
// class Solution {
// public:
//     string decodeCiphertext(string encodedText, int rows) {
//         int n = encodedText.size();
//         if (rows == 0) return "";

//         int col = n / rows;

//         // Step 1: build matrix
//         vector<vector<char>> mat(rows, vector<char>(col));
//         int idx = 0;

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < col; j++) {
//                 mat[i][j] = encodedText[idx++];
//             }
//         }

//         // Step 2: read diagonals
//         string result;

//         for (int j = 0; j < col; j++) {
//             int x = 0, y = j;

//             while (x < rows && y < col) {
//                 result += mat[x][y];
//                 x++;
//                 y++;
//             }
//         }

//         // remove trailing spaces
//         while (!result.empty() && result.back() == ' ')
//             result.pop_back();

//         return result;
//     }
// };