import threading, time

lock = threading.Lock()
shared_resource = 0

def increment():
    global shared_resource
    # lock.acquire()    # Acquire the lock
    for _ in range(100):
        old_value = shared_resource
        time.sleep(0.1)
        shared_resource = old_value+1 
    # lock.release()    # Release the lock

t1 = threading.Thread(target=increment)
t2 = threading.Thread(target=increment)

t1.start()
t2.start()

t1.join()
t2.join()

print("Final value:", shared_resource)
