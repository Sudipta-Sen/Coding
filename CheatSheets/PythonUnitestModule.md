# Python unittest Module

Python’s `unittest` module (sometimes referred to as “PyUnit”) is a built-in framework designed to support writing and running tests. It provides a way to organize test cases, automate test execution, and ensure that your code behaves as expected.

## Basic Concepts

1. **Test Case:** The individual unit of testing. A test case checks a specific response to a particular set of inputs.

2. **Test Suite:** A collection of test cases, test suites, or both.

3. **Test Runner:** A component that orchestrates the execution of tests and provides the outcome to the user (like printing the result).

4. **Test Fixture:** Setup or teardown code that runs before or after a test (like opening/closing a database connection).

## Basic Usage

We define test cases by creating classes that inherit from `unittest.TestCase`, then use methods like `assertEqual`, `assertTrue`, and others to perform checks.

- **Basic Example:**
    ```Python
    import unittest

    # Code to be tested
    def add(a, b):
        return a + b

    def subtract(a, b):
        return a - b

    # Test cases
    class TestMathOperations(unittest.TestCase):

        def test_add(self):
            self.assertEqual(add(10, 5), 15)
            self.assertEqual(add(-1, 1), 0)

        def test_subtract(self):
            self.assertEqual(subtract(10, 5), 5)
            self.assertEqual(subtract(5, 5), 0)

    if __name__ == '__main__':
        unittest.main()
    ```

- **Explanation:**

    1. **Inheriting from unittest.TestCase:** You create test cases by subclassing unittest.TestCase.

    2. **Test Methods:** Methods that start with test_ are recognized by the framework as test methods.

    3. **Assertions:** You use assertion methods like assertEqual to validate the expected behavior.

## Common Assertions

Assertions are methods that check whether the given condition is `True`. If it’s not, the test fails.

- `assertEqual(a, b)` - Check that `a == b`
- `assertNotEqual(a, b)` - Check that `a != b`
- `assertTrue(x)` - Check that `x` is `True`
- `assertFalse(x)` - Check that `x` is `False`
- `assertIs(a, b)` - Check that `a is b`
- `assertIsNot(a, b)` - Check that `a is not b`
- `assertIsNone(x)` - Check that `x is None`
- `assertIsNotNone(x)` - Check that `x is not None`
- `assertIn(a, b)` - Check that `a is in b`
- `assertNotIn(a, b)` - Check that `a is not in b`
- `assertRaises(exception)` - Test that an exception is raised

- Example:

    ```Python
    def divide(a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero!")
        return a / b

    class TestMathOperations(unittest.TestCase):

        def test_divide(self):
            self.assertEqual(divide(10, 2), 5)
            self.assertRaises(ValueError, divide, 10, 0)
    ```

## Test Fixtures (setUp and tearDown)

In many test cases, we need to perform setup before each test and cleanup after each test. This is handled using the `setUp` and `tearDown` methods.

- Example:

    ```Python
    class TestOperations(unittest.TestCase):

        def setUp(self):
            print("Setting up before the test")
            self.data = [1, 2, 3]

        def tearDown(self):
            print("Tearing down after the test")
            self.data = None

        def test_dummy(self):
            self.assertEqual(sum(self.data), 6)
    ```

- Output:
    ```bash
    sudipta@WSL:Snippets (main)$ python3 thread8.py 
    Setting up before the test
    Tearing down after the test
    .
    ----------------------------------------------------------------------
    Ran 1 test in 0.000s

    OK
    ```

## Skipping Tests and Expected Failures

We can skip tests using the `@unittest.skip` decorator or mark them as "expected to fail."

```Python
class TestMathOperations(unittest.TestCase):

    @unittest.skip("Skipping this test temporarily")
    def test_add(self):
        self.assertEqual(add(10, 5), 15)

    @unittest.skipIf(1 < 2, "Skipping because the condition is true")
    def test_subtract(self):
        self.assertEqual(subtract(10, 5), 5)

    @unittest.expectedFailure
    def test_fail(self):
        self.assertEqual(add(10, 5), 20)  # This will fail, but it's marked as expected failure
```

## Running Tests

We can run the tests by executing the script directly:

```bash
python test_script.py
```

Or, we can use the command line:

```bash
python -m unittest test_script.py
```

## Mocking with `unittest.mock`

The `unittest.mock` library is used to replace parts of your system under test with mock objects and make assertions about how they are used.

