# Problem

[Low-Quality Problems](https://leetcode.com/problems/low-quality-problems/)

# Implementation

```sql
-- 512ms 100.00% 0B 100.00%
  SELECT problem_id 
    FROM Problems
   WHERE (likes / (likes + dislikes)) < 0.6
ORDER BY problem_id ASC;
```
