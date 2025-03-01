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