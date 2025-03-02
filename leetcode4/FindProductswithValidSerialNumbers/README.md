# Problem

[Find Products with Valid Serial Numbers](https://leetcode.com/problems/find-products-with-valid-serial-numbers/description/)

# Implementation

```sql
-- 598ms 42.32%
SELECT * 
  FROM products
 WHERE description regexp 'SN[0-9]{4}-[0-9]{4}[^0-9]+' OR
       description regexp 'SN[0-9]{4}-[0-9]{4}$'
 ORDER BY 1;
```

```
-- 1239ms 5.05%
select  product_id, 
        product_name, 
        description 
        from products 
        where description 
        RLIKE 'SN[0-9]{4}-[0-9]{4}$|SN[0-9]{4}-[0-9]{4} +' -- at end or followed by space
```
