'''
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
'''
class Solution1 {
public:
    int jump(vector<int>& nums) {
        queue<int> nodes;
        nodes.push(0);
        int max_pos = nums.size() - 1;
        int level = 0;
        int prev_max = 0;
        int num_node = 1;
        if (nums.size() == 1) return 0;
        
        while (1) {
            level++;
                
            if(traverse_level(nums, max_pos, nodes, prev_max, num_node)) return level;        
        }
        
        
        
    }
    
    int traverse_level(vector<int> &nums, int max_pos, queue<int> &nodes, int &prev_max, int & num_node){

        int new_num_node = 0;
        while (num_node != 0){
            int cur = nodes.front();

            int new_max_pos = nums[cur] + cur;

            if (new_max_pos >= max_pos) return 1;
            

            for (int new_pos = prev_max + 1; new_pos <= new_max_pos; new_pos++){
                
                nodes.push(new_pos);
                new_num_node++;

                    
            }
            if (new_max_pos > prev_max) prev_max = new_max_pos;
            nodes.pop();
            num_node--;
        }

        num_node = new_num_node;

        return 0;
    }
    
};

class Solution2 {
public:
    int jump(vector<int>& nums) {
        int max_pos = nums.size() - 1;
        int level = 0;
        int prev_max = 0;
        int prev_min = 0;
        if (nums.size() == 1) return 0;
        
        while (1) {
            level++;
            if(traverse_level(nums, max_pos, prev_min, prev_max)) return level;        
        }
    }
    
    int traverse_level(vector<int> &nums, int max_pos, int &prev_min, int &prev_max){
        int new_prev_max = prev_max;
        for (int cur = prev_min; cur <=prev_max; cur++){
            if (nums[cur] + cur >= max_pos) return 1;
            else if (nums[cur] + cur > new_prev_max) new_prev_max = nums[cur] + cur;
        }
        prev_min = prev_max + 1;
        prev_max = new_prev_max;

        return 0;
    }
    
};

'''
This is a combination problm which asks you to find the shortest fisible combination
normally, you will have to use exhaustive recursion + prune + BFS, which requires O(n) space
the challenge is to optimize your toy algorithm in terms of space and time
In this problem, pruning the tree a little bit can yield O(n) solution
the real challenge is to decrease space usage to O(1)
the key observation is that the integers you push into the queue in each level form a contiguous range
thus, rather than store the queue itself, you can just store the beginning and end of this sequence
'''
