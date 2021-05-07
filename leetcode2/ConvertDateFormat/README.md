# Problem

[Convert Date Format](https://leetcode.com/problems/convert-date-format/)

# Implementation

```sql
-- 439ms 100.00% 0B 100.00%
SELECT DATE_FORMAT(day, '%W, %M %e, %Y') AS day
  FROM Days;
```
