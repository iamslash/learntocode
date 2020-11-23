
-- 790ms 84.31%
SELECT 
  product_id,
  product_name
FROM
  Product
WHERE
  product_id NOT IN
  (
    SELECT 
      product_id
    FROM
      Sales
    WHERE
      sale_date NOT BETWEEN
      '2019-01-01' AND '2019-03-31'
  )
;  
