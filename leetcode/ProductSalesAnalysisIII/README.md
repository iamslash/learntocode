# Problem

[Product Sales Analysis III](https://leetcode.com/problems/product-sales-analysis-iii/)

# Schema

```
Sales

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
sale_id is the primary key of this table.
product_id is a foreign key to Product table.
Note that the price is per unit.

Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id is the primary key of this table.
```

# Example

```
Sales table:
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+

Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+

Result table:
+------------+------------+----------+-------+
| product_id | first_year | quantity | price |
+------------+------------+----------+-------+ 
| 100        | 2008       | 10       | 5000  |
| 200        | 2011       | 15       | 9000  |
+------------+------------+----------+-------+
```
# Idea

제품들중 첫해에 구입한 것들의 product_id, first_year, quantity, price
를 구하는 문제이다.

# Implementation

```sql
-- 975ms 38.64%
SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN (
           SELECT product_id, MIN(year) AS min_year
           FROM Sales
           GROUP BY product_id
         )
```

```sql
-- 1243ms 36.83%
SELECT
  product_id,
  year AS first_year,
  quantity,
  price
FROM
  Sales
WHERE (product_id, year) IN (
  SELECT
    product_id,
      MIN(year)
  FROM
    Sales
  GROUP BY
    product_id); 
```
