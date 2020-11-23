# 280ms 63.39%
SELECT customer_number
FROM orders 
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;
