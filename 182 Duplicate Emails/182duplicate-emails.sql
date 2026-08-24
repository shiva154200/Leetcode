# Write your MySQL query statement below
select email from 
(select email ,count(email) as emails
from Person group by email) as t2
where  emails>1;
