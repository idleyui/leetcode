> sort online judge: [lintcode](https://www.lintcode.com/problem/sort-integers)

## 一些基本理论

> [wiki: sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)

- 比较排序

    常见的排序方法可以分为 比较排序 和 非比较排序
    
- 评价

    - Best
    - Average
    - Worst
    - Memory
    - Stable

## 快速排序

- 快速排序可以分为三步
    1. 选取 `pivot`
    2. 划分，根据 `pivot` 将数组划分为小于 `pivot` 和大于的部分
    3. 递归求解小于 `pivot` 和大于的部分

- 选取 `pivot` 时可以通过随机选择避免已经排好序的情况

- 划分的方式一般有 Lomuto Partition Scheme 和 Hoare Partition Scheme

    > [wikipedia](https://en.wikipedia.org/wiki/Quicksort)
    > [quicksort partitioning hoare vs lomuto](https://cs.stackexchange.com/questions/11458/quicksort-partitioning-hoare-vs-lomuto)

    - lomuto partition 使用快慢指针，容易实现但是效率更低，当所有元素相同时会退化为 O(n^2)；
        hoare partition 使用两端指针，理解容易但是实现复杂
     
    - 比较次数：两者需要的比较次数是相同的，因为每个元素都需要和 `pivot` 元素进行一次比较，因此都是 N-1 次比较
    
    - 交换次数
    
        假设序列为 {1,...,n}，
        
        **lomuto**
        在 `pivot` 为 x 的情况下，遍历时每次 < `pivot` 时交换一次，共计 x-1 次
        因此平均需要的交换次数 = $`\frac{1}{n} \sum_{x=1}^n(x-1) = \frac{n}{2} - \frac{1}{2}
    
        **hoare**
        超几何分布//todo
             
        直观地想，hoare 效率更高的原因就是每次交换都可以放好两个元素的位置，而 lomuto 只能放一个
        
    - bad cases
    
        在全部元素相等的情况下，hoare 虽然每次都需要交换，但是最终 i, j 会在中间相遇，因此仍然是 O(nlogn)；
        lomuto 不仅每次都要交换，而且每次递归只能减少一个元素，退化为 O(n^2)
        
        在已经排序的情况下，两者都会退化为 O(n^2)

- 具体实现 - [qsort.cpp](qsort.cpp)

    - lomuto 的实现没什么要注意的，只要记住最后把 `left` 和 `pivot` 交换就行，
      判断交换的时候 `<` `<=` 都可以

    - hoare 
        - 使用 `while` 而不是 `do...while` 时，需要添加一次自增操作避免两边相等时死循环，
        - 外层的 `while` 不要使用 l < h，这样会漏掉 l==h 时的判断，比如 {1,2,1} 就会漏掉 l==h==2 的情况导致把 2 分到左侧
        - 另外也不要使用在内层 `while` 中使用 >= / <=，可能会在 pivot 选到最大最小值时溢出边界导致无限递归
    