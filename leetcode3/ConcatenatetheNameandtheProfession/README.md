# Problem

[Concatenate the Name and the Profession](https://leetcode.com/problems/concatenate-the-name-and-the-profession/)

# Implementation

```sql
-- 899ms 100.00% 0B 100.00%
  SELECT person_id,
         CONCAT(name, '(', SUBSTRING(profession, 1, 1), ')') AS name
    FROM Person
ORDER BY person_id DESC;
```
