# MySQL Connector Python Cheatsheet

## 1. Connecting to MySQL

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `mysql.connector.connect()` | Establishes a connection to the MySQL database. | `conn = mysql.connector.connect(host='localhost', user='root', password='password', database='test_db')` | Connects to MySQL database. |
| `conn.close()` | Closes the database connection. | `conn.close()` | Connection is closed. |

## 2. Creating a Cursor

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.cursor()` | Creates a cursor object for executing queries. | `cursor = conn.cursor()` | Cursor is created for executing queries. |

## 3. Executing Queries

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query)` | Executes a single SQL query. | `cursor.execute("SELECT * FROM users")` | Executes a SELECT query. |
| `cursor.executemany(query, data)` | Executes multiple queries with data. | `cursor.executemany("INSERT INTO users (name, age) VALUES (%s, %s)", data)` | Executes multiple inserts. |

## 4. Fetching Data

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.fetchone()` | Fetches the next row from the result set. | `row = cursor.fetchone()` | Fetches a single row. |
| `cursor.fetchall()` | Fetches all remaining rows from the result set. | `rows = cursor.fetchall()` | Fetches all rows from the result. |
| `cursor.fetchmany(size)` | Fetches the next `size` rows from the result set. | `rows = cursor.fetchmany(3)` | Fetches 3 rows. |

## 5. Inserting and Updating Data

| Function  | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query, params)` | Executes an SQL INSERT or UPDATE query with parameters. | `cursor.execute("INSERT INTO users (name, age) VALUES (%s, %s)", ('John', 30))` | Inserts data into the `users` table. |
| `conn.commit()` | Commits the current transaction. | `conn.commit()` | Data changes are committed to the database. |

## 6. Transactions

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.commit()` | Commits the current transaction. | `conn.commit()` | Saves changes to the database. |
| `conn.rollback()` | Rolls back the current transaction. | `conn.rollback()` | Rolls back changes to the previous commit. |

## 7. Prepared Statements

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.execute(query, params)` | Executes a query with parameterized values. | `cursor.execute("SELECT * FROM users WHERE id = %s", (1,))` | Executes a query with a bound parameter. |

## 8. Error Handling

| Exception | Description | Example |
|-----------|-------------|---------|
| `mysql.connector.Error` | Base exception class for all MySQL errors. | `except mysql.connector.Error as err:` |
| `mysql.connector.InterfaceError` | Raised for connection-related issues. | `except mysql.connector.InterfaceError:` |
| `mysql.connector.ProgrammingError` | Raised for SQL syntax errors. | `except mysql.connector.ProgrammingError:` |

## 9. Closing Connections and Cursors

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `cursor.close()` | Closes the cursor. | `cursor.close()` | Cursor is closed. |
| `conn.close()` | Closes the connection. | `conn.close()` | Connection is closed. |

## 10. Checking MySQL Connection Status

| Function | Description | Example | Result |
|-------------------|-------------|---------|--------|
| `conn.is_connected()` | Returns `True` if the connection is open. | `if conn.is_connected():` | Checks connection status. |