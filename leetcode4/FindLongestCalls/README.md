# Problem

[Find Longest Calls](https://leetcode.com/problems/find-longest-calls/)

# Implementation

```
-- 1009ms 85.88% 0B 100.00%
select first_name, 
       type,
       duration_formatted
  from (select Con.id,
               Con.first_name, 
               C.type, 
               concat(lpad(floor(C.duration / 3600), 2, '0'), ':', 
                      lpad(floor((C.duration % 3600) / 60), 2, '0'), ':', 
                      lpad(floor(C.duration % 60), 2, '0')) as `duration_formatted`, 
               rank() over (partition by C.type order by duration desc) `rank`
          from Contacts Con
          join Calls C
            on Con.id = C.contact_id) sub
 where `rank` <= 3
 order by type, duration_formatted desc, first_name desc;
```
