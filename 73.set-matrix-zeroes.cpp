/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if the first row has any zeros
        for(int j = 0 ; j < n ; j++){
            if(matrix[0][j] == 0 ){
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column has any zeros
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and column to mark zeros
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set the marked rows and columns to zero
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the first row to zero if needed
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Set the first column to zero if needed
        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        
    }
};
    /*intuitive idea in simplest terms
    Use the first row and column as flags to indicate which rows and columns need to be set to zero.
    process includes:(answer as talking to 5 year old
    1. Check if the first row has any zeros and remember it.
    2. Check if the first column has any zeros and remember it.
    3. Go through the rest of the matrix and mark the first row and column if a zero is found.
    4. Go through the matrix again and set elements to zero based on the flags in the first row and column.
    5. Finally, set the first row and column to zero if they were marked in steps 1 and 2.)


    */
    

// @lc code=end

