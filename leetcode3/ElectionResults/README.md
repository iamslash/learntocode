# Problem

[Election Results](https://leetcode.com/problems/election-results/)

# Implementation

```sql
WITH cte1 AS (
), cte2 AS (
)
  SELECT candidate
    FROM cte2
   WHERE total = (SELECT MAX(total) FROM cte2)
ORDER BY candidate;
```

```sql
-- 837ms 100.00% 0B 100.00%
WITH cte1 AS (
  SELECT voter, 
         1 / COUNT(*) AS value
    FROM Votes
GROUP BY voter    
), cte2 AS (
  SELECT candidate,
         SUM(value) AS total
    FROM Votes v
    JOIN cte1 ON v.voter = cte1.voter
GROUP BY candidate
  HAVING candidate IS NOT NULL
)
  SELECT candidate
    FROM cte2
   WHERE total = (SELECT MAX(total) FROM cte2)
ORDER BY candidate;
```

