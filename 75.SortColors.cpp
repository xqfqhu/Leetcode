'''
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
'''
class Solution_DutchNationalFlag {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero_p = 0;
        int one_p = 0;
        int two_p = n - 1;
        while (one_p <= two_p){
            if (nums[one_p] == 0){
                swap(nums[zero_p], nums[one_p]);
                zero_p++;
                one_p++;
            }
            else if (nums[one_p] == 1) one_p++;
            else {
                swap(nums[one_p], nums[two_p]);
                two_p--;
            }
        }
        
    }
    
};

class Solution_integerSort {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++){

            count[nums[i]]++;
        }
        
        int cur = 0;
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < count[i]; j++){
                nums[cur] = i;
                cur++;
            }
        }
        
    }
    
};

'''
this is a sort problem
we can do it using an ordinary sort algorithm or integer sort algorithm
integer sort algorithm requires 2 way traversal

in terms of ordinary sort algorithm, since we are required to sort in-place, we should consider quicksort
however, ordinary quicksort performs poorly if there are many repeated elems
the revised 3-way quicksort algorithm should be chosen
in this specific problem, since there are only three kinds of elems, no recursion is required, i.e. only Dutch National Flag algorithm is required
'''
