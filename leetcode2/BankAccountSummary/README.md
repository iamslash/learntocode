# Problem

[Bank Account Summary](https://leetcode.com/problems/bank-account-summary/)

# Implementation

```sql
SELECT u.user_id, user_name, (credit - out_cash + in_cash) AS credit,
       IF((credit - out_cash + in_cash) < 0, 'Yes', 'No') AS credit_limit_breached
FROM Users u
JOIN () out_tmp ON u.user_id = out_tmp.user_id
JOIN () in_tmp  ON u.user_id =  in_tmp.user_id
```

```sql
SELECT u.user_id, user_name, (credit - out_cash + in_cash) AS credit,
       IF((credit - out_cash + in_cash) < 0, 'Yes', 'No') AS credit_limit_breached
FROM Users u
JOIN (SELECT u1.user_id, IFNULL(SUM(amount), 0) AS out_cash
      FROM Users u1
      LEFT JOIN Transactions t1
             ON u1.user_id = t1.paid_by
      GROUP BY user_id) out_tmp ON u.user_id = out_tmp.user_id
JOIN (SELECT u2.user_id, IFNULL(SUM(amount), 0) AS in_cash
      FROM Users u2
      LEFT JOIN Transactions t2
             ON u2.user_id = t2.paid_to
      GROUP BY user_id) in_tmp  ON u.user_id =  in_tmp.user_id
```
