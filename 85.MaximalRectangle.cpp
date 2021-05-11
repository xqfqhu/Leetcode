'''
Given a rows x cols binary matrix filled with  and 1s, find the largest rectangle containing only 1s and return its area
'''

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;
        vector<int> height = {-1};
        vector<int> height_value(n ,0);
        
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1') height_value[j]++;
                else height_value[j] = 0;
                
                int right = height.back();
                while (height.back() != -1 && 
                    height_value[j] <= height_value[height.back()]){
                    int curHeight = height_value[height.back()];
                    height.pop_back();
                    int size = curHeight * (right - height.back());
                    
                    if (size > res) res = size;
                }
                height.push_back(j);
                
            }
            for (int i = 1; i < height.size(); i++){
                int size = height_value[height[i]] * (height.back() - height[i-1]);
                if (size > res) res = size;
                
            }
            height = {-1};
        }
        
        return res;
    }

};

'''
this is a combination problem
One obvious solution is to try each height pair, which takes O(h**2) if there are h heights
however, since there are at most h height pair combinations, we can decrease time complexity to O(h)
the key is to store candidate height in a stack
'''