'''
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
'''
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std:sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int> > res;
        
        helper(candidates, target, 0, candidates.size()-1, combination, res);
        return res;
    }

    
    void helper(vector<int> & candidates, int target, int front, 
                int rear, vector<int> &combination, vector<vector<int> > &res){

        if (front > rear+1) {
            return;
        }
        if (target == 0){
            res.push_back(combination);

            return;
            }
        for (int i = front; i <= rear; i++){
            
            if (candidates[i] <= target){
                
                
                if (i > front && candidates[i] == candidates[i-1]) continue; // 2. skip duplicates
                combination.push_back(candidates[i]);

                helper(candidates, target - candidates[i], i+1, rear, combination, res); // 1. each number in candidates may only be used once in the combination

                combination.pop_back();
                }
            else return;
            }
        }
};

'''
this is a "combination with unknown number of elems" problem
so we should use backtracing
there are two challenges in this problem:
    1. each number in candidates may only be used once in the combination
    2. the solution set must not contain duplicates while the candidates contain duplicates
the first challenge is easy to solve: just increment front when entering the recursion
the second challenge is harder to solve. here is an example:
candidates:    1 2 2 2 5
combination 1: 1 2 2
combination 2: 1   2 2 -->duplicate
"front" in both combination is 1, but i is 1 in combination 1 while i is 2 in combination 2. thus there is a dplicate
in other words, we should not choose any duplicate in the same subcandidates
'''