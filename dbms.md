# SQL Cheat Sheet & Reference Guide

---

## Part 1: Query Cookbook

### Basic SELECT & Filtering

**1. Retrieve all columns from the Employees table.**
```sql
SELECT * FROM Employees;
```

**2. Get names and salaries of employees from the IT department.**
```sql
SELECT first_name, last_name, salary 
FROM Employees 
WHERE department = 'IT';
```

**3. Show employees with salary greater than 60,000.**
```sql
SELECT * FROM Employees 
WHERE salary > 60000;
```

**4. List employees who joined after 2022-01-01.**
```sql
SELECT * FROM Employees 
WHERE join_date > '2022-01-01';
```

**5. Get all distinct department IDs from Employees.**
```sql
SELECT DISTINCT department_id 
FROM Employees;
```

### Sorting & Limiting

**6. Show employees sorted by salary in descending order.**
```sql
SELECT * FROM Employees 
ORDER BY salary DESC;
```

**7. Get the top 3 highest-paid employees.**
```sql
-- Note: Use TOP 3 in SQL Server
SELECT * FROM Employees 
ORDER BY salary DESC 
LIMIT 3;
```

### Aggregate Functions

**8. Count total employees.**
```sql
SELECT COUNT(*) AS total_employees 
FROM Employees;
```

**9. Find average salary in each department.**
```sql
SELECT department_id, AVG(salary) AS average_salary 
FROM Employees 
GROUP BY department_id;
```

**10. Find the maximum salary in the company.**
```sql
SELECT MAX(salary) AS highest_salary 
FROM Employees;
```

### Joins
*(Assuming a Departments table exists with a `department_id` and `department_name`)*

**11. Show each employee’s name along with their department name.**
```sql
SELECT e.first_name, e.last_name, d.department_name
FROM Employees e
JOIN Departments d ON e.department_id = d.department_id;
```

**12. List employees with their manager's name.**
*(Requires a Self Join, assuming Employees has a `manager_id` column)*
```sql
SELECT e1.first_name AS Employee_Name, e2.first_name AS Manager_Name
FROM Employees e1
LEFT JOIN Employees e2 ON e1.manager_id = e2.emp_id;
```

### Subqueries

**13. Find employees earning more than the average salary.**
```sql
SELECT first_name, last_name, salary 
FROM Employees 
WHERE salary > (SELECT AVG(salary) FROM Employees);
```

**14. Get the department name of the highest-paid employee.**
```sql
SELECT department_name 
FROM Departments 
WHERE department_id = (
    SELECT department_id 
    FROM Employees 
    ORDER BY salary DESC 
    LIMIT 1
);
```

### String & Date Functions

**15. Show employee names in uppercase.**
```sql
SELECT UPPER(first_name), UPPER(last_name) 
FROM Employees;
```

**16. Get the year of joining for each employee.**
```sql
-- MySQL Syntax
SELECT first_name, YEAR(join_date) AS join_year 
FROM Employees;

-- PostgreSQL/Standard Syntax
-- SELECT first_name, EXTRACT(YEAR FROM join_date) AS join_year FROM Employees;
```

### Orders Table Queries
*(Assuming an Orders table with `order_id`, `customer_id`, `order_date`, and `amount`)*

**17. Show all orders placed in August 2024.**
```sql
SELECT * FROM Orders 
WHERE order_date >= '2024-08-01' AND order_date < '2024-09-01';
```

**18. Find the total sales amount.**
```sql
SELECT SUM(amount) AS total_sales 
FROM Orders;
```

**19. Get the customer who spent the most.**
```sql
SELECT customer_id, SUM(amount) AS total_spent 
FROM Orders 
GROUP BY customer_id 
ORDER BY total_spent DESC 
LIMIT 1;
```

**20. List customers who placed more than one order.**
```sql
SELECT customer_id, COUNT(order_id) AS order_count 
FROM Orders 
GROUP BY customer_id 
HAVING COUNT(order_id) > 1;
```

### Advanced / Miscellaneous Queries

**Get the system date in MySQL:**
```sql
SELECT CURDATE();  -- Returns 'YYYY-MM-DD'
SELECT NOW();      -- Returns 'YYYY-MM-DD HH:MM:SS'
```

