'''
Given an array of integers heights representing the bar height of the histogram where the width of each bar is 1, return the area of the largest rectangle in the histogram.
'''
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> candidateHeightIdx = {-1};
        for (int i = 0; i < n; i++){
            int curCandidateHeightIdx = candidateHeightIdx.back();
            
            
            
            if (curCandidateHeightIdx == -1 ||
                heights[curCandidateHeightIdx] <= heights[i]){
                candidateHeightIdx.push_back(i);
                continue;
            }
            while (curCandidateHeightIdx != -1 &&
                   heights[curCandidateHeightIdx] > heights[i]){
                candidateHeightIdx.pop_back();
                int candidateMaxArea = heights[curCandidateHeightIdx] * (i - candidateHeightIdx.back() - 1);
                if (candidateMaxArea > maxArea) maxArea = candidateMaxArea;
                
                curCandidateHeightIdx = candidateHeightIdx.back();
            }
            candidateHeightIdx.push_back(i);
        }
        
        for (int i = candidateHeightIdx.size() - 1; i > 0; i--){
            
            int candidateMaxArea = heights[candidateHeightIdx[i]] *
                (candidateHeightIdx.back() - candidateHeightIdx[i - 1]);
            if (candidateMaxArea > maxArea) maxArea = candidateMaxArea;
        }
        return maxArea;
    }
    
    
};


'''
This is a combination problem
normally, we would have to try every bar pair combination to find the optimial one (O(n**2) time)
however, the largest possible rectangle has to have a height equal to one of the elements of the array, and the length of the array is n
thus, there are n possible largest rectangles
that is to say, we can decrease time complexity to O(n) by searching by the height of the rectangle
Note that this problem is thinking process is exactly same as the MaxSumContiguousSubset.cpp problem
Unlike in MaxSumContiguousSubset.cpp problem where previous elems no longer matter once we have visited them
some previous elems, namely those candidate bars, matter after we visited them
thus, we would want to store them in some data structure and pop when necessary
in terms of the data structure, there are often 2 options: stack or queue
since only contiguous elems can form a bar pair, we would like a FILO structure, or namely stack
'''