# Write your MySQL query statement below
select s.user_id, 
round(avg(if(c.action = 'confirmed', 1,0)),2) as confirmation_rate
#ifnull(round(sum(c.action='confirmed')/count(*),2),0.00) as confirmation_rate
from Signups s
left join Confirmations c
on s.user_id = c.user_id
group by s.user_id
