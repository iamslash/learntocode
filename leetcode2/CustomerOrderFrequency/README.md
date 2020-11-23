# Problem

[Customer Order Frequency](https://leetcode.com/problems/customer-order-frequency/)

# Idea

```
Customers
+--------------+-----------+-------------+
| customer_id  | name      | country     |
+--------------+-----------+-------------+
| 1            | Winston   | USA         |
| 2            | Jonathan  | Peru        |
| 3            | Moustafa  | Egypt       |
+--------------+-----------+-------------+

Product
+--------------+-------------+-------------+
| product_id   | description | price       |
+--------------+-------------+-------------+
| 10           | LC Phone    | 300         |
| 20           | LC T-Shirt  | 10          |
| 30           | LC Book     | 45          |
| 40           | LC Keychain | 2           |
+--------------+-------------+-------------+

Orders
+--------------+-------------+-------------+-------------+-----------+
| order_id     | customer_id | product_id  | order_date  | quantity  |
+--------------+-------------+-------------+-------------+-----------+
| 1            | 1           | 10          | 2020-06-10  | 1         |
| 2            | 1           | 20          | 2020-07-01  | 1         |
| 3            | 1           | 30          | 2020-07-08  | 2         |
| 4            | 2           | 10          | 2020-06-15  | 2         |
| 5            | 2           | 40          | 2020-07-01  | 10        |
| 6            | 3           | 20          | 2020-06-24  | 2         |
| 7            | 3           | 30          | 2020-06-25  | 2         |
| 9            | 3           | 30          | 2020-05-08  | 3         |
+--------------+-------------+-------------+-------------+-----------+

Result table:
+--------------+------------+
| customer_id  | name       |  
+--------------+------------+
| 1            | Winston    |
+--------------+------------+ 
Winston spent $300 (300 * 1) in June and $100 ( 10 * 1 + 45 * 2) in July 2020.
Jonathan spent $600 (300 * 2) in June and $20 ( 2 * 10) in July 2020.
Moustafa spent $110 (10 * 2 + 45 * 2) in June and $0 in July 2020.
```

# Implementation

```sql
SELECT c.customer_id, c.name
FROM Customers c
WHERE c.customer_id IN() AND
      c.customer_id IN() 
```

```sql
-- 797mb 100.00% 0B 100.00%
SELECT c.customer_id, c.name
FROM Customers c
WHERE c.customer_id IN (
        SELECT o.customer_id
        FROM Product p, Orders o
        WHERE p.product_id = o.product_id AND
        YEAR(order_date)=2020 AND MONTH(order_date)=6
        GROUP BY o.customer_id
        HAVING SUM(p.price*o.quantity) >= 100) AND
      c.customer_id IN (
        SELECT o.customer_id
        FROM Product p, Orders o
        WHERE p.product_id = o.product_id AND
        YEAR(order_date)=2020 AND MONTH(order_date)=7
        GROUP BY o.customer_id
        HAVING SUM(p.price*o.quantity) >= 100) 
```
