# Problem

[Market Analysis II](https://leetcode.com/problems/market-analysis-ii/)

# Idea

```
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2019-01-01 | Lenovo         |
| 2       | 2019-02-09 | Samsung        |
| 3       | 2019-01-19 | LG             |
| 4       | 2019-05-21 | HP             |
+---------+------------+----------------+

Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2019-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2019-08-04 | 1       | 4        | 2         |
| 5        | 2019-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+

Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+

Result table:
+-----------+--------------------+
| seller_id | 2nd_item_fav_brand |
+-----------+--------------------+
| 1         | no                 |
| 2         | yes                |
| 3         | yes                |
| 4         | no                 |
+-----------+--------------------+

The answer for the user with id 1 is no because they sold nothing.
The answer for the users with id 2 and 3 is yes because the brands of their second sold items are their favorite brands.
The answer for the user with id 4 is no because the brand of their second sold item is not their favorite brand.
```

# Implementation

```sql
SELECT user_id AS seller_id,
  IF (i.item_brand = u.favorite_brand, "yes", "no") AS 2nd_item_fav_brand
FROM Users u
LEFT JOIN () t
  ON u.user_id = t.seller_id
LEFT JOIN Items i
  ON t.item_id = i.item_id
ORDER BY u.user_id
```

```sql
-- 3809ms 5.04% 0B 100.00%
SELECT user_id AS seller_id,
  IF (i.item_brand = u.favorite_brand, "yes", "no") AS 2nd_item_fav_brand
FROM Users u
LEFT JOIN (
  SELECT o1.seller_id, o1.item_id, o1.order_date
  FROM Orders o1 
  JOIN Orders o2
    ON o1.seller_id = o2.seller_id AND o1.order_date > o2.order_date
  GROUP BY o1.seller_id, o1.order_date
  HAVING COUNT(o1.order_id) = 1) t
  ON u.user_id = t.seller_id
LEFT JOIN Items i
  ON t.item_id = i.item_id
ORDER BY u.user_id
```
