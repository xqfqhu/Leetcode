class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int rear = nums.size() - 1;
        for (int pivot = rear - 1 ; pivot >= 0; pivot--){

            if (nums[pivot] >= nums[rear]){
                int pivot_sort = pivot;

                while (pivot_sort + 1 <= rear && nums[pivot_sort] > nums[pivot_sort + 1]){

                    int tmp = nums[pivot_sort];
                    nums[pivot_sort] = nums[pivot_sort + 1];
                    nums[pivot_sort + 1] = tmp;
                    pivot_sort++;
                }
            }
            else{
                int exchange = pivot + 1;
                while (exchange < rear && nums[exchange] <= nums[pivot]) exchange++;
                int tmp = nums[exchange];
                nums[exchange] = nums[pivot];
                nums[pivot] = tmp;
                break;
            }

        }
    }
};