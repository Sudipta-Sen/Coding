# Java JDBC with MySQL CheatSheet

## 1. Setting up the MySQL Connector JAR

- Download the MySQL Connector JAR file (e.g., `mysql-connector-java-8.x.x.jar`).
- Add it to  project's classpath.

## 2. Required Libraries

```Java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;
```

## 3. Load Driver
In mysql the driver name is `Driver` which is present in the package `com.mysql.jdbc`. There are two methods to load the driver

**Method1:** 
```Java
Class.forName(<name_of_the_driver>)
```

Example:
```Java
Class.forName("com.mysql.jdbc.Driver")
```

**Method2:**
```Java
DriverManager.registerDriver(new <name_of_the_driver>)
```

Example:
```Java
DriverManager.registerDriver(new com.mysql.jdbc.Driver())
```

## 4. Database Connection Setup

### a. Connection URL Format:
```Java
String url = "jdbc:mysql://<hostname>:<port>/<database_name>?useSSL=false";
```

Example:
`mydatabase` is the name of the database, I am using.
```Java
String url = "jdbc:mysql://localhost:3306/mydatabase?useSSL=false";
```

### b. Connection Setup:
`getConnection` is a static method
```Java
String username = "root";
String password = "password";

Connection connection = DriverManager.getConnection(url, username, password);
```

## 5. Creating a Statement

### a. Basic Statement
Executes static SQL queries (hard-coded or built dynamically) where you directly concatenate values in the query.

```Java
Statement stmt = connection.createStatement();
String query = "SELECT * FROM users WHERE id = " + 1;
ResultSet rs = stmt.executeQuery(query);

```

### b. Prepared Statement
Executes precompiled SQL queries with placeholders (?) for values. You set these values using setter methods (e.g., setInt(), setString())

```Java
String query = "SELECT * FROM users WHERE username = ?";
PreparedStatement pstmt = connection.prepareStatement(query);
pstmt.setString(1, "sudipta");  // Sets the first `?` to the value sudipta
```

PreparedStatement supports batch updates. You can reuse the same query with different parameters multiple times in a batch

```Java
String query = "INSERT INTO users (name, email) VALUES (?, ?)";
PreparedStatement pstmt = connection.prepareStatement(query);
connection.setAutoCommit(false);

for (int i = 0; i < 1000; i++) {
    pstmt.setString(1, "User" + i);
    pstmt.setString(2, "user" + i + "@example.com");
    pstmt.addBatch();
}

pstmt.executeBatch();
connection.commit();

```

### c. Statement vs PreparedStatement

| Feature |	Statement |	PreparedStatement |
| ------- | --------- | ----------------- |
| SQL Query | Static, with direct concatenation |	Precompiled, with placeholders (?) |
| SQL Injection Vulnerability |	Vulnerable |	Protects against SQL injection |
| Performance |	Less efficient for repetitive queries	|Better for repeated execution |
| Batch Processing	| No batch support |	Supports batch execution |
| Use Case	| Simple, one-time queries	| Frequently executed or dynamic queries |

## 6. Execute Queries

### a. Execute a SELECT Query
```Java
ResultSet resultSet = statement.executeQuery("SELECT * FROM users");
while (resultSet.next()) {
    System.out.println(resultSet.getString("username"));
}
```

### b. Execute an INSERT/UPDATE/DELETE Query
```Java
int rowsAffected = statement.executeUpdate("UPDATE users SET name = 'John' WHERE id = 1");
```

### c. Execute with PreparedStatement
```Java
String insertQuery = "INSERT INTO users (name, email) VALUES (?, ?)";
PreparedStatement pstmt = connection.prepareStatement(insertQuery);
pstmt.setString(1, "John");
pstmt.setString(2, "john@example.com");
int rows = pstmt.executeUpdate();
```

```java
String query = "SELECT id, username, email, location FROM users WHERE location = ?";
PreparedStatement pstmt = connection.prepareStatement(query)
// Set the parameter in the query (location = Kirnahar)
pstmt.setString(1, "Kirnahar");

// Execute the query
ResultSet resultSet = pstmt.executeQuery();

while (resultSet.next()) {
    int id = resultSet.getInt("id");
    String user = resultSet.getString("username");
    String email = resultSet.getString("email");

    // Display the data
    System.out.println("ID: " + id);
    System.out.println("Username: " + user);
    System.out.println("Email: " + email);
}
```

## 7. Transaction Management
### a. Disabling Auto-Commit (start transaction)

```Java
connection.setAutoCommit(false);
```

### b. Committing a Transaction

```Java
connection.commit();
```

### c. Rolling Back a Transaction
```Java
connection.rollback();
```

## 7. Closing Resources

Always close `Connection`, `Statement`, and `ResultSet` objects to avoid memory leaks:

```Java
if (resultSet != null) resultSet.close();
if (statement != null) statement.close();
if (connection != null) connection.close();
```

## 8. Common SQL Exceptions

- `SQLException`: Catch this to handle SQL-related errors.
- `SQLIntegrityConstraintViolationException`: Occurs when you try to insert duplicate keys.
- `SQLSyntaxErrorException`: Syntax error in the SQL query.

## 9. Summary
Here is a summary of the whole flow

- **`Load the JDBC Driver:`** There are two methods available to load the JDBC driver.
    - `Class.forName(<name_of_the_driver>)`
    - `DriverManager.registerDriver(new <name_of_the_driver>)`

- **`Create a Query:`** Query can be created using one of the following:
    - `Statement`
    - `PreparedStatement`
    - `CallableStatement`

- **`Execute the Query:`** Depending on the type of query:
    - Use `executeQuery()` for `SELECT` queries, which returns a `ResultSet`.
    - Use `executeUpdate()` for `INSERT`, `UPDATE`, or `DELETE` queries, which returns an `integer` representing the number of affected rows.

- **`Process the Result:`** 
    - If the query is a `SELECT` query, process the `ResultSet`.
    - For `INSERT`, `UPDATE`, or `DELETE` queries, processing the result is not required.