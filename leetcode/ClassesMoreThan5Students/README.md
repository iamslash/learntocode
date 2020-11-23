# Problem

[Classes More Than 5 Students](https://leetcode.com/problems/classes-more-than-5-students/)

# Idea

Please list out all classes which have more than or equal to 5 students.

```
courses:

+---------+------------+
| student | class      |
+---------+------------+
| A       | Math       |
| B       | English    |
| C       | Math       |
| D       | Biology    |
| E       | Math       |
| F       | Computer   |
| G       | Math       |
| H       | Math       |
| I       | Math       |
+---------+------------+

output:

+---------+
| class   |
+---------+
| Math    |
+---------+
```

# Implementation

```sql
-- 247ms 87.54% 0B 100.00%
SELECT class 
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5

```
