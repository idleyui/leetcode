# interview problem 101

**toc**
- implement 101 algorithms & data structure
- binary search
- counting sort
- top k problem
- priority queue
- linked list
    - find mid
    - reverse
    - ...
- stack - next greater item
- tree - traversal (pre/in/post/level order)
- math
    - power
    - sqrt
    - conversion of number system
    - simulation (add / subtract / times / divide)
- dfs | bfs
    - permutation & combination problem
- graph
- dp 
    - lcs | lcs
    - edit distance
    - stock problems
    - knapsack problems
- greedy
    - merge interval
- design
- bit
    - power of two
    - xor

## 101 algorithms & data structure

- bubble sort
- select sort
- insert sort
- merge sort
- quick sort

## binary search

Integer binary search
- [33 search in rotated sorted array](solution/0033_Search_in_Rotated_Sorted_Array.cpp)
- [34 find first and last position of element in sorted array](solution/0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp)

float binary search
- [pow(x, n)](solution/0050_Powx_n.cpp)
- [sqrt(x)](solution/0069_Sqrtx.cpp)


## counting sort

- [75 sort colors](solution/0075_Sort_Colors.cpp)

## topk problem

Solution:
- just sort and get first k
- maintain a size K heap: stream data
- quick select: based on quick sort

- [973 K Closest Points to Origin](solution/0973_K_Closest_Points_to_Origin.cpp)
- [215 kth largest element in an array](solution/0215_Kth_Largest_Element_in_an_Array.cpp)

## priority queue

//todo

## linked list

basic operations
- [reverse linked list](solution/0206_Reverse_Linked_List.cpp)
- find k / find mid / delete k
- cycle
    - [141 linked list cycle](solution/0141_Linked_List_Cycle.cpp)
    - [142 linked list cycle II](solution/0142_Linked_List_Cycle_II.cpp)
- merge sorted list
    - [21 merge two sorted lists](solution/0021_Merge_Two_Sorted_Lists.cpp)
    - [23 merge k sorted lists](solution/0023_Merge_k_Sorted_Lists.cpp)

## stack

> https://leetcode.com/problems/next-greater-element-ii/discuss/98270/JavaC%2B%2BPython-Loop-Twice

next greater element
- [496 next greater element I](solution/0496_Next_Greater_Element_I.cpp)
- [503 next greater element II](solution/0503_Next_Greater_Element_II.cpp)
- [739 daily temperatures](solution/0739_Daily_Temperatures.cpp)

## tree

traversal
- [144 binary tree preorder traversal](solution/0144_Binary_Tree_Preorder_Traversal.cpp)
- [94 binary tree inorder traversal](solution/0094_Binary_Tree_Inorder_Traversal.cpp)
- [145 binary tree postorder_traversal](solution/0145_Binary_Tree_Postorder_Traversal.cpp)
- [102 binary tree level order traversal](solution/0102_Binary_Tree_Level_Order_Traversal.cpp)

## math



## dfs | bfs


### permutation ans combination

- [39 combination sum](solution/0039_Combination_Sum.cpp)
- [40 combination sum II](solution/0040_Combination_Sum_II.cpp)
- [77 combinations](solution/0077_Combinations.cpp)
- [46 permutations](solution/0046_Permutations.cpp)
- [47 permutations II](solution/0047_Permutations_II.cpp)
- [31 next permutation](solution/0031_Next_Permutaion.cpp)
- [556 next greater element III](solution/0556_Next_Greater_Element_III.cpp)

### backtrack

- top-down backtrack
> [A general approach to backtracking questions in Java (Subsets, Permutations, Combination Sum, Palindrome Partitioning)](https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-\(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning\))

- combination problem
- bottom up combination and filter by condition
- [401 binary watch](solution/0401_Binary_Watch.cpp)

use self matrix to log visit info
- [79 work search](solution/0079_Word_Search.cpp)

## graph

## two-pointers

https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers
- [3 longest substring without repeating characters](solution/0003_Longest_Substring_Without_Repeating_Characters.cpp)
- [763 partition labels](solution/0763_Partition_Labels.cpp)


## dp

### longest common substring
- [5 longest palindromic substring](solution/0005_Longest_Palindromic_Substring.cpp)

### longest common subsequence
- [1143 longest common subsequence](solution/1143_Longest_Common_Subsequence.cpp)
- [516 longest palindromic subsequence](solution/0516_Longest_Palindromic_Subsequence.cpp)

### 0-1 knapsack

- [322 coin change](solution/0322_Coin_Change.cpp)
- [518 coin change ii](solution/0518_Coin_Change_II.cpp)

### stock

- [best time to buy and sell stock](solution/0121_Best_Time_to_Buy_and_Sell_Stock.cpp)
- [best time to buy and sell stock ii](solution/0122_Best_Time_to_Bug_and_Sell_Stock_II.cpp)
- [best time to buy and sell stock iii](solution/0123_Best_Time_to_Buy_and_Sell_Stock_III.cpp)
- [best time to buy and sell stock iv](solution/0188_Best_Time_to_Buy_and_Sell_Stock_IV.cpp)
- [best time to buy and sell stock with cooldown](solution/0309_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp)
- [best time to buy and sell stock with transaction fee](solution/0714_Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee.cpp)
- [online stock span](solution/0901_Online_Stock_Span.cpp)

## greedy

merge interval
- [56 merge intervals](solution/0056_Merge_Intervals.cpp)
- [763 partition labels](solution/0763_Partition_Labels.cpp)

## design

- [146 LRU cache](solution/0146_LRU_Cache.cpp)
- [225 implement stack using queues](solution/0225_Implement_Stack_using_Queues.cpp)
- [232 implement queue using stacks](solution/0232_Implement_Queue_using_Stacks.cpp)
- [155 min stack](solution/0155_Min_Stack.cpp)

### math

- [441 arranging coins](solution/0441_Arranging_Coins.cpp)

#### power and sqrt

**basic**

calculate sqrt [367 valid perfect square](solution/0367_Valid_Perfect_Square.cpp):
- binary search
- newton method

**questions**
- [326 power of three](solution/0326_Power_of_Three.cpp)
- [342 power of four](solution/0342_Power_of_Four.cpp)

#### binary, decimal and hexadecimal

- [405 convert a number to hexadecimal](solution/0405_Convert_a_Number_to_Hexadecimal.cpp)
- [441 arranging coins](solution/0441_Arranging_Coins.cpp)

## tricks
### bit
#### power of two
- [342 power of four](solution/0342_Power_of_Four.cpp)

#### xor
- [389 find the difference](solution/0389_Find_the_Difference.cpp)

#### hex

- [405 convert a number to hexadecimal](solution/0405_Convert_a_Number_to_Hexadecimal.cpp)

#### other

- [401 binary watch](solution/0401_Binary_Watch.cpp)

#### INT_MIN

- [divide two integers](solution/0029_Divide_Two_Integers.cpp)


