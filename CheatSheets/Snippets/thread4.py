from threading import Thread, main_thread, active_count, enumerate
import time

def display():
    time.sleep(0.1)
    print("Main thread details from display - ",main_thread())
    print("Hello World from display")

t1 = Thread(target=display)
print("before: ",t1.is_alive())
t1.start()
print("after: ",t1.is_alive())
print("Number of threads: ",active_count())
print("Thread details: ",enumerate())
time.sleep(0.1)


