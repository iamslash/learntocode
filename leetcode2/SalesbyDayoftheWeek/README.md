# Problem

[Sales by Day of the Week](https://leetcode.com/problems/sales-by-day-of-the-week/)

# Idea

```
SQL Schema
Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| order_date    | date    | 
| item_id       | varchar |
| quantity      | int     |
+---------------+---------+
(ordered_id, item_id) is the primary key for this table.
This table contains information of the orders placed.
order_date is the date when item_id was ordered by the customer with id customer_id.

Table: Items

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| item_id             | varchar |
| item_name           | varchar |
| item_category       | varchar |
+---------------------+---------+
item_id is the primary key for this table.
item_name is the name of the item.
item_category is the category of the item.
```

```
Orders table:
+------------+--------------+-------------+--------------+-------------+
| order_id   | customer_id  | order_date  | item_id      | quantity    |
+------------+--------------+-------------+--------------+-------------+
| 1          | 1            | 2020-06-01  | 1            | 10          |
| 2          | 1            | 2020-06-08  | 2            | 10          |
| 3          | 2            | 2020-06-02  | 1            | 5           |
| 4          | 3            | 2020-06-03  | 3            | 5           |
| 5          | 4            | 2020-06-04  | 4            | 1           |
| 6          | 4            | 2020-06-05  | 5            | 5           |
| 7          | 5            | 2020-06-05  | 1            | 10          |
| 8          | 5            | 2020-06-14  | 4            | 5           |
| 9          | 5            | 2020-06-21  | 3            | 5           |
+------------+--------------+-------------+--------------+-------------+

Items table:
+------------+----------------+---------------+
| item_id    | item_name      | item_category |
+------------+----------------+---------------+
| 1          | LC Alg. Book   | Book          |
| 2          | LC DB. Book    | Book          |
| 3          | LC SmarthPhone | Phone         |
| 4          | LC Phone 2020  | Phone         |
| 5          | LC SmartGlass  | Glasses       |
| 6          | LC T-Shirt XL  | T-Shirt       |
+------------+----------------+---------------+

Result table:
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| Category   | Monday    | Tuesday   | Wednesday | Thursday  | Friday    | Saturday  | Sunday    |
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| Book       | 20        | 5         | 0         | 0         | 10        | 0         | 0         |
| Glasses    | 0         | 0         | 0         | 0         | 5         | 0         | 0         |
| Phone      | 0         | 0         | 5         | 1         | 0         | 0         | 10        |
| T-Shirt    | 0         | 0         | 0         | 0         | 0         | 0         | 0         |
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
On Monday (2020-06-01, 2020-06-08) were sold a total of 20 units (10 + 10) in the category Book (ids: 1, 2).
On Tuesday (2020-06-02) were sold a total of 5 units  in the category Book (ids: 1, 2).
On Wednesday (2020-06-03) were sold a total of 5 units in the category Phone (ids: 3, 4).
On Thursday (2020-06-04) were sold a total of 1 unit in the category Phone (ids: 3, 4).
On Friday (2020-06-05) were sold 10 units in the category Book (ids: 1, 2) and 5 units in Glasses (ids: 5).
On Saturday there are no items sold.
On Sunday (2020-06-14, 2020-06-21) were sold a total of 10 units (5 +5) in the category Phone (ids: 3, 4).
There are no sales of T-Shirt.
```

# Implementation

```sql
SELECT i.item_category AS Category,
  SUM() AS Monday,
  SUM() AS Tuesday,
  SUM() AS Wednesday,
  SUM() AS Thursday,
  SUM() AS Friday,
  SUM() AS Saturday,
  SUM() AS Sunday
FROM Items i 
LEFT JOIN Orders o
  ON i.item_id = o.item_id
GROUP BY i.item_category
ORDER BY i.item_category
```

```sql
-- 579ms 62.08% 0B 100.00%
SELECT i.item_category AS CATEGORY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '0' THEN o.quantity ELSE 0 END) AS MONDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '1' THEN o.quantity ELSE 0 END) AS TUESDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '2' THEN o.quantity ELSE 0 END) AS WEDNESDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '3' THEN o.quantity ELSE 0 END) AS THURSDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '4' THEN o.quantity ELSE 0 END) AS FRIDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '5' THEN o.quantity ELSE 0 END) AS SATURDAY,
  SUM(CASE WHEN WEEKDAY(o.order_date) = '6' THEN o.quantity ELSE 0 END) AS SUNDAY
FROM Items i 
LEFT JOIN Orders o
  ON i.item_id = o.item_id
GROUP BY i.item_category
ORDER BY i.item_category
```
