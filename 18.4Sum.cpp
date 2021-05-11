'''
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
'''


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        int n = nums.size();
        vector<vector<int> > res;
        if (n < 4) return res;
        std:sort(nums.begin(), nums.end());
        
        for (int p1 = 0; p1 < n - 3; p1++){
            if (p1 != 0 && nums[p1] == nums[p1-1]) continue;
            int target_3 = target - nums[p1];
            if (target_3 < nums[p1] && nums[p1] >= 0) break;
            for (int p2 = p1 + 1; p2 < n - 2; p2++){
                if (p2 != p1 + 1 && nums[p2] == nums[p2-1]) continue;
                int target_2 = target_3 - nums[p2];
                if (target_2 < nums[p2] && nums[p2] >= 0) break;
                int front = p2 + 1;
                int rear = n-1;
                
                while (front < rear){
                    int sum_2 = nums[front] + nums[rear];
                    if (sum_2 < target_2) front++;
                    else if (sum_2 > target_2) rear--;
                    else{
                        vector<int> quad = {nums[p1], nums[p2], nums[front], nums[rear]};
                        res.push_back(quad);
                        front++;
                        rear--;
                        while (front < rear && nums[front] == quad[2]) front++;
                        if (nums[front] == quad[3]) break;
                        while (front < rear && nums[rear] == quad[3]) rear--;
                    }
                }
            }
        }
        return res;
    }
};


'''
this is a combination problem
normally, we will have to use exhaustive recursion + backtracing + BFS/DFS to solve the problem
however, since the number of elems in the combination is fixed, once we fix n-2 elems, binary search can help us search faster
we solve order 2 fixed number combination problem using binary search, but how should we generalize the method to order 4 array problem?
we set one elem fixed to downgrade it to order 3 array problem
we set another elem fixed to downgrade it to order 2 array problem
note that we prune under certain conditions to make the algorithm faster 
'''