# Problem

[Calculate Product Final Price](https://leetcode.com/problems/calculate-product-final-price/description/)

# Implementation

```sql
-- 1959ms 5.43% 
SELECT product_id,
       IFNULL(price * (1 - discount / 100), price) AS final_price,
       p.category
  FROM Products p
  LEFT JOIN Discounts d
    ON p.category = d.category
    
-- 726ms 33.03%
SELECT p.product_id,
       CASE WHEN d.category IS NULL THEN price ELSE price * (100 - discount) / 100 END final_price,
       p.category
  FROM Products p
  LEFT JOIN discounts d
    ON p.category = d.category
 ORDER BY 1   
```

