# Problem

[Dynamic Unpivoting of a Table](https://leetcode.com/problems/dynamic-unpivoting-of-a-table/)

# Implementation

```sql
-- 2663ms 20.83% 0B 100.00%
CREATE PROCEDURE UnpivotProducts()
BEGIN
    SET SESSION group_concat_max_len = 1000000;
    SET @macro = null;    
	SELECT group_concat(
            concat(
                'select product_id, "', 
                `column_name`, '" as store, ', 
                `column_name`,
                ' as price from products where ', 
                `column_name`, 
                ' is not null'
                ) separator ' union '
            )
     INTO @macro
     FROM `information_schema`.`columns`
    WHERE `table_schema`='test' AND 
          `table_name`='products' AND 
          `column_name` != 'product_id';
    PREPARE sql_query FROM @macro;
    EXECUTE sql_query;
    DEALLOCATE PREPARE sql_query;
END
```
