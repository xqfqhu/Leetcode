'''
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
'''
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int first_row_flag = 0;
        int first_col_flag = 0;
        for (int i = 0; i < m; i++){
            if (matrix[i][0] == 0) first_col_flag = 1;
        }
        
        for (int j = 0; j < n; j++){
            if (matrix[0][j] == 0) first_row_flag = 1;
        }
        
       
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++){
            if (matrix[i][0] == 0) {

                for (int j = 1; j < n; j++) matrix[i][j] = 0;
            }
        }
        
        for (int j = 1; j < n; j++){
            if (matrix[0][j] == 0){

                for (int i = 1; i < m; i++) matrix[i][j] = 0;
            }
        }
        
        if (first_row_flag){
            for (int j = 0; j < n; j++) matrix[0][j] = 0; 
        }
        
        if (first_col_flag){
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};

'''
this is an array - in place manipulation problem
the naive solution is to zero set rows and cols while traversing
however, this will influence the values you have not visited
our solution is to use the first row and col as flag and use two extra variables to indicate whether we want to zero set the first col and row
'''