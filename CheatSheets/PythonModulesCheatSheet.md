# CheatSheet for various python modules

## Table of Contents
> 1. [Requests Module](#1-requests-module)
>> 1. [Get Request](#1-get-request)
>> 2. [Post Request](#2-post-request)
>> 3. [Send JSON data](#3-sending-json-data-in-post-request)
>> 4. [PUT Request](#4-put-request)
>> 5. [Delete Request](#5-delete-request)
>> 6. [HEAD Request](#6-head-request)
>> 7. [Send parameters in GET](#7-sending-parameters-in-get-request)
>> 8. [Send headers](#8-sending-headers-with-request)
>> 9. [Cookies](#9-working-with-cookies)
>> 10. [Upload files](#10-uploading-files)
>> 11. [Authentication](#11-authentication)
>> 12. [Download](#12-downloading-content)
>> 13. [Proxies](#13-proxies)
>> 14. [SSL Verification](#14-disable-ssl-verification)
>> 15. [Custome timeout](#15-custom-timeout-for-requests)
>> 16. [Status Code](#16-common-status-codes)

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
