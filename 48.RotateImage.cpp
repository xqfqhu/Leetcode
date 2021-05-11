'''
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
'''
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int half = n / 2;
        int i, j;
        for (i = 0; i < half; i++){
            int new_col = n - 1 - i;
            for (j = 0; j <  n - i - 1; j++){
                swap(matrix[i][j], matrix[j][new_col]);
            }
        }
        
        for (i = half; i < n - 1; i++){
            int new_col = n - 1 - i;
            for (j = 0; j < i + 1; j++){
                swap(matrix[i][j], matrix[j][new_col]);
            }
        }
        
        for (j = 0; j < n; j++){
            swap(matrix[n-1][j], matrix[j][0]);
        }
    }
private:
    void swap(int & a, int & b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};





'''
this is an in-place rotation problem
the solution is to swap appropriate elems
the challenge is to decide when to skip swapping
use example to help you decide
for this particular problem, this image really helps:
![picture 1](images/fb3a7b7fca5df5d5c2d08d2e8f14e8df44e19fb6504f3e12724f35c89681d211.png)  
'''