# Problem

[Find the Start and End Number of Continuous Ranges](https://leetcode.com/problems/find-the-start-and-end-number-of-continuous-ranges/)

# Idea

* Tables

```
Logs

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| log_id        | int     |
+---------------+---------+
id is the primary key for this table.
Each row of this table contains the ID in a log Table.
```

* Examples

```
Logs table:
+------------+
| log_id     |
+------------+
| 1          |
| 2          |
| 3          |
| 7          |
| 8          |
| 10         |
+------------+

Result table:
+------------+--------------+
| start_id   | end_id       |
+------------+--------------+
| 1          | 3            |
| 7          | 8            |
| 10         | 10           |
+------------+--------------+
The result table should contain all ranges in table Logs.
From 1 to 3 is contained in the table.
From 4 to 6 is missing in the table
From 7 to 8 is contained in the table.
Number 9 is missing in the table.
Number 10 is contained in the table.
```

# Implementation

```sql
-- 208ms 76.46% 0B 100.00%
-- L1 which start with the sequence
-- L2 which end with the sequence

SELECT L1.log_id AS START_ID, L2.log_id AS END_ID
FROM (SELECT log_id 
        FROM Logs 
        WHERE log_id - 1 NOT in 
        (SELECT log_id FROM Logs)) AS L1,
     (SELECT log_id 
        FROM Logs 
        WHERE log_id + 1 NOT in 
        (SELECT log_id FROM Logs)) AS L2
WHERE L1.log_id <= L2.log_id
GROUP BY L1.log_id
ORDER BY L1.log_id ASC
```
