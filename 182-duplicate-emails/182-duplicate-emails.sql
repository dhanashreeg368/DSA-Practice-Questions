/* Write your PL/SQL query statement below */
select email as Email from Person group by email having count(email)>1;