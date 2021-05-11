/* 
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */

/* 
 * this is a combination problem
 * normally, you'll have to use exhaustive recursion + backtracing + BFS/DFS to solve the problem
 * However, since the number of elems is fixed, once we fix n-2 elem in the combination, we can use binary search to find the last 2 elems, and the candidate last 2 elems we found can inform our search for the first n-2 elems
 * follow these steps to construct a solution:
 *  1. decide how many pointers you want use. #pointers + #fix = subvector.size(). 
 *  2. decide how to control the movement of the pointers
 *  3. find a combination of step 1 and 2 that has the least complexity
 *  4. decide when to stop
 *  5. update max/ min in the process
 */ 
#include <cmath> 
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int optimalDif = -1;
        int optimalSum = -1;
        for(int i = 0; i < nums.size()-2; i++){
            cout << "fix " <<i << endl;
            int head = i + 1;
            int tail = nums.size() - 1;
            while(true){
                if(optimalDif == 0) return optimalSum;
                if(head == tail) break;
                int newSum = nums[head] + nums[tail] + nums[i];
                bool MoreThanTarget = ((newSum - target) > 0);
                int newDif = abs(newSum - target);
                
                if(optimalDif == -1){
                    optimalDif = newDif;
                    optimalSum = newSum;
                }
            
                else if(optimalDif > newDif){
                    optimalDif = newDif;
                    optimalSum = newSum;
                }
                
                if(MoreThanTarget) tail--;
                else head++;
            }
        }
        return optimalSum;
    }


    int main(){
        vector<int> nums = {-1,2,1,-4};
        int result;
        result = threeSumClosest(nums, 1);
        cout << result << endl;
    }