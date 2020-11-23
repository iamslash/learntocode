# Problem

[Report Contiguous Dates](https://leetcode.com/problems/report-contiguous-dates/)

# Idea

```
SQL Schema

Table: Failed

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| fail_date    | date    |
+--------------+---------+
Primary key for this table is fail_date.
Failed table contains the days of failed tasks.

Table: Succeeded

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| success_date | date    |
+--------------+---------+
Primary key for this table is success_date.
Succeeded table contains the days of succeeded tasks.
```

```
Failed table:
+-------------------+
| fail_date         |
+-------------------+
| 2018-12-28        |
| 2018-12-29        |
| 2019-01-04        |
| 2019-01-05        |
+-------------------+

Succeeded table:
+-------------------+
| success_date      |
+-------------------+
| 2018-12-30        |
| 2018-12-31        |
| 2019-01-01        |
| 2019-01-02        |
| 2019-01-03        |
| 2019-01-06        |
+-------------------+


Result table:
+--------------+--------------+--------------+
| period_state | start_date   | end_date     |
+--------------+--------------+--------------+
| succeeded    | 2019-01-01   | 2019-01-03   |
| failed       | 2019-01-04   | 2019-01-05   |
| succeeded    | 2019-01-06   | 2019-01-06   |
+--------------+--------------+--------------+

The report ignored the system state in 2018 as we care about the system in the period 2019-01-01 to 2019-12-31.
From 2019-01-01 to 2019-01-03 all tasks succeeded and the system state was "succeeded".
From 2019-01-04 to 2019-01-05 all tasks failed and system state was "failed".
From 2019-01-06 to 2019-01-06 all tasks succeeded and system state was "succeeded".
```

# Implementation

```sql
SELECT
  "succeeded" AS perioed_state,
  MIN(success_date) AS start_date,
  MAX(success_date) AS end_date
FROM
  () temp1
GROUP BY DATEDIFF(success_date, exp_date1)

UNION

SELECT
  "FAILED" AS period_state,
  MIN(fail_date) AS start_date,
  MAX(fail_date) AS end_date
FROM
  () temp2
GROUP BY DATEDIFF(fail_date, exp_date2)    

ORDER BY start_date
```

```sql
SELECT
  "succeeded" AS perioed_state,
  MIN(success_date) AS start_date,
  MAX(success_date) AS end_date
FROM (
  SELECT 
    success_date,
    @r := SUBDATE(@r, -1) AS exp_date1
  FROM () init, Succeeded
  WHERE success_date BETWEEN "2019-01-01" AND "2019-12-31"    
  ORDER BY success_date
) temp1
GROUP BY DATEDIFF(success_date, exp_date1)

UNION

SELECT
  "FAILED" AS period_state,
  MIN(fail_date) AS start_date,
  MAX(fail_date) AS end_date
FROM (
  SELECT 
    fail_date,
    @r := SUBDATE(@r, -1) AS exp_date2
  FROM () init, Failed
  WHERE fail_date BETWEEN "2019-01-01" AND "2019-12-31"    
  ORDER BY fail_date
) temp2
GROUP BY DATEDIFF(fail_date, exp_date2)    

ORDER BY start_date
```


```sql
-- 1342ms 42.29% 0B 100.00%
SELECT
  "succeeded" AS period_state,
  MIN(success_date) AS start_date,
  MAX(success_date) AS end_date
FROM (
  SELECT 
    success_date,
    @r := SUBDATE(@r, -1) AS exp_date1
  FROM (
    SELECT @r := (SELECT MIN(success_date) FROM Succeeded)
  ) init, Succeeded
  WHERE success_date BETWEEN "2019-01-01" AND "2019-12-31"    
  ORDER BY success_date
) temp1
GROUP BY DATEDIFF(success_date, exp_date1)

UNION

SELECT
  "failed" AS period_state,
  MIN(fail_date) AS start_date,
  MAX(fail_date) AS end_date
FROM (
  SELECT 
    fail_date,
    @r := SUBDATE(@r, -1) AS exp_date2
  FROM (
    SELECT @r := (SELECT MIN(fail_date) FROM Failed)    
  ) init, Failed
  WHERE fail_date BETWEEN "2019-01-01" AND "2019-12-31"    
  ORDER BY fail_date
) temp2
GROUP BY DATEDIFF(fail_date, exp_date2)    

ORDER BY start_date
```