- Example: `Mocking print`

    ```Python
    from unittest.mock import patch

    class TestPrint(unittest.TestCase):

        @patch('builtins.print')  # Mock the built-in print function
        def test_print(self, mock_print):
            print("Hello, World!")
            mock_print.assert_called_once_with("Hello, World!")
    ```

    Here, the `print` function is replaced by a mock object, and we check that it was called with specific arguments.

### Key Features of MagicMock

- Simulating Method Calls

    We can mock methods and define what they should return when called:

    ```Python
    mock_object = MagicMock()
    mock_object.some_method.return_value = 42

    print(mock_object.some_method())  # Output: 42
    ```

    We can also assert whether a method was called during the test:

    ```Python
    mock_object.some_method()
    mock_object.some_method.assert_called_once()  # Passes since the method was called once
    ```

- Handling Magic Methods

    `MagicMock` automatically handles Python's magic methods, which are methods with double underscores (e.g., `__getitem__`, `__call__`, etc.). This makes it ideal for mocking objects that need to behave like collections, context managers, or other special Python constructs.

    For example, mocking an object that behaves like a list:
    ```Python
    mock_list = MagicMock()
    mock_list.__getitem__.return_value = 'mocked item'

    print(mock_list[0])  # Output: mocked item
    ```

- Attributes and Properties

    We can mock object attributes and even properties:
    ```Python
    mock_object = MagicMock()
    mock_object.some_attribute = "mocked attribute"

    print(mock_object.some_attribute)  # Output: mocked attribute
    ```

    We can also mock properties using the `@property` decorator:
    ```Python
    class MyClass:
    @property
    def my_property(self):
        return "real value"

    mock_object = MagicMock(spec=MyClass)
    mock_object.my_property = "mocked value"

    print(mock_object.my_property)  # Output: mocked value
    ```

-  Mocking Return Values and Side Effects

    We can specify what a mock method should return using return_value or simulate various behaviors using side_effect:

    - **Return Values:** Define a specific value that the mock should return when called.
        ```Python
        mock_object.some_method.return_value = "Hello"
        print(mock_object.some_method())  # Output: Hello
        ```
    
    - **Side Effects:** Simulate multiple behaviors, exceptions, or sequences of return values.
        ```Python
        mock_object.some_method.side_effect = [1, 2, 3]
        print(mock_object.some_method())  # Output: 1
        print(mock_object.some_method())  # Output: 2

        # Raising an exception as a side effect
        mock_object.some_method.side_effect = Exception("Error occurred")
        ```
    
- Chaining Method Calls
    
    We can easily mock chained method calls, which are common when working with libraries like SQLAlchemy or Django ORM.
    ```Python
    mock_object.some_method.return_value.another_method.return_value = "mocked value"
    print(mock_object.some_method().another_method())  # Output: mocked value
    ```

###  Common Use Cases for MagicMock

- **Mocking Functions in Unit Tests**

    We can mock individual functions or methods to isolate what we're testing and avoid unwanted side effects.

    ```Python
    from unittest.mock import MagicMock

    def process_data(reader):
        data = reader.read()
        # process data...
        return data

    # Mocking the reader object
    mock_reader = MagicMock()
    mock_reader.read.return_value = "mocked data"
    result = process_data(mock_reader)

    print(result)  # Output: mocked data
    mock_reader.read.assert_called_once()  # Ensures the read() method was called exactly once
    ```

- **Mocking External Dependencies:**

    If our code depends on external systems (e.g., databases, APIs, files), we can use `MagicMock` to simulate those dependencies.

    For instance, mocking a database call:
    ```Python
    mock_db = MagicMock()
    mock_db.get_user.return_value = {"name": "John", "age": 30}

    print(mock_db.get_user(123))  # Output: {'name': 'John', 'age': 30}
    ```

- **Mocking Objects with Magic Methods:**

    When we need to mock objects like dictionaries, lists, or context managers (which rely on magic methods), `MagicMock` comes in handy:

    ```Python
    mock_file = MagicMock()
    mock_file.__enter__.return_value = "mocked content"

    with mock_file as f:
    print(f)  # Output: mocked content
    ```
### Common Assertions with MagicMock

`MagicMock` provides several useful assertion methods:

- `assert_called():` Verifies that the mock was called at least once.
- `assert_called_once():` Verifies that the mock was called exactly once.
- `assert_called_with(*args, **kwargs):` Verifies that the mock was called with the specified arguments.
- `assert_not_called():` Verifies that the mock was not called.
- `assert_any_call(*args, **kwargs):` Verifies that the mock was called with the specified arguments at least once.

