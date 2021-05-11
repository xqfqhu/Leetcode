'''
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
'''
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std:sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<vector<int> > res;
        vector<int> cur = intervals[0];
        
        for (int i = 1; i < n; i++){
            
            if (intervals[i][0] <= cur[1]) {
                if (intervals[i][1] >= cur[1]) cur[1] = intervals[i][1];
            }
            else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
private:
    struct{
    bool operator() (vector<int> &a, vector<int> & b) const {return a[0] < b[0];}
} cmp;
};

'''
this is a "array-search-removing redundancy problem"
sort the input and then remove
Note how you sort vector of vectors
'''