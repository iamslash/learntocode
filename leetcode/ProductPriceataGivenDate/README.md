# Problem

[](https://leetcode.com/problems/product-price-at-a-given-date/)

# Idea

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key of this table.
Each row of this table indicates that the price of some 
product was changed to a new price at some date.

Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+

Result table:
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+
```

`2019-08-16` 의 `product_id, price` 를 구하라. 만약 해당 날짜안에
가격변동이 없었던 상품은 가격이 10 이었다고 가정하자.

먼저 `change_data <= 2019-08-16` 인 product 들을 `product_id` 를
그룹으로 얻어온다. 이것을 R0 이라고 하자.  결과는 아래와 같다.

```
1 "2019-08-16"
2 "2019-08-14"
```

`product_id, new_price` 를 `Products` 로 부터 얻어온다.
이때 `product_id, new_price` 는 `R0` 에 포함되어야 한다.
이것을 R1 이라고 하고 결과는 다음과 같다.

```
2 50
1 35
```

이제 `2019-08-16` 이후에만 가격이 변동된 제품들을 찾아서
`2019-08-16` 에 가격이 `10` 이라고 해보자. 이것을 R2
라고 하고 결과는 다음과 같다. 

```
3 10
```

`R1` 과 `R2` 를 합하면 답이 된다.

```
2 50
1 35
3 10
```

# Implementation

```sql
-- 253ms 99.56%
SELECT product_id, new_price AS 'price'
FROM Products p
WHERE (product_id, change_date) IN
(
	SELECT product_id, MAX(change_date) AS 'change_date'
	FROM Products
	WHERE change_date <= '2019-08-16'
	GROUP BY product_id
)
UNION 
SELECT product_id, 10 AS 'price'
FROM Products p
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16'
```
