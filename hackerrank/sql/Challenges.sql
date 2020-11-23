


select c.hacker_id, h.name, count(c.challenge_id) as total from challenges c

inner join hackers h
on h.hacker_id= c.hacker_id

group by c.hacker_id having 

total=
(select  count(c1.challenge_id) from challenges c1
    group by c1.hacker_id 
    ORDER BY count(c1.challenge_id) desc limit 1)

or 

count(c.challenge_id) in 
(select t1.tot from ((select t.tot, count(t.hacker_id) from (select count(c2.challenge_id) as tot, c2.hacker_id from challenges c2
                group by c2.hacker_id) as t
            group by t.tot having count(t.hacker_id)=1) as t1))

order by total desc, h.hacker_id;
