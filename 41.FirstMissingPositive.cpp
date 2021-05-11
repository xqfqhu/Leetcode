'''
Given an unsorted integer array nums, find the smallest missing positive integer.
runs in O(n) time and uses constant extra space
'''
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
            
        }
        
        for (int i = 0; i < n; i++){
            
            if (nums[i] > 0 && nums[i] < n + 1){
                if (nums[nums[i] - 1] > 0) nums[nums[i] - 1] = - nums[nums[i] - 1];
            }
            else if (nums[i] < 0 && nums[i] > - n - 1){
                if (nums[-nums[i] - 1] > 0) nums[-nums[i] - 1] = - nums[-nums[i] - 1];
            }
        }
        
        for (int i = 0; i < n; i++){
            
            if (nums[i] >= 0) return i + 1;
        }
        return n + 1;
    }
};

'''
this is a "search" problem. we should sort the array first and then do search
bottleneck 1: ordinary search algorithm takes at least O(nlogn)
solution: sinec nums is an integer array, we can do integer sort which takes O(n)

bottleneck 2: integer sort takes O(n) space
solution: we want to do an in-place integer sort. 
          The key observation is that the smallest missing elem falls int then range [1, len(nums)+1]
          the implication is that we only have to sort the smallest len(nums) elem
          thus we can do it in-place

bottleneck 3: doing integer sort in place destroy the original nums
solution: we want to mark the existance of i without destroy the value of nums[i]
          one obvious way to do that is to let nums[i] -> -abs(nums[i]) if i exists
          fortunately, those values in nums that are originally negative are not important, so we can change them to some out of range value beforehand
'''