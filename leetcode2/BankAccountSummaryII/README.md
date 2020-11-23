# Problem

[Bank Account Summary II](https://leetcode.com/problems/bank-account-summary-ii/)

# Implementation

```sql
-- 983ms 100.00% 0B 100.00%
SELECT u.name, SUM(t.amount) AS balance
  FROM Users u
  JOIN Transactions t
    ON u.account = t.account
GROUP BY u.name HAVING SUM(t.amount) > 10000;    
```
