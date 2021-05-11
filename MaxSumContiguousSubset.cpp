/* 
 * https://see.stanford.edu/Course/CS106B HW5-Q5: Suppose that you have a Vector of integers and you would like to find the maximum sum 
 * of any its subvectors (a subvector is some contiguous set of numbers in the Vector). That
 * is, you want to figure out what is the maximum sum you can get using a sequence of
 * consecutive numbers from the Vector. Note that since the numbers can be positive or
 * negative, this is not simply the entire Vector. For example, if the Vector contained [2, -5,
 * 12, 9, -3, 10], the largest sum is found in the subvector [12, 9, -3, 10] for a total sum of
 * 28
 */ 

/* Algorithm 1: easy solution */

int FindMax(vector<int> v){
    int GlobalMax = 0;
    for(int i == 0; i < v.size(); i++){ // O(n)
        int MaxCurStart = 0;
        int sumCurStart = 0;
        for(int j == i; j < v.size(); j++){ //O(n)
            sumCurStart += v[j];
            if(sumCurStart >= MaxCurStart) MaxCurStart = sumCurStart;
        }
        if(MaxCurStart >= GlobalMax) GlobalMax = MaxCurStart;
    }
    return GlobalMax;
}

/*
 * complexity = O(n**2)
 * this solution involves many repeated computations
 * for example, (-5) + 12 is used by both 2 + (-5) + 12 and (-5) + 12 + 9
 * thus, we would like to store the results of these repeated computation, i.e. using dynamic programming
 */

/* Algorithm 2: dp solution */
int FindMax(vector<int> v){
    int n = v.size();
    vector<int> dp(n, 0);
    dp[0] = v[0];
    int maxSum = dp[0];
    for (int i = 1; i < n; i++){
        dp[i] = v[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

/*
 * time complexity: O(n)
 * space complexity: O(n)
 * we have achieved the min time complexity, but could improve space complexity further
 * we can notice that the only variable we should store is actually dp[i - 1]
 */

/* Algorithm 3: aim: decrease space complexity to O(1)*/


int FindMax(vector<int> v){
    int GlobalMax = v[0];
    int maxSoFar = v[0];
    for(int i = 1; i< v.size(); i++){
        maxSoFar = max(0, maxSoFar) + v[i];
        GlobalMax = max(maxSoFar, GlobalMax);
        
    }
    return GlobalMax;
}

/* Algorithm 4: aim: decrease the number of candidate starting points tried by using divide-and-conquer approach --> O(nlogn) */

/*
 * after we divide a vector into halves, the max sum is either:
 *  1. sum of some subvector in the left half
 *  2. sum of some subvector in the right half
 *  3. sum of some subvector that crosses the border
 * Then we return max(left,right,cross)
 * 
 * The first two possiblities can be handled with recursion. We just call findMax(left) and findMax(right)
 * the problem becomes how to find "cross" with at most O(n)(because we're aiming for O(nlogn) in total)
 * Notice that O(n) is exactly the complexity required to solve the problem if we know the right starting point
 * Do we know the starting point of a subvector that crosses the border?
 * The answer is yes. It's simply the border
 * We find the subvector with the max sum starting from the border to the left and the subvector with the max sum starting from the border to the right
 * then we take the sum of these two max, resulting in the max sum of some subvector that corsses the border
 * 
 *  the next question is the base case
 * if there is no element in the vector, we'd like to return 0
 * if there is one element in the vector, we'd like to return max(0,v[0])
 */



/* Similar problem 1: leetcode 11 */
/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
 * Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
 */

/* Algorithm 1: easy solution */
/* 
 * brute force solution is straight forward, taking O(n**2)
 * 
 * The bottleneck of this solution is that we don't know where the right starting point is
 */

/* Algorithm 2: easy solution */
 
 /* generalization about continuous subvector problem */
/* 
 * contiguous subvector problems are about finding the right head and tail. So you should follow these steps to design to solution:
 *  1. decide where to initialize head and tail. Do you want to initialize them at the end/start/middle of the vector? one at the front and one at the end?
 *  2. decide whether to store both head and tail. Sometimes the position of head/tail is implied by other member data so that you don't have to store it explicitly. For example in the first question, the position of the start pointer is implied by the localSum
 *  3. decide how to control the movement of the head and tail. under what circumstances should you increment/decrement your head/tail? by how much? be careful not to miss any potential answer
 *  4. decide when to stop. very often you stop when head/tail hits the end of the vector or when they cross
 *  5. update max/min in the process of moving head/tail
 */ 