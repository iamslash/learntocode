# Problem

[Find Top Scoring Students](https://leetcode.com/problems/find-top-scoring-students/)

# Implementation

```sql
-- 927ms 10.17% 0B 100.00%
WITH cte AS (
  SELECT a.student_id,
         a.major,
         b.course_id,
         c.grade
    FROM Students a
    LEFT JOIN courses AS b
      ON a.major = b.major
    LEFT JOIN enrollments AS c
      ON a.student_id = c.student_id AND
         b.course_id = c.course_id
)
SELECT student_id
  FROM cte
 GROUP BY student_id
HAVING COUNT(DISTINCT course_id) = SUM(grade = 'A')
```
