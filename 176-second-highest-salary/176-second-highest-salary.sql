/* Write your PL/SQL query statement below */
select max(salary) SecondHighestSalary from Employee where Salary<(select max(salary) from employee);