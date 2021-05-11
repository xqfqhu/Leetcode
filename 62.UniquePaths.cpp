'''
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
'''

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<int> right_mem(m-1, 1);
        for (int i = 0; i < n - 1; i++){
            int down = 1;
            for (int j = 0; j < m - 1; j++){
                down += right_mem[j];
                right_mem[j] = down;
            }
        }
        return right_mem[m-2];
    }
};

'''
the first key observation is that the number of unique paths from point a to the destination = # unique paths from the point right to it to the destination + # unique paths from the point below it to the destination
so we can solve this problem recursively
the second key observation is that there are many repeated calculations if we use plain recursion
for example, we will have to calculate the value in orange in order to calcultae the value in green and blue ![picture 2](images/9a05572422d60b89faddffe2f1a595f19a365750860e4a5b4638a55e8d647f77.png)  
thus we want to use dynamic programming
we might do dynamic programming recursively or bottom up
bottom up is both easy to write and easy to optimize space usage
'''