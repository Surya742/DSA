-- // Department Highest Salary

-- SQL Schema
-- Table: Employee

-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | id           | int     |
-- | name         | varchar |
-- | salary       | int     |
-- | departmentId | int     |
-- +--------------+---------+
-- id is the primary key column for this table.
-- departmentId is a foreign key of the ID from the Department table.
-- Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.

-- Prob link: https://leetcode.com/problems/department-highest-salary/

select d.Name Department, e.Name Employee, Salary
from Department d join Employee e on d.Id=e.DepartmentId
where (Salary,d.id) in (select max(Salary),DepartmentId from Employee group by DepartmentId);