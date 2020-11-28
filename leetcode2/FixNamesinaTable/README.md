# Problem

[Fix Names in a Table](https://leetcode.com/problems/fix-names-in-a-table/)

# Implementation

```sql
-- 531ms 100.00% 0B 100.00%
SELECT user_id,
       CONCAT(UPPER(LEFT(name, 1)), 
              LOWER(SUBSTR(name, 2))) AS name
FROM Users
ORDER BY user_id ASC;
```
