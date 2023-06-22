# Problem

[Count Occurrences in Text](https://leetcode.com/problems/count-occurrences-in-text/)

# Implementation

```sql
-- 682ns 62.50% 0B 100.00%
SELECT 'bull' AS word,
       SUM(CASE WHEN content LIKE '% bull %' THEN 1 ELSE 0 END) AS count
  FROM Files
 UNION ALL
SELECT 'bear' AS word,
       SUM(CASE WHEN content LIKE '% bear %' THEN 1 ELSE 0 END) AS count
  FROM Files
```
