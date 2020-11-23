# Problem

[Unpopular Books](https://leetcode.com/problems/unpopular-books/)

# Schema

```
Books

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| book_id        | int     |
| name           | varchar |
| available_from | date    |
+----------------+---------+
book_id is the primary key of this table.

Orders

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| order_id       | int     |
| book_id        | int     |
| quantity       | int     |
| dispatch_date  | date    |
+----------------+---------+
order_id is the primary key of this table.
book_id is a foreign key to the Books table.
```

# Example

```
Books table:
+---------+--------------------+----------------+
| book_id | name               | available_from |
+---------+--------------------+----------------+
| 1       | "Kalila And Demna" | 2010-01-01     |
| 2       | "28 Letters"       | 2012-05-12     |
| 3       | "The Hobbit"       | 2019-06-10     |
| 4       | "13 Reasons Why"   | 2019-06-01     |
| 5       | "The Hunger Games" | 2008-09-21     |
+---------+--------------------+----------------+

Orders table:
+----------+---------+----------+---------------+
| order_id | book_id | quantity | dispatch_date |
+----------+---------+----------+---------------+
| 1        | 1       | 2        | 2018-07-26    |
| 2        | 1       | 1        | 2018-11-05    |
| 3        | 3       | 8        | 2019-06-11    |
| 4        | 4       | 6        | 2019-06-05    |
| 5        | 4       | 5        | 2019-06-20    |
| 6        | 5       | 9        | 2009-02-02    |
| 7        | 5       | 8        | 2010-04-13    |
+----------+---------+----------+---------------+

Result table:
+-----------+--------------------+
| book_id   | name               |
+-----------+--------------------+
| 1         | "Kalila And Demna" |
| 2         | "28 Letters"       |
| 5         | "The Hunger Games" |
+-----------+--------------------+
```

# Idea

오늘은 `2019-06-23` 이다. 최근 일년동안 10 개 이하로 판매된 책들 중에
한달 전까지 available 한 책들의 book_id, name 을 출력하는 문제이다.

# Implementation

```sql
-- 647ms 53.93%
SELECT
  b.book_id,
  b.name
FROM
  (SELECT 
    * 
  FROM
    Books
  WHERE
    available_from <= "2019-05-23") b
  LEFT JOIN
    (SELECT 
      * 
    FROM
      Orders
    WHERE
      dispatch_date >= "2018-06-23"
    ) o
  ON
    b.book_id = o.book_id
GROUP BY 
  b.book_id, b.name
HAVING 
  SUM(o.quantity) is null OR
    SUM(o.quantity) < 10
    
```
