# Problem

[Evaluate Boolean Expression](https://leetcode.com/problems/evaluate-boolean-expression/)

# Idea

```
Variables table:
+------+-------+
| name | value |
+------+-------+
| x    | 66    |
| y    | 77    |
+------+-------+

Expressions table:
+--------------+----------+---------------+
| left_operand | operator | right_operand |
+--------------+----------+---------------+
| x            | >        | y             |
| x            | <        | y             |
| x            | =        | y             |
| y            | >        | x             |
| y            | <        | x             |
| x            | =        | x             |
+--------------+----------+---------------+

Result table:
+--------------+----------+---------------+-------+
| left_operand | operator | right_operand | value |
+--------------+----------+---------------+-------+
| x            | >        | y             | false |
| x            | <        | y             | true  |
| x            | =        | y             | false |
| y            | >        | x             | true  |
| y            | <        | x             | false |
| x            | =        | x             | true  |
+--------------+----------+---------------+-------+
As shown, you need find the value of each boolean exprssion in the table using the variables table.
```

# Implementation

```sql
SELECT e.left_operand, e.operator, e.right_operand,
  () AS value
FROM Expression e
JOIN Variables v1
  ON e.left_operand = v1.name
JOIN Variables v2
  ON e.right_operand = v2.name
```

```sql
-- 1294ms 63.06% 0B 100.00%
SELECT e.left_operand, e.operator, e.right_operand,
  (
    CASE
        WHEN e.operator = '<' AND v1.value < v2.value THEN 'true'
        WHEN e.operator = '=' AND v1.value = v2.value THEN 'true'
        WHEN e.operator = '>' AND v1.value > v2.value THEN 'true'
        ELSE 'false'
    END
  ) AS value
FROM Expressions e
JOIN Variables v1
  ON e.left_operand = v1.name
JOIN Variables v2
  ON e.right_operand = v2.name
```
