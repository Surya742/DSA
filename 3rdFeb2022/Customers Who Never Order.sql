-- Customers Who Never Order
-- SQL Schema
-- Table: Customers

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table indicates the ID and name of a customer.
 

-- Table: Orders

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | customerId  | int  |
-- +-------------+------+
-- id is the primary key column for this table.
-- customerId is a foreign key of the ID from the Customers table.
-- Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
 

-- Write an SQL query to report all customers who never order anything.

-- Return the result table in any order.

-- Prob Link: https://leetcode.com/problems/customers-who-never-order/

-- # Write your MySQL query statement below
select name as Customers from Customers where Customers.id NOT IN (select customerId from Orders);