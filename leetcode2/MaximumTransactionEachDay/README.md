# Problem

> [Maximum Transaction Each Day](https://leetcode.com/problems/maximum-transaction-each-day/)

# Implementation

```sql
-- 433ms 87.10% 0B 100.0%
  SELECT transaction_id 
    FROM Transactions
   WHERE (DATE(day), amount)
      IN (SELECT DATE(day), MAX(amount)
            FROM Transactions
        GROUP BY DATE(day))
ORDER BY transaction_id;
```

```sql
-- RANK() OVER()
-- 536ms 51.61% 0B 100.00%
  SELECT transaction_id
    FROM (SELECT transaction_id, 
                 RANK() OVER(PARTITION BY DATE(day)
                 ORDER BY amount DESC) AS rnk
            FROM Transactions) AS tt
   WHERE rnk = 1
ORDER BY transaction_id ASC 
```
