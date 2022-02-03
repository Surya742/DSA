-- Delete Duplicate Emails
-- SQL Schema
-- Table: Person

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | email       | varchar |
-- +-------------+---------+
-- id is the primary key column for this table.
-- Each row of this table contains an email. The emails will not contain uppercase letters.
 

-- Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id. Note that you are supposed to write a DELETE statement and not a SELECT one.

-- Return the result table in any order.

-- Prob Link: https://leetcode.com/problems/delete-duplicate-emails/

-- # Write your MySQL query statement below
delete p1 from Person p1, Person p2 where p1.Email = p2.Email and p1.Id>p2.Id;