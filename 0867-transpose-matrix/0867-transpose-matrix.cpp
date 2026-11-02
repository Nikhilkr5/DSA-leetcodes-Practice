class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};

/*
// Learning:
// Separate ans matrix → visit every element (j = 0).
// ans[j][i] = matrix[i][j] → rows and columns are swapped.
// No need for j = i+1 because we are copying, not swapping.

// Time: O(m*n)
// Space: O(m*n)
*/

// Learning:
// LC 867 can be transposed in-place only for square matrices.
// Since LC 867 allows rectangular matrices, use a separate ans matrix.
// Copy: ans[j][i] = matrix[i][j]
