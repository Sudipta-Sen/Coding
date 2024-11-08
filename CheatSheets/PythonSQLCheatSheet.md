# MySQL Connector Python Cheatsheet

## 1. Package required
- mysql-connector-python

```shell
pip install mysql-connector-python
```

```Python
import mysql.connector
```

## 2. Connecting to MySQL

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `mysql.connector.connect()` | Establishes a connection to the MySQL database. | `conn = mysql.connector.connect(host='localhost', user='root', password='password', database='test_db')` | Connects to MySQL database. |
| `mysql.connector.connect()` |  If the `database` parameter is not provided, the connection defaults to the MySQL server level, allowing you to `create`, `view`, or `delete` databases. | Example below |
| `conn.close()` | Closes the database connection. | `conn.close()` | Connection is closed. |

```Python
import mysql.connector

# Connect to MySQL server without specifying a database
connection = mysql.connector.connect(
    host="localhost",
    user="your_username",
    password="your_password"
)

cursor = connection.cursor()

# Example: Create a new database
cursor.execute("CREATE DATABASE my_new_db")

# Example: List all databases
cursor.execute("SHOW DATABASES")
for db in cursor:
    print(db)

# Example: Delete a database
cursor.execute("DROP DATABASE my_new_db")

# Close connection
connection.close()
```
- mysql.connector.connect returns a object of type `MySQLConnection`

```Python
from mysql.connector import MySQLConnection
```

## 3. Creating a Cursor

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.cursor()` | Creates a cursor object for executing queries. | `cursor = conn.cursor()` | Cursor is created for executing queries. |

## 4. Executing Queries

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query)` | Executes a single SQL query. | `cursor.execute("SELECT * FROM users")` | Executes a SELECT query. |
| `cursor.executemany(query, data)` | Executes multiple queries with data. | `cursor.executemany("INSERT INTO users (name, age) VALUES (%s, %s)", data)` | Executes multiple inserts. |
```Python
sqlFormula = "INSERT INTO users (name, age) VALUES (%s, %s)"
students = [
    ("Sudipta", 30),
    ("Nikhil", 22),
    ("Sourav", 36)
]
cursor.executemany(sqlFormula, students)
cursor.commit()
```

## 5. Fetching Data

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.fetchone()` | Fetches the next row from the result set. | `row = cursor.fetchone()` | Fetches a single row. |
| `cursor.fetchall()` | Fetches all remaining rows from the result set. | `rows = cursor.fetchall()` | Fetches all rows from the result. |
| `cursor.fetchmany(size)` | Fetches the next `size` rows from the result set. | `rows = cursor.fetchmany(3)` | Fetches 3 rows. |

## 6. Inserting and Updating Data

| Function  | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query, params)` | Executes an SQL INSERT or UPDATE query with parameters. | `cursor.execute("INSERT INTO users (name, age) VALUES (%s, %s)", ('John', 30))` | Inserts data into the `users` table. |
| `conn.commit()` | Commits the current transaction. | `conn.commit()` | Data changes are committed to the database. |

## 7. Transactions

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.commit()` | Commits the current transaction. | `conn.commit()` | Saves changes to the database. |
| `conn.rollback()` | Rolls back the current transaction. | `conn.rollback()` | Rolls back changes to the previous commit. |

Explanation:
- DDL Operations: No `commit()` needed (e.g., `CREATE DATABASE`, `CREATE TABLE`).
- DML Operations: Always use `connection.commit()` to make sure your changes (insert/update/delete) are saved in the database.
- Transaction Rollback: If an error occurs during a DML operation, you can call `connection.rollback()` to undo any changes made during that transaction.

## 8. Prepared Statements

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query, params)` | Executes a query with parameterized values. | <li>`cursor.execute("SELECT * FROM users WHERE id = %s", (1,))`</li> <li>`cursor.execute("SELECT * FROM users WHERE id = %s AND name = %s AND age = %s", (1, 'John', 25))`</li>| Executes a query with a bound parameter. It prevents from SQL Injection|

- Parameterized queries with placeholders (`%s`) are typically used for values in `INSERT`, `UPDATE`,`DELETE`, or `SELECT` statements but not for database or table names like `CREATE DATABASE`

## 9. Error Handling

| Exception | Description | Example |
|-----------|-------------|---------|
| `mysql.connector.Error` | Base exception class for all MySQL errors. | `except mysql.connector.Error as err:` |
| `mysql.connector.InterfaceError` | Raised for connection-related issues. | `except mysql.connector.InterfaceError:` |
| `mysql.connector.ProgrammingError` | Raised for SQL syntax errors. | `except mysql.connector.ProgrammingError:` |

## 10. Closing Connections and Cursors

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.close()` | Closes the cursor. | `cursor.close()` | Cursor is closed. |
| `conn.close()` | Closes the connection. | `conn.close()` | Connection is closed. |

## 11. Checking MySQL Connection Status

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.is_connected()` | Returns `True` if the connection is open. | `if conn.is_connected():` | Checks connection status. |