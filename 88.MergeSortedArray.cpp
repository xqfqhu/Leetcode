'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
'''

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int p1 = m - 1;
        int p2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--){
            if ((p1 >= 0) && (p2 < 0 || nums1[p1] >= nums2[p2])){

                nums1[i] = nums1[p1];
                p1--;
            }
            else{
               
                nums1[i] = nums2[p2];
                p2--;
            }
        }
        return;
    }
};

'''
this is a sort - merge sorted lists problem
we can do it using O(n) space by traversing the lists forwards
to do it using O(1) space, we should traverse backwards
'''