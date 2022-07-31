# Problem

[Number of Unique Subjects Taught by Each Teacher](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/)

# Implementation

```sql
-- 650ms 41.67% 0B 100.00%
  SELECT teacher_id, 
         COUNT(DISTINCT subject_id) AS cnt
    FROM Teacher
GROUP BY teacher_id;
```
