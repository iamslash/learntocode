
-- 485ms 33.51%
SELECT customer_id
FROM Customer c
GROUP BY c.customer_id
HAVING COUNT(DISTINCT c.product_key) =
  (SELECT COUNT(DISTINCT product_key)
   FROM Product)
