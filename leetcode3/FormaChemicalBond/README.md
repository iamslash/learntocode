# Problem

[Form a Chemical Bond](https://leetcode.com/problems/form-a-chemical-bond/)

# Implementation

```sql
-- 3348ms 100.00% 0B 100.00%
SELECT a.symbol AS metal, b.symbol AS nonmetal
  FROM Elements a
  JOIN Elements b
    ON a.type = 'Metal' AND b.type = 'Nonmetal';    
```
