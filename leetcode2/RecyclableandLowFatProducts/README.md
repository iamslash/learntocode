# Problem

[Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/)

# Implementation

```sql
-- 401ms 100.00% 0B 100.00%
SELECT product_id 
  FROM Products
 WHERE low_fats = 'Y' AND
       recyclable = 'Y';
```
