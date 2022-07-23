# Problem

[Compute the Rank as a Percentage](https://leetcode.com/problems/compute-the-rank-as-a-percentage/)

# Implementation

```sql
-- 630ms 100.00% 0B 100.00%
SELECT student_id,
       department_id,
       ROUND(
         100 * PERCENT_RANK() OVER (PARTITION BY department_id ORDER BY mark DESC)
         , 2) AS percentage
  FROM Students
```
