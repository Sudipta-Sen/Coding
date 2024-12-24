import threading, time

lock = threading.Lock()
shared_resource = 0

def increment():
    global shared_resource
    if lock.acquire(timeout=2):
        try:
            time.sleep(5)
        finally:
            lock.release()
    else:
        print("Could not acquire the lock within 2 sec")

t1 = threading.Thread(target=increment)
t2 = threading.Thread(target=increment)

t1.start()
t2.start()


t1.join()
t2.join()


print("Final value:", shared_resource)
