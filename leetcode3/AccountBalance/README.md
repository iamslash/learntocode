# Problem

[Account Balance](https://leetcode.com/problems/account-balance/)

# Implementation

```sql
-- 455ms 60.98% 0B 100.00%
SELECT account_id,
       day,
       SUM(CASE WHEN type='Deposit' THEN amount ELSE -amount END) 
         OVER(PARTITION BY account_id ORDER BY day) AS balance
  FROM Transactions;
```
