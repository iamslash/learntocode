# Problem

[Friday Purchase III](https://leetcode.com/problems/friday-purchase-iii/)

# Implementation

```sql
-- 1181ms 91.10% 0B 100.00%
WITH RECURSIVE DateRange AS (
    SELECT DATE '2023-11-01' AS date_
    UNION ALL
    SELECT date_ + INTERVAL 1 DAY
    FROM DateRange
    WHERE date_ < DATE '2023-11-30'
),

MembershipTypes AS (
    SELECT 'Premium' AS membership
    UNION
    SELECT 'VIP' AS membership
),

JoinedMemberships AS (
    SELECT
        dr.date_,
        mt.membership
    FROM DateRange dr
    CROSS JOIN MembershipTypes mt
),

FridaySpend AS (
    SELECT
        jm.date_,
        jm.membership,
        SUM(COALESCE(p.amount_spend, 0)) AS total_amount
    FROM JoinedMemberships jm
    LEFT JOIN (
        SELECT
            p.purchase_date,
            p.amount_spend,
            u.membership
        FROM Purchases p
        LEFT JOIN Users u ON p.user_id = u.user_id
    ) AS p ON jm.date_ = p.purchase_date AND jm.membership = p.membership
    WHERE WEEKDAY(jm.date_) = 4
    GROUP BY jm.date_, jm.membership
    ORDER BY jm.date_, jm.membership
)

SELECT
    DENSE_RANK() OVER (ORDER BY date_) AS week_of_month,
    membership,
    total_amount
FROM FridaySpend;
```
