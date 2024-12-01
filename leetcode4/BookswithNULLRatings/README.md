# Problem

[Books with NULL Ratings](https://leetcode.com/problems/books-with-null-ratings/)

# Implementation

```sql
-- 80ms 91.35% 0B 100.00%
SELECT book_id, 
       title,
       author,
       published_year
  FROM books
 WHERE rating is NULL;
       
```
