# Problem

[Find Books with No Available Copies](https://leetcode.com/problems/find-books-with-no-available-copies/description/)

# Implementation

```sql          
-- 546ms 43.00% 
SELECT book_id,
       title,
       author,
       genre,
       publication_year,
       current_borrowers
  FROM library_books 
  LEFT JOIN (
    SELECT book_id,
           COUNT(*) AS current_borrowers
      FROM borrowing_records
     WHERE return_date IS NULL
     GROUP BY book_id
  ) t USING(book_id)
 WHERE total_copies = current_borrowers
 ORDER BY current_borrowers DESC, title ASC;
```
