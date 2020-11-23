# Problem

[Last Person to Fit in the Elevator](https://leetcode.com/problems/last-person-to-fit-in-the-elevator/)

# Idea

```
Table: Queue

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| person_name | varchar |
| weight      | int     |
| turn        | int     |
+-------------+---------+
```

```
Queue table
+-----------+-------------------+--------+------+
| person_id | person_name       | weight | turn |
+-----------+-------------------+--------+------+
| 5         | George Washington | 250    | 1    |
| 3         | John Adams        | 350    | 2    |
| 6         | Thomas Jefferson  | 400    | 3    |
| 2         | Will Johnliams    | 200    | 4    |
| 4         | Thomas Jefferson  | 175    | 5    |
| 1         | James Elephant    | 500    | 6    |
+-----------+-------------------+--------+------+

Result table
+-------------------+
| person_name       |
+-------------------+
| Thomas Jefferson  |
+-------------------+
```

# Implementation

```
q1 JOIN q2

+-----------+-------------------+--------+------+-----------+-------------------+--------+------+
| person_id | person_name       | weight | turn | person_id | person_name       | weight | turn |
+-----------+-------------------+--------+------+-----------+-------------------+--------+------+
| 5         | George Washington | 250    | 1    | 5         | George Washington | 250    | 1    |
| 3         | John Adams        | 350    | 2    | 5         | George Washington | 250    | 1    |
| 3         | John Adams        | 350    | 2    | 3         | John Adams        | 350    | 2    |
| 6         | Thomas Jefferson  | 400    | 3    | 5         | George Washington | 250    | 1    |
| 6         | Thomas Jefferson  | 400    | 3    | 3         | John Adams        | 350    | 2    |
| 6         | Thomas Jefferson  | 400    | 3    | 6         | Thomas Jefferson  | 400    | 3    |
...
```

```sql
-- 2072ms 38.52% 0B 100.00%
SELECT q1.person_name
FROM Queue q1 JOIN Queue q2 ON q1.turn >= q2.turn
GROUP BY q1.turn
HAVING SUM(q2.weight) <= 1000
ORDER BY SUM(q2.weight) DESC
LIMIT   1
```
