# Problem

[Article Views II](https://leetcode.com/problems/article-views-ii/)

# Schema

```
Views

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.
```

# Example

```
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 3          | 4         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+

Result table:
+------+
| id   |
+------+
| 5    |
| 6    |
+------+
```

# Idea

사람들 중 같은 날에 2 개 이상의 글을 읽은 사람들의
viewer_id 를 구하는 문제이다.

# Implementation

```sql
-- 571 ms 5.06%
SELECT DISTINCT(viewer_id) AS id
FROM Views
GROUP BY viewer_id, view_date
HAVING COUNT(DISTINCT(article_id)) > 1
ORDER BY viewer_id;
```

```sql
-- 263ms 83.23%
SELECT DISTINCT(id)
FROM (
      SELECT
      viewer_id AS id,
      view_date,
      COUNT(DISTINCT(article_id)) cnt_articles
      FROM Views
      GROUP BY viewer_id, view_date
      HAVING COUNT(DISTINCT(article_id)) > 1
     ) AS View_lv
ORDER BY id;
```

