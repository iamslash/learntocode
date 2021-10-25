# Problem

[The Category of Each Member in the Store](https://leetcode.com/problems/the-category-of-each-member-in-the-store/)

# Implementation

```
-- 1484ms 0B
WITH MemberVisitPurchase AS(
   SELECT m.member_id, m.name, v.visit_id, p.charged_amount
     FROM Members m
LEFT JOIN Visits v
       ON m.member_id = v.member_id
LEFT JOIN Purchases p
       ON v.visit_id = p.visit_id
),
VisitPurchaseCount AS(
  SELECT member_id, 
         name, 
         COUNT(visit_id) AS v_count,
         COUNT(charged_amount) AS p_count
    FROM MemberVisitPurchase 
GROUP BY member_id  
)
    SELECT member_id, name,
      CASE
        WHEN v_count = 0 THEN "Bronze"
        WHEN p_count/v_count*100 < 50 THEN "Silver"
        WHEN p_count/v_count*100 < 80 THEN "Gold"
        ELSE "Diamond"
      END AS category
    FROM VisitPurchaseCount
ORDER BY member_id ASC;
```
