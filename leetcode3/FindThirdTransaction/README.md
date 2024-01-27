# Problem

[Find Third Transaction](https://leetcode.com/problems/find-third-transaction/)

# Implementation

```
-- 946ms 67.65% 0B 100.00%
WITH trx_date_rank AS (
  SELECT user_id,
         spend,
         transaction_date,
         RANK() OVER(PARTITION BY user_id ORDER BY transaction_date ASC) AS 'date_rank'
    FROM Transactions
)
SELECT t3.user_id,
       t3.spend AS 'third_transaction_spend',
       t3.transaction_date AS 'third_transaction_date'
  FROM trx_date_rank t1,
       trx_date_rank t2,
       trx_date_rank t3
 WHERE t1.user_id = t2.user_id 
   AND t2.user_id = t3.user_id 
   AND t1.date_rank = 1 
   AND t2.date_rank = 2
   AND t3.date_rank = 3
   AND t1.spend < t3.spend
   AND t2.spend < t3.spend
```
