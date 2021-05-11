'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
'''
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(3, vector<int> (n, 0));
        for (int i = 1; i < n; i++){
            for (int k = 1; k <= 2; k++){
                int minV = prices[0];
                for (int j = 1; j < i; j++ ){
                    minV = min(minV, prices[j] - dp[k - 1][j]);
                }
                dp[k][i] = max(dp[k][i - 1], prices[i] - minV);
            }
        }
        return dp[2][n-1];
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(3, vector<int> (n, 0));
        vector<int> minV(2, prices[0]);

        for (int i = 1; i < n; i++){
            for (int k = 1; k <= 2; k++){
                minV[k - 1] = min(minV[k-1], prices[i] - dp[k - 1][i]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - minV[k-1]);
                
            }
        }
        return dp[2][n - 1];
    }
};


class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3, 0);
        
        
        
        vector<int> minV(2, prices[0]);
        for (int i = 1; i < n; i++){
            for (int k = 1; k <= 2; k++){
                minV[k - 1] = min(minV[k-1], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - minV[k-1]);
                
            }
        }
        return dp[2];
    }
};


class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp1 = 0, dp2 = 0, minV1 = prices[0], minV2 = prices[0];

        
        for (int i = 1; i < n; i++){
            
            
            minV1 = min(minV1, prices[i]);
            minV2 = min(minV2, prices[i] - dp1);
            dp1 = max(dp1, prices[i] - minV1);
            dp2 = max(dp2, prices[i] - minV2);

        }
        return dp2;
    }
};
'''
the naive solution is to explore all choices: if we have not bought any stock, we either buy it or skip it. if we have bought a stock, we either sell it or skip it
this solution involves many repeated computations
for example, buy at time stamp 2 and sell at time stamp 3 is computed when it is the first and second transaction
we want to use dynamic programming to save these results

the dp formula is as follows:
dp[k][i] = max(dp[k][i - 1], dp[k - 1][j] + prices[i] - min (prices[j])) for j = 1,...,i-1
dp[k][i] represents the maximum profit with k transactions at day i
we can write Solution1 based on this formula


To avoid repeatedly computing minV, we can store minV, which leads to Solution2

Notice that only dp[k - 1][i - 1] is needed, so we can decrease space usage to O(1), which leads to Solution3

by expanding the for loop for k and use integers rather than vector, we further optimize the code, which leads to Solution4
'''