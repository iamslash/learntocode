# Problem

[Odd and Even Transactions](https://leetcode.com/problems/odd-and-even-transactions/description/)

# Implementation

```sql
SELECT transaction_date,
       SUM(CASE WHEN THEN ELSE END) AS odd_sum,
       SUM(CASE WHEN THEN ELSE END) AS even_sum
  FROM transactions
 GROUP BY transaction_date
 ORDER BY transaction_date;
```

```sql
-- 546ms 14.26%
SELECT transaction_date,
       SUM(CASE WHEN amount % 2 != 0 THEN amount ELSE 0 END) AS odd_sum,
       SUM(CASE WHEN amount % 2 = 0 THEN amount ELSE 0 END) AS even_sum
  FROM transactions
 GROUP BY transaction_date
 ORDER BY transaction_date;
```