**Print alternate tuples (rows):**
*(Using a window function combined with a modulo operator)*
```sql
-- Print Odd Rows
SELECT * FROM (
    SELECT *, ROW_NUMBER() OVER(ORDER BY emp_id) AS row_num 
    FROM Employees
) subquery 
WHERE row_num % 2 <> 0;

-- Print Even Rows
SELECT * FROM (
    SELECT *, ROW_NUMBER() OVER(ORDER BY emp_id) AS row_num 
    FROM Employees
) subquery 
WHERE row_num % 2 = 0;
```

**Fetch the second highest salary from a table:**
```sql
-- Using a Subquery:
SELECT MAX(salary) 
FROM Employees 
WHERE salary < (SELECT MAX(salary) FROM Employees);

-- Using LIMIT and OFFSET (MySQL/PostgreSQL):
SELECT DISTINCT salary 
FROM Employees 
ORDER BY salary DESC 
LIMIT 1 OFFSET 1;

-- Using a Window Function (DENSE_RANK):
SELECT salary FROM (
    SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) AS rank_num 
    FROM Employees
) subquery
WHERE rank_num = 2 
LIMIT 1;
```

---

## Part 2: Core Database Concepts

### 1. Joins Explained
Joins combine data from two or more tables based on a related column.

* **INNER JOIN:** Returns only the rows where there is a match in both tables.
* **LEFT JOIN:** Returns all rows from the left table, and the matched rows from the right table (unmatched right rows become `NULL`).
* **RIGHT JOIN:** Returns all rows from the right table, and the matched rows from the left table.
* **FULL OUTER JOIN:** Returns all rows when there is a match in either the left or the right table.

### 2. Applied Practical Queries

**Find the number of employees in each department:**
```sql
SELECT department_id, COUNT(*) AS num_employees 
FROM employees 
GROUP BY department_id;
```

**Find employees who earn more than the average salary:**
```sql
SELECT first_name, last_name, salary 
FROM employees 
WHERE salary > (SELECT AVG(salary) FROM employees);
```

**Fetch the top 3 highest-paid employees (Using Window Function):**
```sql
SELECT * FROM (
    SELECT *, RANK() OVER(ORDER BY salary DESC) AS rank_num 
    FROM employees
) subquery 
WHERE rank_num <= 3;
```

### 3. Keys
Keys are used to identify rows uniquely and establish relationships between tables.

* **Super Key:** Any combination of columns that can uniquely identify a row.
* **Candidate Key:** A minimal Super Key (no unnecessary columns). A table can have multiple.
* **Primary Key (PK):** The specific Candidate Key chosen by the database designer to uniquely identify rows.
* **Alternate Key:** Any Candidate Key that was not chosen as the Primary Key.
* **Composite Key:** A Primary Key made up of two or more columns combined.
* **Foreign Key (FK):** A column (or columns) in one table that references the Primary Key in another table, creating a relationship.

### 4. Constraints & Keywords

* **PRIMARY KEY vs. UNIQUE:** Both ensure data is not duplicated. However, a `PRIMARY KEY` does not allow `NULL` values (and you can only have one per table). A `UNIQUE` constraint allows `NULL` values (and you can have multiple per table).
* **UNION vs. UNION ALL:** Both combine rows from two queries. `UNION` scans for and removes exact duplicates. `UNION ALL` keeps duplicates (which makes it run faster).
* **DISTINCT:** Used in a `SELECT` statement to return only unique, non-duplicate values.
* **GROUP BY:** Groups rows that have the same values in specified columns into summary rows (e.g., calculating the `SUM` or `COUNT` for each specific department).
* **WHERE vs. HAVING:** * `WHERE` filters individual rows *before* any grouping or aggregation takes place. It cannot be used with aggregate functions.
    * `HAVING` filters groups *after* the `GROUP BY` clause has been applied. It is specifically designed to be used with aggregate functions.

### 5. Database Structure & Architecture

* **Tuples and Attributes:** In relational database theory, a Tuple is a row (a single record), and an Attribute is a column (a field).
* **VIEW:** A virtual table based on the result set of an SQL statement. It doesn't store data itself; it just saves a complex query so you can query it like a regular table.
* **ERD (Entity-Relationship Diagram):** A flowchart-like diagram that visually illustrates how "entities" (tables) relate to each other within a system.

