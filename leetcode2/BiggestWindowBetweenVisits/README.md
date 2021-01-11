# Problem

[Biggest Window Between Visits](https://leetcode.com/problems/biggest-window-between-visits/)

# Implementation

```sql
-- 460ms 67.47% 0B 100.00%
SELECT user_id, MAX(diff) AS biggest_window
  FROM (
    SELECT user_id,
           DATEDIFF(LEAD(visit_date, 1, '2021-01-01')
                      OVER(PARTITION BY user_id 
                           ORDER BY visit_date), 
                    visit_date) AS diff
      FROM userVisits
  ) t
 GROUP BY user_id
 ORDER BY user_id
```
