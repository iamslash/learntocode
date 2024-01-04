# Problem

[Class Performance](https://leetcode.com/problems/class-performance/)

# Implementation

```sql
-- 504ms 88.57% 0B 100.00%
SELECT MAX(assignment1 + assignment2 + assignment3) -
       MIN(assignment1 + assignment2 + assignment3) AS difference_in_score
  FROM Scores;             
```
