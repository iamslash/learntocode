
-- 871ms 51.08%
SELECT 
  DISTINCT(S.buyer_id)
FROM
  Sales AS S
INNER JOIN
  Product AS P
ON
  P.product_id = S.product_id
WHERE 
  P.product_name = 'S8' AND
  buyer_id NOT IN (
    SELECT 
      S.buyer_id
    FROM 
      Sales AS S
    INNER JOIN
      Product AS P
    ON
      P.product_id = S.product_id
    WHERE
      P.product_name = 'iPhone'
  )
;  
