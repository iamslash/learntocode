# Problem

[Classifying Triangles by Lengths](https://leetcode.com/problems/classifying-triangles-by-lengths/)

# Implementation

```sql
-- 537ms 100.00% 0B 100.00%
SELECT
  CASE
    WHEN (A + B <= C) OR
         (B + C <= A) OR
         (A + C <= B)
      THEN 'Not A Triangle'
    WHEN (A = B AND B <> C) OR
         (A = C AND A <> B) OR
         (B = C AND A <> B)
      THEN 'Isosceles'
    WHEN (A = B AND B = C)
      THEN 'Equilateral'
    ELSE 'Scalene'
  END AS triangle_type
  FROM Triangles;
```
