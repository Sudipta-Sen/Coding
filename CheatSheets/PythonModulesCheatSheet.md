# CheatSheet for various python modules & important concepts

## Table of Contents
> 1. [Requests Module](#1-requests-module)
>> a. [Get Request](#1-get-request)<br>
>> b. [Post Request](#2-post-request)<br>
>> c. [Send JSON data](#3-sending-json-data-in-post-request)<br>
>> d. [PUT Request](#4-put-request)<br>
>> e. [Delete Request](#5-delete-request)<br>
>> f. [HEAD Request](#6-head-request)<br>
>> g. [Send parameters in GET](#7-sending-parameters-in-get-request)<br>
>> h. [Send headers](#8-sending-headers-with-request)<br>
>> i. [Cookies](#9-working-with-cookies)<br>
>> j. [Upload files](#10-uploading-files)<br>
>> k. [Authentication](#11-authentication)<br>
>> l. [Download](#12-downloading-content)<br>
>> m. [Proxies](#13-proxies)<br>
>> n. [SSL Verification](#14-disable-ssl-verification)<br>
>> o. [Custome timeout](#15-custom-timeout-for-requests)<br>
>> p. [Status Code](#16-common-status-codes)<br>
> 2. [Lambda/Anonymous Function](#2-lambdaanonymous-function)
>> a. [Basic Syntax](#basic-syntax)<br>
>> b. [lambdas with default arguments](#lambdas-with-default-arguments)<br>
>> c. [condition in lambda](#conditional-ternary-in-lambda)
> 3. [Map function](#3-map-function)<br>
>> a. [Map with Lambda](#map-with-lambda-function)<br>
>> b. [Map without Lambda](#map-without-lambda-function)<br>
>> c. [Map with multiple iterables](#map-with-multiple-iterables)
> 4. [Filter function](#4-filter-function)
>> a. [Filter without lambda](#filter-without-lambda)<br>
>> b. [Filter with lambda](#filter-with-lambda)
> 5. [Reduce function](#5-reduce-function)
>> a. [Reduce without lambda](#reduce-without-lambda)<br>
>> b. [Reduce with lambda](#reduce-without-lambda)
> 6. [Multi-threading](#6-multithreading-threading-module)<br>
>> [a. Key Concepts](#key-concepts)<br>
>> [b. Thread Methods](#main-thread-functions)<br>
>> [c. Creating Thread](#creating-threads)<br>
>>> [i. Use thread class directly](#use-thread-class-directly)<br>
>>> [ii. Extending thread class](#creating-threads-by-extending-the-thread-class)

>> [d. Thread naming and identification](#thread-naming-and-identification)<br>

## 1. Requests module

### 1. Get request
- Used to retrive from server

```Python
response = requests.get('https://example.com')
print(response.status_code)  # HTTP Status Code (e.g., 200)
print(response.text)         # Response content (HTML, JSON, etc.)
print(response.json())       # Parse response as JSON (if applicable)
```

### 2. POST Request
- Used to send data to the server (typically for creating or updating).
- Content-Type: `application/x-www-form-urlencoded` (default for data)
```Python
data = {'key1': 'value1', 'key2': 'value2'}
response = requests.post('https://example.com/post', data=data)
print(response.text)  # Response content
```

### 3. Sending JSON Data in POST Request
 - Send JSON in the body of a POST request.
 - Content-Type: `application/json`
```Python
json_data = {'name': 'John', 'age': 30}
response = requests.post('https://example.com/post', json=json_data)
print(response.text)
```

### 4. PUT Request
- Used to update data on the server.
```Python
data = {'key': 'updated_value'}
response = requests.put('https://example.com/put', data=data)
print(response.text)
```

### 5. DELETE Request
- Used to delete data on the server.
```Python
response = requests.delete('https://example.com/delete')
print(response.text)
```
### 6. HEAD Request
- Similar to GET, but retrieves only headers (no body).
```Python
response = requests.head('https://example.com')
print(response.headers)
```

### 7. Sending Parameters in GET Request
- Send query parameters in a URL.
```Python
params = {'key1': 'value1', 'key2': 'value2'}
response = requests.get('https://example.com', params=params)
print(response.url)  # Full URL with parameters
```

### 8. Sending Headers with Request
- Customize headers in your requests.
```Python
headers = {'Authorization': 'Bearer your-token'}
response = requests.get('https://example.com', headers=headers)
print(response.text)
```

### 9. Working with Cookies
- Access and send cookies with requests.
```Python
# Get cookies from a response
response = requests.get('https://example.com')
print(response.cookies)

# Send cookies in a request
cookies = {'session_id': '12345'}
response = requests.get('https://example.com', cookies=cookies)
```

### 10. Uploading Files
- Send files in a POST request.

```Python
files = {'file': open('report.txt', 'rb')}
response = requests.post('https://example.com/upload', files=files)
```

### 11. Authentication
- Send requests with authentication (e.g., basic authentication)

```Python
from requests.auth import HTTPBasicAuth

response = requests.get('https://example.com', auth=HTTPBasicAuth('user', 'pass'))
```

### 12. Downloading Content
- Downloading large files in chunks.

```Python
response = requests.get('https://example.com/file.zip', stream=True)
with open('file.zip', 'wb') as f:
    for chunk in response.iter_content(chunk_size=128):
        f.write(chunk)
```

### 13. Proxies
- Send requests through a proxy.
```Python
proxies = {
    'http': 'http://10.10.1.10:3128',
    'https': 'https://10.10.1.11:1080',
}
response = requests.get('https://example.com', proxies=proxies)
```

### 14. Disable SSL Verification
- Ignore SSL certificate verification.
```Python
response = requests.get('https://example.com', verify=False)
```

### 15. Custom Timeout for Requests
 - Set both connection and read timeout values.
```Python
response = requests.get('https://example.com', timeout=(3.05, 27))
```

- `First value (3.05):` The time to wait for a connection to establish (write timeout).
- `Second value (27):` The time to wait for a response (read timeout).

### 16. Common Status Codes:
- 200: OK
- 201: Created
- 204: No Content
- 400: Bad Request
- 401: Unauthorized
- 403: Forbidden
- 404: Not Found
- 500: Internal Server Error

## 2. Lambda/Anonymous Function 

Lambda functions are small anonymous functions defined with the `lambda` keyword.

### Basic Syntax
```Python
lambda arguments: expression
```
- `arguments:` Input parameters (like in a normal function).
- `expression:` A single expression that is evaluated and returned

Example:
```Python
add = lambda x, y: x + y
print(add(2, 3))  # Output: 5
```

### Lambdas with Default Arguments
```Python
add = lambda x, y=10: x + y
print(add(5))  # Output: 15
print(add(5, 3))  # Output: 8
```

### Conditional (Ternary) in Lambda
```Python
max_value = lambda x, y: x if x > y else y
print(max_value(5, 10))  # Output: 10
```

## 3. Map function
The `map()` function executes the given function to every item of an iterable, such as a `list` or `tuple`, and returns a map object (which is an iterator).

Syntax
```Python
map(function, iterables)
```
- `function:`	The function to execute for each item
- `iterable:` A sequence, collection or an iterator object.
- Returns an iterable object

### Map without lambda function
```Python
a = [1, 2, 3, 4]

def double(val):
  return val*2

res = list(map(double, a))
print(res) # Output: [1, 4, 9, 16]
```
### Map with lambda function
```Python
a = [1, 2, 3, 4]

res = list(map(lambda n:n*n, a))
print(res) # Output: [1, 4, 9, 16]
```

### map() with multiple iterables
```Python
a = [1, 2, 3]
b = [8, 9, 10]

res = list(map(lambda x,y:x+y, a, b))
print(res) #Output: [9, 11, 13]
```
## 4. Filter Function

The `filter()` function returns an iterator where the items are filtered through a function to test if the item is accepted in result or not.

Syntax is same as `map()`

### Filter without lambda
```Python
def isEven(x):
    if x%2 == 0: return True
    return False

a = [1,2,3,4,5,6]
res = list(filter(isEven, a))
print(res) # Output: [2, 4, 6]
```

### Filter with lambda
```Python
a = [1,2,3,4,5,6]
res = list(filter(lambda x:x%2==0, a))
print(res) # Output: [2, 4, 6]
```

## 5. Reduce function
The reduce() function accepts a function and a sequence and returns a single value calculated as follows:

- Initially, the function is called with the first two items from the sequence and the result is returned.
- The function is then called again with the result obtained in step 1 and the next value in the sequence. This process keeps repeating until there are items in the sequence.

This function is defined in `functools` module.

- Syntax: `reduce(function, sequence[, initial]) -> value`

### reduce without lambda
```Python
from functools import reduce

def sum(a, b):
    return a+b
    
arr = [3, 4, 5]
val = reduce(sum, arr)
print(val) # Output: 12
```

### reduce with lambda
```Python
from functools import reduce
    
arr = [3, 4, 5]
val = reduce(lambda x,y:x+y, arr)
print(val) # Output: 12
```

## 6. Multithreading (threading module)

### Key Concepts:

- A thread is an operating system object that executes a set of instructions. By default, each Python program runs on a single thread known as the main thread, created by the Python interpreter (PVM).

- Multithreading allows multiple threads to run concurrently, though Python threads run in the same memory space, the memmory requirement increases when number of thread increases.

### Main Thread Functions:

- `threading.current_thread():` Returns the current thread object.
- `threading.current_thread().name:` Returns the name of the current thread.
- `threading.current_thread().ident:` Returns the thread ID (TID).
- `threading.current_thread().is_alive():` Returns True if the thread is active.

### Creating Threads: 

There are two primary ways to create a thread in Python:

1. Using the `Thread` class directly.
2. Extending the `Thread` class.

### Use `Thread` class directly

#### Creating Threads Using Thread Class

You can create and start threads using the `Thread` class from the `threading` module.

Refer to the example - [thread1.py](Snippets/thread1.py)

- Explanation:
    - Calling the `Thread` constructor signals the operating system to create a new thread and allocate memory for it. However, the thread's execution does not begin immediately. The new thread is only initialized, not running. The actual execution of the thread starts only when the `start()` method is called, which triggers the operating system to schedule the thread for execution.

    - We pass arguments using both `args` (tuple) and `kwargs` (dictionary) for different ways to input parameters.

#### Using the Thread Class in an Object-Oriented Way

Refer to the example - [thread2.py](Snippets/thread2.py)

- Explanation:
    - We use both instance methods and class/static methods as thread targets.

### Creating Threads by Extending the `Thread` Class
When we call `start()` on a thread object, the interpreter internally calls the `run()` method. This run() method is part of the `Thread` class, which belongs to the `threading` module. The main job of the `run()` method is to execute the target function in a separate thread (in a different memory space). This is the default behavior when we create and start a thread.

However, we can customize this behavior by overriding the `run()` method. To do this, we extend the `Thread` class in our own class and redefine the `run()` method. This allows us to define the specific actions our thread should perform.

Key Benefits of Overriding run():
1. **Custom Logic:** We can define what the thread will execute by customizing the run() method.
1. **Access to Thread Data:** Instead of returning values from a thread (which is not directly possible), we can store the results in instance variables. After the thread has finished executing, these instance variables can be accessed to retrieve the result.

    ```Python
    from threading import Thread, current_thread
    import time

    class MyClass(Thread):
        def run(self):
            a = 10
            b = 20
            time.sleep(0.1) # Simulate some working
            self.res = a+b
            
    t1 = MyClass()
    t1.start()
    time.sleep(2) # let the child thread finish
    print(f"Res={t1.res}") #Output: Res=30
    ```

Refer to the example - [thread3.py](Snippets/thread3.py)

Explanation:
1. Passing Arguments to a Thread:

    The `run()` method in Python's `Thread` class does not accept arguments directly. To pass arguments to a thread, you can either:

    - Use the `__init__` method of your child class to pass arguments when creating the thread instance.

    - Alternatively, use a lambda function or a wrapper function to handle the arguments before starting the thread.

2. Calling the Superclass Constructor:

    In the constructor (`__init__`) of your child class, it's essential to call the constructor of the parent class (`Thread`). This is done using `super().__init__()`. The `Thread` class constructor performs crucial setup steps that are necessary before the thread can be started and executed properly. Skipping this could lead to incorrect or incomplete thread initialization.

### Thread Naming and Identification
1. Unique Thread Name Assignment:

    - Each thread is assigned a unique name when created. This name follows the naming convention `Thread-[%d]`, where `%d` represents an incrementing integer.

    Example:
    - First thread: `Thread-1`
    - Second thread: `Thread-2`
2. Main Thread Name:

    - The main thread (created by Python when the program starts) is named `MainThread`.

3. Thread Object and Name Attribute:

    - Every thread in Python is an object of the `Thread` class. The name of a thread is stored in the `name` attribute of the thread object.

4. Changing Thread Names:

    - You can change the name of a thread by directly assigning a string to the `name` attribute of the thread object.
    - This applies to both the main thread and any created threads.
    - Alternatively, you can use the `setName()` and `getName()` methods to set or retrieve the thread’s name, but note that these methods are deprecated and may be removed in future Python versions.

5. Thread Identifiers:

    - Thread Identifier:

        - Each thread is assigned a unique, positive integer (within the Python process) called the thread identifier, which is stored in the `ident` attribute. This value is read-only and assigned by the Python interpreter.

    - Native Identifier:

        - The native identifier is assigned by the operating system and stored in the `native_id` attribute. It becomes available only after the thread is started. In many cases, the thread identifier (`ident`) and the native identifier (`native_id`) are the same.

    ```Python
    from threading import Thread, current_thread
    import time

    def display():
        time.sleep(0.1)

    def show():
        time.sleep(0.1)

    t1 = Thread(target=display)
    t2 = Thread(target=show)
    print(t1.name) #Outut: Thread-1 (display)
    print(t2.name) #Outut: Thread-2 (show)

    # change name of the t1 thread
    t1.name = "sudipta"
    print(t1.name) #Outut: sudipta

    # change name of the main thread
    current_thread().name = "newmain"
    print(current_thread().name) #Outut: newmain

    # Get indentifiers, initially this will print null as thread is not yet started
    print(t1.ident)
    print(t1.native_id)
    t1.start()
    print(t1.ident)
    print(t1.native_id)
    ```