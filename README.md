# Leetcode problem classification
## Sort according to method used
<ul>
    <li> Array
        <ul>
            <li>Sort
                <ul>
                    <li>Integer sort
                        <ul>
                            <li>O(1) space usage: in-place integer sort <a hef="./41.FirstMissingPositive.cpp">#41</a>
                            </li>
                            <li><a hef="./75.SortColors.cpp">#75</a>
                            </li>
                        </ul>
                    </li>
                    <li>Ordinary sort
                        <ul>
                            <li>in-place: quicksort
                                <ul>
                                    <li>many repeated elements: 3-way quicksort/dutch national flag problem: <a hef="./75.SortColors.cpp">#75</a>
                                    </li>
                                </ul>
                            </li>
                            <li>offline: mergesort
                            </li>
                        </ul>
                    </li>
                    <li>Special case: merge sorted list
                        <li>in-place: <a hef="./88.MergeSortedArray.cpp">#88</a>
                        </li>
                    </li>
                </ul>
            </li>
            <li>Search
                <ul>
                    <li>reorder possible: sort (+ binary search). Note: for binary search having rear = mid - 1 and front = rear + 1 is usually the fastest. However, if doing so require more branches, having mid = rear and mid = front might be better
                        <ul>
                            <li>revised conditions: <a hef="./33.SearchInRotatedSortedArray.cpp">#33</a>
                            </li>
                            <li>multiple binary search: <a hef="./34.FindFirstAndLastPosition.cpp">#34</a>
                            </li>
                            <li>remove redundancy: <a hef="./56.MergeIntervals.cpp">#56</a>
                            </li>
                        </ul>    
                    </li>
                    <li>reorder impossible
                        <ul>
                            <li>search for local maximum/minimum of n subvectors with O(1) space: n pointers traverse from the beginning of each subvector
                                <ul>
                                    <li><a hef="./42.TrappingRainWater.cpp">#42</a>
                                    </li>
                                </ul>
                            </li>
                        </ul>
                    </li>
                </ul>
            </li>
            <li>Combination
                <ul>
                    <li>General case: exhaustive recursion + backtracing. presorting can usually help pruning if order does not matter
                        <ul>
                            <li>Find all/any combinations that meet certain criteria: DFS
                                <ul>
                                    <li><a hef = "./78.Subsets.cpp">#78</a>
                                    </li>
                                    <li>distinct candidates + used multiple times -> unique combinations <a hef = "./39.CombinationSum.cpp">#39</a>
                                    </li>
                                    <li>candidates + used once -> unique combinations <a hef = "./40.CombinationSum2.cpp">#40</a>: deal with duplicates
                                    </li>
                                    <li>prune to achieve O(n) time: <a hef = "./55.JumpGame.cpp">#55</a>
                                    </li>
                                </ul>
                            </li>
                            <li>Find shortest combination that meet certain criteria: BFS (O(n) space usage)
                                <ul>
                                    <li>optimize algorithm to achieve O(1) space usage by storing max and min of a queue rather than the queue itself: <a hef = "./45.JumpGameII.cpp">#45</a>
                                    </li>
                                    <li><a hef = "./126.WordLadderII">#126</a>
                                    </li>
                                </ul>
                            </li>
                        </ul>
                    </li>
                    <li>Special case - Combination with fixed number of elems: sort the vector, use binary search to solve order 2 problem, prune if certain condition is not met. if problem order n > 2, set 1 elem fixed to downgrade the problem to n-1 order, O(n ** (subvector.size() - 1))
                        <ul>
                            <li><a hef = "./16.threeSumClosest.cpp">#16</a>
                            </li>
                            <li><a hef = "./18.4Sum.cpp">#18</a>
                            </li>
                        </ul>
                    </li>
                </ul>
            </li>
            <li>Permutation: usually, you'll have to use exhaustive recursion + backtracing. However, if the output permutation is supposed to be very similar to the input permutation, you can just swap certain elem of the input permutation
                <ul>
                    <li>slightly modify the original permutation by resorting: <a hef = "./31.nextPermutation.cpp">#31</a>
                    </li>
                </ul>
            </li>
            <li>In-place manipulation: to avoid influencing the value you have not visited yet, store important values using extra memory or skip when necessary
                <ul>
                    <li>in-place rotation: swap, skip swapping when necessary: <a hef = "./48.RotateImage.cpp">#48</a>
                    </li>
                    <li>in-place zeroing: store using extra space. Note how to decrease space usage: <a hef = "./73.SetMatrixZeroes.cpp">#73</a>
                    </li>
                </ul>
            </li>
        </ul>
    </li>
    <li>Dynamic programming: Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. memoize result. Note that you should also optimize memory usage
        <ul>
            <li><a hef = "./62.UniquePaths.cpp">#62</a>
            </li>
            <li><a hef="./MaxSumContiguousSubset.cpp">MaxSumContiguousSubset</a>
            </li>
            <li><a hef="./122.BestTimetoBuyandSellStockII.cpp"> #122 </a>
            </li>
            <li><a hef="./123.BestTimetoBuyandSellStockIII.cpp"> #123 </a>
            </li>
        </ul>
    </li>
    <li>Tree
        <ul>
            <li>construct tree: construct recursively or iteratively with stack: <a hef="./105.ConstructBinaryTreefromPreorderandInorderTraversal.cpp"> #105 </a>
            </li>
        </ul>
    </li>
    <li>Stack
        <ul>
            <li>use stack as a buffer to delay manipulation
                <ul>
                    <li><a hef="./84.LargestRectangleInHistogram.cpp"> #84 </a>
                    </li>
                    <li><a hef="./85.MaximalRectangle.cpp"> #85 </a>
                    </li>
                </ul>
            </li>
            <li>use stack to "undo"
                <ul>
                    <li><a hef="./105.ConstructBinaryTreefromPreorderandInorderTraversal.cpp"> #105 </a>
                    </li>
                </ul>
            </li>
        </ul>
    </li>
    <li>Hash
        <ul>
            <li>use hash set to check whether an elem is in a set
                <ul>
                    <li><a hef="./128.LongestConsecutiveSequence.cpp"> #128 </a>
                    </li>
                </ul>
            </li>
        </ul>
    </li>
</ul>