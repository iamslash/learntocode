# Problem

[Find Students Who Improved](https://leetcode.com/problems/find-students-who-improved/description/)

# Implementation

```sql

-- Use FIRST_VALUE instead of LAST_VALUE() which is too complicated to use.
-- 583ms 100.00%
WITH ctx AS (
  SELECT student_id,
         subject,
         FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date) AS first_score,
         FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date DESC) AS latest_score
    FROM Scores     
)
SELECT * 
  FROM ctx
 WHERE first_score < latest_score  
 GROUP BY student_id, subject
 ORDER BY student_id, subject
```
