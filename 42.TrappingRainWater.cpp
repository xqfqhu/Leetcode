'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
'''
class Solution1 {
public:
    int trap(vector<int>& height) {
        int l = 0;
        vector<int> r;
        int n = height.size();
        int res = 0;
        
        for (int i = n - 1; i >= 0; i--){
            if (r.size() == 0 || height[i] > r.back()) r.push_back(height[i]);
            else r.push_back(r.back());
        }
        
        for (int i = 0; i < n; i++){
            int tmp = r.back();
            (height[i] > l)? l = height[i] : l = l;
            (l > tmp)? res += (tmp - height[i]) : res += (l - height[i]);
            r.pop_back();
        }
        return res;
    }
};


class Solution2 {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int res;
        
        while (left < right){
            if (height[left] < height[right]){
                (height[left] > leftMax)? leftMax = height[left] : leftMax = leftMax;
                res += (leftMax - height[left]);
                left++;
            }
            else{
                (height[right] > rightMax)? rightMax = height[right] : rightMax = rightMax;
                res += (rightMax - height[right]);
                right--;
            }
        }
        return res;
    }
};

'''
the obvious solution is solution1
more particularly:
area = sum((min(leftMax[i], rightMax[i]) - height[i]))

this solution takes O(2n) time (which is not bad) and O(n) space (which is bad)
so our goal is to decrease space usage
since we do not want to store reightMax, we will have to have another pointer which starts from right
when we start from the left, we know leftMax[left] for height[left] and when we start from the right, we know rightMax[right] for height[right]
area_i = leftMax[left] - height[left] if height[left] < height[right]
         rightMax[right] - height[right] if height[right] < height[left]
because if the height of a bar is higher than any bar right to it, the water it traps is constrained by the height of itself and leftMax
if the height of a bar is higher than any bar left to it, the water it traps is constrained by the height of itself and rightMax
'''