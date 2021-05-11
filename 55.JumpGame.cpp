'''
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
'''

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size() - 1;
        for (int i = 0; i <= reach; i++){
            if (i > reach) return false;
            int reach_local = i + nums[i];
            if (reach_local > reach) reach = reach_local;
            if (reach >= n) return true;
        }
        return false;
    }
    
    
};

'''
this is a combination problem which asks you to find any combination that meet certain criteria
normally, you will have to use DFS to solve the problem
however, in this specific problem, pruning earlier allows you to generate O(n) solution
'''