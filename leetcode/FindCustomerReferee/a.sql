# 240ms 98.16%
SELECT name
FROM customer
WHERE referee_id IS NULL OR referee_id != '2';
