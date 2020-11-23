# Problem

[Reformat Department Table](https://leetcode.com/problems/reformat-department-table/)

# Idea

## Tables

```
Table: Department

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| revenue       | int     |
| month         | varchar |
+---------------+---------+
(id, month) is the primary key of this table.
The table has information about the revenue of each department per month.
The month has values in ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"].
```

# Implementation

```sql
-- 553ms 36.27% 0B 100.00%
SELECT 
  id, 
  SUM(IF(month = 'Jan', revenue, null)) AS Jan_Revenue,
  SUM(IF(month = 'Feb', revenue, null)) AS Feb_Revenue,
  SUM(IF(month = 'Mar', revenue, null)) AS Mar_Revenue,
  SUM(IF(month = 'Apr', revenue, null)) AS Apr_Revenue,
  SUM(IF(month = 'May', revenue, null)) AS May_Revenue,
  SUM(IF(month = 'Jun', revenue, null)) AS Jun_Revenue,
  SUM(IF(month = 'Jul', revenue, null)) AS Jul_Revenue,
  SUM(IF(month = 'Aug', revenue, null)) AS Aug_Revenue,
  SUM(IF(month = 'Sep', revenue, null)) AS Sep_Revenue,
  SUM(IF(month = 'Oct', revenue, null)) AS Oct_Revenue,
  SUM(IF(month = 'Nov', revenue, null)) AS Nov_Revenue,
  SUM(IF(month = 'Dec', revenue, null)) AS Dec_Revenue
FROM Department
GROUP BY id
```