### Best Practices for Using MagicMock

- **Use `spec` to Match the Real Object:** Use `spec` to ensure the mock object only allows methods and attributes of the real object you’re mocking. This helps avoid errors from using non-existent methods.

    ```Python
    real_obj = SomeClass()
    mock_obj = MagicMock(spec=real_obj)

    # Now mock_obj can only have methods/attributes that real_obj has
    ```

- **Use Assertions to Verify Behavior:** Always verify that the mocks were called as expected using methods like `assert_called_once`, `assert_called_with`, etc.

    ```Python
    mock_function.assert_called_with(expected_arg)
    ```

- **Avoid Over-Mocking:** Focus on mocking external dependencies or complex objects, but avoid over-mocking your own business logic as it may obscure the behavior you're testing.


## patch: A Detailed Guide

The `patch` function in Python’s `unittest.mock` module is a powerful tool used to temporarily replace an object, method, or attribute in your code during testing. This is particularly useful when you want to mock or modify external dependencies or certain parts of your code without permanently altering the source code.

Importing patch:
```Python
from unittest.mock import patch
```

### 1. How patch Works

The `patch` function replaces the specified object with a mock (usually a `MagicMock`) during the scope of the test. After the test is done, `patch` restores the original object.

You can patch:

- **Modules:** For example, you can patch functions or classes from a module.
- **Methods:** Temporarily replace methods within a class.
- **Attributes:** Mock class or instance attributes.

### 2. Using patch
There are multiple ways to use `patch`:

- As a Context Manager:
    
    We can use `patch` in a `with` statement, which temporarily replaces the object within the context of the block.

    ```Python
    from unittest.mock import patch, MagicMock

    def some_function():
        return external_dependency()

    # Patch the external function
    with patch('module_containing_function.external_dependency', return_value='mocked value'):
        result = some_function()

    print(result)  # Output: mocked value
    ```

    Here, `external_dependency()` is replaced by a mock that returns `"mocked value"` during the test.

- **As a Decorator:**

    We can use `patch` as a decorator for a test function, replacing the object for the duration of the function.

    ```Python
    @patch('module_containing_function.external_dependency', return_value='mocked value')
    def test_some_function(mock_external):
        result = some_function()
        assert result == 'mocked value'
    ```

    The decorator form provides a cleaner approach, especially when you need to patch multiple objects within a function.

- With `patch.object`:

    `patch.object` is used to patch specific attributes or methods of an object or class, instead of a module-level patch.
    ```Python
    class MyClass:
        def method(self):
            return "real value"

    with patch.object(MyClass, 'method', return_value="mocked value"):
        instance = MyClass()
        print(instance.method())  # Output: mocked value
    ```

- `patch` with Multiple Mocks:

    We can use multiple `patch` decorators or context managers to mock multiple objects simultaneously.

    ```Python
    @patch('module1.function1')
    @patch('module2.function2')
    def test_something(mock_func2, mock_func1):
        mock_func1.return_value = "mocked value 1"
        mock_func2.return_value = "mocked value 2"
        # Test code using both mocked functions
    ```

### 3. What to Patch?

When patching, it's important to patch the **right location**—typically where the object is used rather than where it is defined. This ensures that the code under test uses the mock instead of the real object.

For example:

- If `some_function()` imports `external_dependency` from `module_containing_function`, you should patch `'module_containing_function.external_dependency'`, not the original definition of `external_dependency`.


### 4. Common Use Cases for patch

- **Mocking External APIs:** Patch network calls, like HTTP requests, to avoid making real network requests during tests.

    ```Python
    @patch('requests.get')
    def test_fetch_data(mock_get):
        mock_get.return_value.status_code = 200
        mock_get.return_value.json.return_value = {"data": "mocked data"}
        result = fetch_data()
        assert result == {"data": "mocked data"}
    ```

- **Mocking File I/O:** Patch file reading/writing functions to simulate reading from or writing to a file without creating actual files.

    ```Python
    @patch('builtins.open', new_callable=mock_open, read_data="mocked file content")
    def test_read_file(mock_open):
        with open('somefile.txt', 'r') as f:
            data = f.read()
        assert data == "mocked file content"
    ```

- **Mocking Time or Sleep Functions:** Patch functions like `time.sleep()` to avoid slowing down your tests.

    ```Python
    @patch('time.sleep', return_value=None)
    def test_time_sensitive_code(mock_sleep):
        # Code that uses time.sleep()
    ```