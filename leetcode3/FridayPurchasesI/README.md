# Problem

[Friday Purchases I](https://leetcode.com/problems/friday-purchases-i/)

# Implementation

```
-- 803ms 51.61% 0B 100.00%
SELECT (WEEK(purchase_date) - WEEK('2023-11-01') + 1) AS 'week_of_month',
       purchase_date,
       SUM(amount_spend) AS 'total_amount'
  FROM Purchases
 WHERE DAYOFWEEK(purchase_date) = 6  
 GROUP BY purchase_date
 ORDER BY week_of_month ASC;
```
