
'''
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

'''

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std:sort(candidates.begin(), candidates.end());
        vector<vector<int> >res;
        vector<int> combination;
        
        helper(candidates, target, 0, candidates.size()-1, combination, res);
        return res;
    }
    
    
    void helper(vector<int> & candidates, int target, int front, int rear, vector<int> &combination, vector<vector<int> > &res){
        if (target == 0){
            res.push_back(combination);
            return;
        }
        for (int i = front; i <= rear; i++){
            
            if (candidates[i] <= target){
                combination.push_back(candidates[i]);
                helper(candidates, target-candidates[i], i, rear, combination, res);
                combination.pop_back();
                
                
            }
            else if (candidates[i] > target) {
                break;
            }
        }
    }
};

'''
this is a "combination with unknown number of elems" problem
it is a generalization of "combination with known number of elems" problem
unlike in "combination with fixed number of elems" problem where you can downgrade the problem to binary search problem by fixing one position at a time
since the number of elems in the output combination is unknown, you cannot fix n elems and write n for loops manually
you will have to use exhaustive recursion + backtracing
Note that presorting helps early ending
'''