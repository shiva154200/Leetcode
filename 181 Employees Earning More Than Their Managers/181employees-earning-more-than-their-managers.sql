# Write your MySQL query statement below
-- select name as Employee from 
-- Employee as E1 where 
-- salary>(select salary from Employee as E2 
-- where
-- E1.managerId=E2.id);


SELECT E1.name AS Employee
FROM Employee E1
JOIN Employee E2 
    ON E1.managerId = E2.id
WHERE E1.salary > E2.salary;
