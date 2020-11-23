# Problem

[Monthly Transactions II](https://leetcode.com/problems/monthly-transactions-ii/)

# Idea

```
Table: Transactions

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| id             | int     |
| country        | varchar |
| state          | enum    |
| amount         | int     |
| trans_date     | date    |
+----------------+---------+

Table: Chargebacks

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| trans_id       | int     |
| charge_date    | date    |
+----------------+---------+
```

```
Transactions table:
+------+---------+----------+--------+------------+
| id   | country | state    | amount | trans_date |
+------+---------+----------+--------+------------+
| 101  | US      | approved | 1000   | 2019-05-18 |
| 102  | US      | declined | 2000   | 2019-05-19 |
| 103  | US      | approved | 3000   | 2019-06-10 |
| 104  | US      | approved | 4000   | 2019-06-13 |
| 105  | US      | approved | 5000   | 2019-06-15 |
+------+---------+----------+--------+------------+

Chargebacks table:
+------------+------------+
| trans_id   | trans_date |
+------------+------------+
| 102        | 2019-05-29 |
| 101        | 2019-06-30 |
| 105        | 2019-09-18 |
+------------+------------+

Result table:
+----------+---------+----------------+-----------------+-------------------+--------------------+
| month    | country | approved_count | approved_amount | chargeback_count  | chargeback_amount  |
+----------+---------+----------------+-----------------+-------------------+--------------------+
| 2019-05  | US      | 1              | 1000            | 1                 | 2000               |
| 2019-06  | US      | 3              | 12000           | 1                 | 1000               |
| 2019-09  | US      | 0              | 0               | 1                 | 5000               |
+----------+---------+----------------+-----------------+-------------------+--------------------+
```

# Implementation

```sql
-- 778ms 61.22% 0B 100.00%
SELECT month, country,
  SUM(IF(state = "approved", 1, 0)) AS approved_count,
  SUM(CASE WHEN state = "approved" THEN amount ELSE 0 END) AS approved_amount,
  SUM(IF(state="back", 1, 0)) AS chargeback_count,
  SUM(CASE WHEN state = "back" THEN amount ELSE 0 END) AS chargeback_amount
FROM (
  SELECT DATE_FORMAT(c.trans_date, '%Y-%m') AS month, 
    country,
    "back" AS state,
    amount
  FROM chargebacks AS c
  JOIN transactions AS t ON c.trans_id = t.id
  UNION ALL
  SELECT DATE_FORMAT(t.trans_date, '%Y-%m') AS month, country, state, amount
  FROM transactions AS t
  WHERE state = "approved"
) s
GROUP BY month, country;
```

