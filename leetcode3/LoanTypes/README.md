# Problem

[Loan Types](https://leetcode.com/problems/loan-types/)

# Implementation

```sql
-- 528ms 0B
SELECT user_id
  FROM Loans
 GROUP BY user_id
HAVING SUM(loan_type = 'Refinance') > 0 AND SUM(loan_type = 'Mortgage') > 0
 ORDER BY user_id ASC; 
```
