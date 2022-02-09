# Problem

[Order Two Columns Independently](https://leetcode.com/problems/order-two-columns-independently/)

# Implementation

```sql
-- 504ms 31.62% 0B 100.00%
SELECT first_col,
       second_col
  FROM (
      SELECT first_col,
             ROW_NUMBER() OVER(ORDER BY first_col ASC) AS r
        FROM Data
  ) a
  JOIN (
      SELECT second_col,
             ROW_NUMBER() OVER(ORDER BY second_col DESC) as r
        FROM Data
  ) b
    ON a.r = b.r
```

```sql
-- 505ms 30.88% 0B 100.00%
WITH first_rows AS (
  SELECT first_col, 
         ROW_NUMBER() OVER(ORDER BY first_col ASC) as r
    FROM Data),
     second_rows AS (
  SELECT second_col,
         ROW_NUMBER() OVER(ORDER BY second_col DESC) as r
    FROM Data)
  SELECT first_rows.first_col,
         second_rows.second_col
    FROM first_rows, second_rows
   WHERE first_rows.r = second_rows.r
ORDER BY first_rows.r ASC
```
