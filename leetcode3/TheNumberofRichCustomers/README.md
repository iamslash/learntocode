# Problem

[The Number of Rich Customers](https://leetcode.com/problems/the-number-of-rich-customers/)

# Implementation

```sql
-- 408ms 100.00% 0B 100.00%
SELECT COUNT(DISTINCT(customer_id)) AS rich_count
  FROM Store
 WHERE amount > 500
```
