
'''
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
'''
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int> > res;
        subsets_rec(nums, subset, res, 0, nums.size()-1);
        return res;
    }
    
    void subsets_rec(vector<int> & nums, vector<int> &subset, vector<vector<int> > &res,
                    int front, int rear){
        
        res.push_back(subset);
        
        for (int i = front; i <= rear; i++){
        
            subset.push_back(nums[i]);
            subsets_rec(nums, subset, res, i+1, rear);
            subset.pop_back();
        }
    }
};
'''
most basic combination problem, DFS
'''