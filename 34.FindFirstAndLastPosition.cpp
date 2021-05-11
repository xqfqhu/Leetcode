'''
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
'''

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int front = 0;
        int rear = nums.size() - 1;
        if (rear < 0) return res;
        int mid = (front + rear) / 2;
        
        
        while (1){
            if (front == mid || rear == mid){
                if (nums[front] == target){
                    res[0] = front;
                    break;
                }
                else if (nums[rear] == target){
                    res[0] = rear;
                    break;
                }
                else return res;
            }
            else if (nums[mid] >= target){
                rear = mid;
                mid = (front + rear) / 2;
            }
            else {
                front = mid + 1;
                mid = (front + rear) / 2;
            }
        }
            
        
        front = 0;
        rear = nums.size() - 1;
        mid = (front + rear) / 2;
        
        while (1){
            if (front == mid || rear == mid){
                if (nums[rear] == target){
                    res[1] = rear;
                    return res;
                }
                else if (nums[front] == target){
                    res[1] = front;
                    return res;
                }
                else exit(1);
            }
            else if (nums[mid] > target){
                rear = mid - 1;
                mid = (front + rear) / 2;
            }
            else {
                front = mid;
                mid = (front + rear) / 2;
            }
            
        }
    }
};


'''
this is a "search in sorted array" problem. Thus we should use binary search.
since we are searching for two positions, i.e. first and last position of an elem, we should do binary search twice.
usually, having rear = mid - 1 and front = rear + 1 allows us to decrease range faster
however, in this case, in order to have rear = mid - 1 and front = rear + 1, we will have more branches
in particular, if (nums[mid] > target) and if (nums[mid] == target) will behave differently
having more branches is really slow
thus, having rear = mid and front = rear is more efficient in this case
'''