# Problem

[Tasks Count in the Weekend](https://leetcode.com/problems/tasks-count-in-the-weekend/)

# Implementation

```
-- 464ms 50.00% 0B 100.00%
SELECT SUM(WEEKDAY(submit_date) >= 5) AS weekend_cnt,
       SUM(WEEKDAY(submit_date) < 5) AS working_cnt
  FROM Tasks;
```
