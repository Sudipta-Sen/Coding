import threading, time
from threading import Thread

# function containing code to be executed parallaly
def display(n:int, msg:str):
    for i in range(n):
        print(f"{msg} - thread_name-{threading.current_thread().name}")
        time.sleep(0.1)

# Create new thread
t1 = Thread(target=display, args=(4, "Hi"))
t2 = Thread(target=display, kwargs={'n':4, 'msg':"Hello"})

# Start new thread, currently the program has only one thread
t1.start()
t2.start()
# now the program has total 3 threads

for i in range(4):
    print("Its end")