**Relationships in a DBMS:**
* **One-to-One (1:1):** One record in Table A relates to only one record in Table B (e.g., Employee and ID Badge).
* **One-to-Many (1:N):** One record in Table A relates to many in Table B (e.g., Department and Employees).
* **Many-to-Many (M:N):** Many records in Table A relate to many in Table B (e.g., Students and Classes). Requires a third "junction" table to function in SQL.

### 6. DELETE vs. TRUNCATE vs. DROP

* **DELETE (DML):** Removes specific rows based on a `WHERE` clause. It is logged in the transaction history and can usually be rolled back.
* **TRUNCATE (DDL):** Instantly empties all data from a table, but leaves the table structure intact. It resets auto-incrementing IDs and is much faster than `DELETE`. Usually cannot be rolled back.
* **DROP (DDL):** Completely destroys the table structure, its data, constraints, and indexes from the database permanently.

### 7. Normalization
Normalization is the process of organizing data to minimize redundancy (duplicate data) and prevent data anomalies.

* **1st Normal Form (1NF):** Every column must hold atomic (indivisible) values. No comma-separated lists in a single cell.
* **2nd Normal Form (2NF):** Must be in 1NF, and all non-key columns must depend on the entire primary key (eliminates partial dependency).
* **3rd Normal Form (3NF):** Must be in 2NF, and no non-key column can depend on another non-key column (eliminates transitive dependency).

### 8. Performance & Transactions

**Indexes:**
An index is a data structure (like an index at the back of a book) that speeds up data retrieval.
* **Clustered Index:** Dictates the actual physical sorting order of the data on the disk. You can only have one clustered index per table (usually the Primary Key).
* **Non-Clustered Index:** A separate structure from the data that contains pointers to the physical rows. You can have multiple non-clustered indexes per table.

**ACID Properties:**
The four rules that guarantee database transactions are processed reliably:
* **Atomicity:** "All or nothing." A transaction either fully completes or fully fails.
* **Consistency:** The database must remain in a valid state before and after the transaction (all constraints must be met).
* **Isolation:** Concurrent transactions must not interfere with each other.
* **Durability:** Once a transaction is committed, it is saved permanently, even if the database crashes.

**OLTP vs. OLAP:**
* **OLTP (Online Transaction Processing):** Designed for fast, short, real-time inserts/updates (e.g., e-commerce checkout, ATMs). Highly normalized.
* **OLAP (Online Analytical Processing):** Designed for complex queries, data mining, and reading massive amounts of historical data (e.g., calculating YoY sales). Uses denormalized data warehouses.

### 9. Miscellaneous Concepts

**SQL vs. NoSQL**

| Feature | SQL (Relational) | NoSQL (Non-Relational) |
| :--- | :--- | :--- |
| **Data Storage** | Stored in structured tables with defined schemas. | Stored in flexible formats (JSON, key-value, graphs). |
| **Relationships** | Uses primary/foreign keys to link data. | Dynamic schemas; less emphasis on strict relations. |
| **Scaling** | Scales vertically (adding power to a single server). | Scales horizontally (adding more servers). |
| **Best For** | Complex queries, transactional consistency (ACID). | Massive unstructured data, rapid development. |
| **Examples** | MySQL, PostgreSQL, SQL Server. | MongoDB, Redis, Cassandra. |

**Pattern Matching (Wildcards):**
Using the `LIKE` operator to search for specific character patterns.
* `%` represents zero, one, or multiple characters (e.g., `LIKE 'A%'` finds all names starting with A).
* `_` represents exactly one single character (e.g., `LIKE 'J_n'` finds 'Jon', 'Jan', but not 'John').

**SQL Sublanguages:**
* **DDL (Data Definition Language):** Defines structure (`CREATE`, `ALTER`, `DROP`, `TRUNCATE`).
* **DML (Data Manipulation Language):** Manipulates data (`SELECT`, `INSERT`, `UPDATE`, `DELETE`).
* **DCL (Data Control Language):** Manages permissions (`GRANT`, `REVOKE`).
* **TCL (Transaction Control Language):** Manages transactions (`COMMIT`, `ROLLBACK`, `SAVEPOINT`).