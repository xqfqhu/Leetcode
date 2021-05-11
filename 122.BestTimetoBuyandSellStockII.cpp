'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
'''

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, n = prices.size();
        
        for (int i = 1; i < n; i++){
            maxProfit += max(0, prices[i] - prices[i - 1]);
        }
        
        return maxProfit;
    }
};

'''
this is a array - combination - contiguous subarray problem
if the array is a monotone sequence, the best strategy is to buy on the first day and sell on the last day if price[-1] > price[0]
this can be decomposed as sum(price[i]-price[i-1])
if the array is not monotone, the best strategy is to buy at valley and sell at peak
this can also be decomposed as sum(price[i]-price[i-1])
'''