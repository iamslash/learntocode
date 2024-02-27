# Problem

[Binary Tree Nodes](https://leetcode.com/problems/binary-tree-nodes/)

# Implementation

```sql
-- 531ms 100.00% 0B 100.00%
SELECT N, (CASE
             WHEN P is NULL THEN 'Root'
             WHEN N in (SELECT DISTINCT P FROM Tree) THEN 'Inner'
             ELSE 'Leaf' 
           END) AS 'Type'
  FROM Tree
 ORDER by N ASC; 
```
