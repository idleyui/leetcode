# Patterns

**toc**
- data structure
    - string
        - char hash
        - string pattern match
    - array
    - linked list
    - queue
    - stack
    - tree
        - traversal (pre/in/post/level order)
        - balance tree
    - graph
    - heap
    - hash
- algorithms
    - sort
    - search
        - binary search
        - hash table
        - tree search
        - dfs
        - bfs
    - greedy
    - dp
    - skills
        - backtrack
        - divide and conquer
        - enum
    - math
        - power and sqrt
        - conversion of number system
- bag of tricks
    - bit
        - power of two
        - xor

## data structure

### string

#### char hash
- [299 bulls and cows](solution/0299_Bulls_and_Cows.cpp)
- [383 ransom note](solution/0383_Ransom_Note.cpp)
- [387 first unique character in a string](solution/0387_First_Unique_Character_in_a_String.cpp)
- [389 find the difference](solution/0389_Find_the_Difference.cpp)
- [409 longest palindrome](solution/0409_Longest_Palindrome.cpp)

#### string pattern match
- [290 word pattern](solution/0290_Word_Pattern.cpp)
- [205 isomorphic strings](solution/0205_Isomorphic_Strings.cpp)

#### palindromic string

tricks: reverse, expansion

- [5 longest palindromic substring](solution/0005_Longest_Palindromic_Substring.cpp)
- [516 longest palindromic subsequence](solution/0516_Longest_Palindromic_Subsequence.cpp)
- [647 palindromic substring](solution/0647_Palindromic_Substrings.cpp)

### array

running sum & target sum: `sum[i...j] = sum[0...j] - sum[0...i]`
https://leetcode.com/problems/subarray-sum-equals-k/discuss/190674/Python-O(n)-Based-on-%22running_sum%22-concept-of-%22Cracking-the-coding-interview%22-book
- [560 subarray sum equals k](solution/0560_Subarray_Sum_Equals_k.cpp)

### linked list

### queue

### stack

> https://leetcode.com/problems/next-greater-element-ii/discuss/98270/JavaC%2B%2BPython-Loop-Twice

next greater element
- [496 next greater element I](solution/0496_Next_Greater_Element_I.cpp)
- [503 next greater element II](solution/0503_Next_Greater_Element_II.cpp)
- [739 daily temperatures](solution/0739_Daily_Temperatures.cpp)

### tree

traversal
- [144 binary tree preorder traversal](solution/0144_Binary_Tree_Preorder_Traversal.cpp)
- [94 binary tree inorder traversal](solution/0094_Binary_Tree_Inorder_Traversal.cpp)
- [145 binary tree postorder_traversal](solution/0145_Binary_Tree_Postorder_Traversal.cpp)
- [102 binary tree level order traversal](solution/0102_Binary_Tree_Level_Order_Traversal.cpp)

### graph

### heap

### hash

- [447 number of boomerangs](solution/0447_Number_of_Boomerangs.cpp)

## algorithms

[import:binary search](algo101/search/binary_search.md)

### sort

- [basic sort code](algo101/sort.cpp)
- basic sort: bubble sort, selection sort, insertion sort
- merge sort, heap sort, quick sort
- other: counting sort, bucket sort

**counting sort**
- [75 sort colors](solution/0075_Sort_Colors.cpp)

**topk problem**
- [973 K Closest Points to Origin](solution/0973_K_Closest_Points_to_Origin.cpp)

Solution:
- just sort and get first k
- maintain a size K heap: stream data
- quick select: based on quick sort

### backtrack

- top-down backtrack
> [A general approach to backtracking questions in Java (Subsets, Permutations, Combination Sum, Palindrome Partitioning)](https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-\(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning\))

- combination problem
- bottom up combination and filter by condition
- [401 binary watch](solution/0401_Binary_Watch.cpp)

use self matrix to log visit info
- [79 work search](solution/0079_Word_Search.cpp)

### two-pointers

https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers
- [3 longest substring without repeating characters](solution/0003_Longest_Substring_Without_Repeating_Characters.cpp)
- [763 partition labels](solution/0763_Partition_Labels.cpp)

### greedy

merge interval
- [56 merge intervals](solution/0056_Merge_Intervals.cpp)
- [763 partition labels](solution/0763_Partition_Labels.cpp)

### dp

#### longest common substring
- [5 longest palindromic substring](solution/0005_Longest_Palindromic_Substring.cpp)

#### longest common subsequence
- [1143 longest common subsequence](solution/1143_Longest_Common_Subsequence.cpp)
- [516 longest palindromic subsequence](solution/0516_Longest_Palindromic_Subsequence.cpp)

#### 0-1 knapsack

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

## problem

### permutation ans combination

#### next permutation

- [31 next permutation](solution/0031_Next_Permutaion.cpp)
- [556 next greater element III](solution/0556_Next_Greater_Element_III.cpp)


## appendix

### shitty questions


### awesome solution post

- 459 https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination
- 48 https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
- 160 amazing XOR solution: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49899/C%2B%2B-solution-using-XOR-trick

### Easter Egg

- [donald trump](https://leetcode.com/problems/convert-a-number-to-hexadecimal/discuss/89253/Simple-Java-solution-with-comment)
- "love live! mu'sic forever" in 434 test case

### dalao

https://leetcode.com/mzchen/

