'''
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
'''

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rear = nums.size() - 1;
        int mid = rear / 2;
        int front = 0;
        
        while (1){
            if (nums[front] == target) return front;
            else if (nums[rear] == target) return rear;
            else if (nums[mid] == target) return mid;
            else if (front == mid || mid == rear) return -1;
            else if (((nums[front] < nums[mid]) && 
                     (target > nums[front]) && 
                     (target < nums[mid])) ||
                     ((nums[front] > nums[mid]) &&
                     ((target < nums[mid]) || (target > nums[front]))
                    )){
                rear = mid - 1;
                mid = (front + rear) / 2;
            }
            else{
                front = mid + 1;
                mid = (front + rear) / 2;
            }
        }
    }
};

'''
this is a "search in sorted array" problem. Thus we should use binary search
what distinguish this problem from classic "search in sorted array" problem is that the sorted array is rotated
thus the conditions where we narrow the scope down to left/right half should be slightly different
'''