# Problem

[Rectangles Area](https://leetcode.com/problems/rectangles-area/)

# Idea

```
Points table:
+----------+-------------+-------------+
| id       | x_value     | y_value     |
+----------+-------------+-------------+
| 1        | 2           | 8           |
| 2        | 4           | 7           |
| 3        | 2           | 10          |
+----------+-------------+-------------+

Result table:
+----------+-------------+-------------+
| p1       | p2          | area        |
+----------+-------------+-------------+
| 2        | 3           | 6           |
| 1        | 2           | 2           |
+----------+-------------+-------------+

p1 should be less than p2 and area greater than 0.
p1 = 1 and p2 = 2, has an area equal to |2-4| * |8-7| = 2.
p1 = 2 and p2 = 3, has an area equal to |4-2| * |7-10| = 6.
p1 = 1 and p2 = 3 It's not possible because the rectangle has an area equal to 0.
```

# Implementation

```sql
-- 564ms 38.85% 0B 100.00%
SELECT a.id as P1, b.id as P2,
  ABS(b.x_value - a.x_value) * ABS(b.y_value - a.y_value) as AREA
FROM Points a 
JOIN Points b
  ON a.id < b.id AND
     a.x_value != b.x_value AND
     b.y_value != a.y_value
ORDER BY AREA DESC, P1 ASC, P2 ASC
```
