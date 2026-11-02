//Brute force aPPROACH
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>>rotated(n,vector<int>(n,0));

//         for(int i =0; i<n;i++){
//             for(int j =0;j<n;j++){
//                 rotated[j][n-i-1] = matrix[i][j];
//             }
//         }
//         matrix = rotated;
        
//     }
// };

/*
Complexity
Time: O(n²)
Space: O(n²)
*/

//aPPROACH 2:
//oPTIMAL aPPROACH(Optimal In-Place (Transpose + Reverse)


/*
Idea
Transpose matrix
Reverse each row
*/




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();


        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        } 
           

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }                          
    }
};


/*
Complexity
Time: O(n²)
Space: O(1) ✅
*/


/*
// Learning:
// In-place transpose → swap only upper triangle (j = i+1).
// This avoids swapping the same pair twice.
// Then reverse every row → 90° clockwise rotation.

// Time: O(n²)
// Space: O(1)
*/