# Problem

[Users With Two Purchases Within Seven Days](https://leetcode.com/problems/users-with-two-purchases-within-seven-days/)

# Implementation

```sql
SELECT DISTINCT user_id 
  FROM () t
 WHERE DATEDIFF(cur_date, prv_date) <= 7 
```

```sql
-- 386ms 81.82% 0B 100.00%
SELECT DISTINCT user_id 
  FROM (
    SELECT user_id, 
           purchase_date AS cur_date,
           LAG(purchase_date) OVER(PARTITION BY user_id ORDER BY purchase_date) AS prv_date
      FROM Purchases
  ) t
 WHERE DATEDIFF(cur_date, prv_date) <= 7 
```
