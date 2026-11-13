# Write your MySQL query statement below
-- Select 
--     contest_id, 
--     ROUND(COUNT(user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) as percentage
-- from Register
-- group by contest_id
-- order by percentage desc, contest_id asc;


select contest_id,
round(count(distinct user_id)*100 / (select count(user_id) from users), 2)as percentage
from register
group by contest_id
order by percentage desc, contest_id asc