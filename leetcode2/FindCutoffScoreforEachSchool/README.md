# Problem

[Find Cutoff Score for Each School](https://leetcode.com/problems/find-cutoff-score-for-each-school/)

# Implementation

```sql
-- 455ms 95.56% 0B 100.00%
   SELECT s.school_id,
           IFNULL(MIN(score), -1) AS score 
     FROM Schools s
LEFT JOIN Exam e
       ON s.capacity >= e.student_count
 GROUP BY s.school_id;       
```
