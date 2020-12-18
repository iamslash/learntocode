# Problem

Daily Leads and Partners[](https://leetcode.com/problems/daily-leads-and-partners/)

# Implementation

```sql
-- 487ms 100.00% 0B 100.00%
SELECT date_id, 
       make_name, 
       COUNT(DISTINCT(lead_id)) AS unique_leads,
       COUNT(DISTINCT(partner_id)) AS unique_partners
  FROM DailySales
GROUP BY date_id, make_name  
```
