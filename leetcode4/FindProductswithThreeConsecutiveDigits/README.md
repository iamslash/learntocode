# Problem

[Find Products with Three Consecutive Digits](https://leetcode.com/problems/find-products-with-three-consecutive-digits/description/)

# Implementation

```sql
-- 552ms 34.62% 
SELECT product_id,
       name
  FROM Products
 WHERE name REGEXP '[0-9]{3}' AND name NOT REGEXP '[0-9]{4,}'
 ORDER BY product_id ASC;
```
