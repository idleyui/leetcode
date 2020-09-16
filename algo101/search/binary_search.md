binary search

Integer

`|-----------AB----------|` search A & search B pattern

找到一个性质 C 使将区间一分为二
- [0,A] 满足 C 
- [B,size-1] 不满足 C

这样就可以使用二分法求解 A 或 B

handle `|--------A|B` in search B and `A|B---------|` in search A

basic search B
- [35 search insert position](../../solution/0035_Search_Insert_Position.cpp)

use twice search B
- [34 find first and last position of element in sorted array](../../solution/0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp)

complex condition
- [33 search in rotated sorted array](../../solution/0033_Search_in_Rotated_Sorted_Array.cpp)
- [81 search in rotated sorted array](../../solution/0081_Search_in_Rotated_Sorted_Array.cpp)




Floating number

power and sqrt
- [50 pow(x, n)](../../solution/0050_Powx_n.cpp)


todo
- [374 guess number higher or lower](../../solution/0374_Guess_Number_Higher_or_Lower.cpp)
