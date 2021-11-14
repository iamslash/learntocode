# Problem

[The Winner University](https://leetcode.com/problems/the-winner-university/)

# Implementation

`90%` 점수는 90 점과 같다는 말인가?

```sql
-- 790ms 100.00% 0B 100.00%
WITH excellent_students AS(
  SELECT
    (SELECT COUNT(*) FROM NewYork WHERE score >= 90) AS ny,
    (SELECT COUNT(*) FROM California WHERE score >= 90) AS ca
)
SELECT
  (CASE
    WHEN E.ny > E.ca THEN 'New York University'
    WHEN E.ny < E.ca THEN 'California University'
    ELSE 'No Winner'
   END) AS winner
  FROM excellent_students E;    
```
