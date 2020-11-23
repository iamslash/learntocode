# Problem

[The Most Recent Three Orders](https://leetcode.com/problems/the-most-recent-three-orders/)

# Idea

```
Customers
+-------------+-----------+
| customer_id | name      |
+-------------+-----------+
| 1           | Winston   |
| 2           | Jonathan  |
| 3           | Annabelle |
| 4           | Marwan    |
| 5           | Khaled    |
+-------------+-----------+

Orders
+----------+------------+-------------+------+
| order_id | order_date | customer_id | cost |
+----------+------------+-------------+------+
| 1        | 2020-07-31 | 1           | 30   |
| 2        | 2020-07-30 | 2           | 40   |
| 3        | 2020-07-31 | 3           | 70   |
| 4        | 2020-07-29 | 4           | 100  |
| 5        | 2020-06-10 | 1           | 1010 |
| 6        | 2020-08-01 | 2           | 102  |
| 7        | 2020-08-01 | 3           | 111  |
| 8        | 2020-08-03 | 1           | 99   |
| 9        | 2020-08-07 | 2           | 32   |
| 10       | 2020-07-15 | 1           | 2    |
+----------+------------+-------------+------+

Result table:
+---------------+-------------+----------+------------+
| customer_name | customer_id | order_id | order_date |
+---------------+-------------+----------+------------+
| Annabelle     | 3           | 7        | 2020-08-01 |
| Annabelle     | 3           | 3        | 2020-07-31 |
| Jonathan      | 2           | 9        | 2020-08-07 |
| Jonathan      | 2           | 6        | 2020-08-01 |
| Jonathan      | 2           | 2        | 2020-07-30 |
| Marwan        | 4           | 4        | 2020-07-29 |
| Winston       | 1           | 8        | 2020-08-03 |
| Winston       | 1           | 1        | 2020-07-31 |
| Winston       | 1           | 10       | 2020-07-15 |
+---------------+-------------+----------+------------+
Winston has 4 orders, we discard the order of "2020-06-10" because it is the oldest order.
Annabelle has only 2 orders, we return them.
Jonathan has exactly 3 orders.
Marwan ordered only one time.
We sort the result table by customer_name in ascending order, by customer_id in ascending order and by order_date in descending order in case of a tie.
```

# Implementation

with 
    customer_recent as (select customer_id, order_id, order_date, rank() 
    over (partition by customer_id order by order_date desc) as weight  from orders)
select customers.name as customer_name, customers.customer_id, customer_recent.order_id,  
  customer_recent.order_date 
from customer_recent 
join customers 
on customer_recent.customer_id = customers.customer_id 
where weight between 1 and 3 order by customer_name asc, customer_id asc, order_date desc
    

```sql
WITH customer_recent AS () 
SELECT c.name AS customer_name, c.customer_id, r.order_id, r.order_date
FROM customer_recent r
JOIN customers c
  ON r.customer_id = c.customer_id
WHERE weight BETWEEN 1 and 3 
ORDER BY customer_name asc, customer_id asc, order_date desc
```

```sql
-- 942ms 90.53% 0B 100.00%
WITH customer_recent AS (
  SELECT customer_id, order_id, order_date, rank() over (partition by customer_id 
  ORDER BY order_date desc) weight 
  FROM orders) 
SELECT c.name AS customer_name, c.customer_id, r.order_id, r.order_date
FROM customer_recent r
JOIN customers c
  ON r.customer_id = c.customer_id
WHERE weight BETWEEN 1 and 3 
ORDER BY customer_name asc, customer_id asc, order_date desc
```
