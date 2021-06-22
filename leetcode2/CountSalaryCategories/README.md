# Problem

[Count Salary Categories](https://leetcode.com/problems/count-salary-categories/)

# Implementation

```sql
-- 1637ms 100.00% 0B 100.00%
   SELECT 'Low Salary' AS category, 
          COUNT(*) AS accounts_count
    WHERE income < 20000
     FROM accounts
UNION ALL
   SELECT 'Average Salary' AS category, 
          COUNT(*) AS accounts_count
    WHERE income BETWEEN 20000 AND 50000          
     FROM accounts
UNION ALL
   SELECT 'High Salary' AS category, 
          COUNT(*) AS accounts_count
    WHERE income > 50000          
     FROM accounts     
```

```sql
-- 1975ms 100.00% 0B 100.00%
   SELECT 'Low Salary' AS category, 
          SUM(income < 20000) AS accounts_count
     FROM accounts
UNION ALL
   SELECT 'Average Salary' AS category, 
          SUM(income BETWEEN 20000 AND 50000) AS accounts_count
     FROM accounts
UNION ALL
   SELECT 'High Salary' AS category, 
          SUM(income > 50000) AS accounts_count
     FROM accounts
```
