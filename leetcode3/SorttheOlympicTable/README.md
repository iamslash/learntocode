# Problem

[Sort the Olympic Table](https://leetcode.com/problems/sort-the-olympic-table/)

# Implementation

```sql
-- 355ms 100.00% 0B 100.00%
  SELECT * 
    FROM Olympic
ORDER BY gold_medals DESC, silver_medals DESC, bronze_medals DESC, country ASC;   
```
