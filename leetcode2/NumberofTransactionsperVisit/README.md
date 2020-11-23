# Problem

[Number of Transactions per Visit](https://leetcode.com/problems/number-of-transactions-per-visit/)

# Idea

It's too difficult.

```
Visits table:
+---------+------------+
| user_id | visit_date |
+---------+------------+
| 1       | 2020-01-01 |
| 2       | 2020-01-02 |
| 12      | 2020-01-01 |
| 19      | 2020-01-03 |
| 1       | 2020-01-02 |
| 2       | 2020-01-03 |
| 1       | 2020-01-04 |
| 7       | 2020-01-11 |
| 9       | 2020-01-25 |
| 8       | 2020-01-28 |
+---------+------------+
Transactions table:
+---------+------------------+--------+
| user_id | transaction_date | amount |
+---------+------------------+--------+
| 1       | 2020-01-02       | 120    |
| 2       | 2020-01-03       | 22     |
| 7       | 2020-01-11       | 232    |
| 1       | 2020-01-04       | 7      |
| 9       | 2020-01-25       | 33     |
| 9       | 2020-01-25       | 66     |
| 8       | 2020-01-28       | 1      |
| 9       | 2020-01-25       | 99     |
+---------+------------------+--------+
Result table:
+--------------------+--------------+
| transactions_count | visits_count |
+--------------------+--------------+
| 0                  | 4            |
| 1                  | 5            |
| 2                  | 0            |
| 3                  | 1            |
+--------------------+--------------+
* For transactions_count = 0, The visits (1, "2020-01-01"), (2, "2020-01-02"), (12, "2020-01-01") and (19, "2020-01-03") did no transactions so visits_count = 4.
* For transactions_count = 1, The visits (2, "2020-01-03"), (7, "2020-01-11"), (8, "2020-01-28"), (1, "2020-01-02") and (1, "2020-01-04") did one transaction so visits_count = 5.
* For transactions_count = 2, No customers visited the bank and did two transactions so visits_count = 0.
* For transactions_count = 3, The visit (9, "2020-01-25") did three transactions so visits_count = 1.
* For transactions_count >= 4, No customers visited the bank and did more than three transactions so we will stop at transactions_count = 3

The chart drawn for this example is as follows:
```

# Implementation

```sql
WITH t AS (),
     row_nums AS ()
SELECT row_nums.rn AS transactions_count, 
       COUNT(t.transactions_cnt) AS visits_count
FROM t 
RIGHT JOIN row_nums 
        ON transactions_cnt = rn
WHERE rn <= ()
GROUP BY rn
ORDER BY 1
```

```sql
WITH t AS (SELECT v.user_id AS user_id,
                  v.visit_date AS visit_date,
                  COUNT(t.transaction_date) AS transactions_cnt
           FROM Visits v
           LEFT JOIN Transactions t 
                  ON v.visit_date = t.transaction_date AND
                     v.user_id = t.user_id
           GROUP BY 1, 2),
     row_nums AS (SELECT ROW_NUMBER() OVER () AS rn
                  FROM Transactions
                  UNION
                  SELECT 0)
SELECT row_nums.rn AS transactions_count, 
       COUNT(t.transactions_cnt) AS visits_count
FROM t 
RIGHT JOIN row_nums 
        ON transactions_cnt = rn
WHERE rn <= (SELECT MAX(transactions_cnt) FROM t)
GROUP BY rn
ORDER BY 1```
