class Solution {
'''
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
'''

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsHash;
        int n = nums.size();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++){
            numsHash.insert(nums[i]);
        }
        
        for (int i = 0; i < n; i++){
            if (numsHash.find(nums[i] - 1) != numsHash.end()) continue;
            if (numsHash.find(nums[i]) != numsHash.end()){
                int curLen = 1;
                int num = nums[i] + 1;
                while (1){
                    if (numsHash.find(num) == numsHash.end()) break;
                    curLen++;
                    num++;
                }
                maxLen = max(curLen, maxLen);
            }
        }
        return maxLen;
    }
};

'''
This is a hash problem

the brute force solution is that for each nums[i], check whether nums[i], nums[i] + 1, nums[i] + 2,... is in nums
This solution takes O(n ** 3)

one obvious optimization is to sort nums first and then find the res
if we use ordinary sort algorithm, it takes O(nlogn)
if we use integer sort, it takes too much space if nums[i] is too scattered

going back to the brute force solution, can we optimize this solution?
    1. we want to check whether nums[i] + k is in nums fast --> use hashset
    2. we want to check whether nums[i] + k is in nums for as few i as possible --> we only check if nums[i] is the first of a longest consecutive elements sequence
'''