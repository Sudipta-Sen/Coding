from threading import Thread, current_thread
import time 

class Example:
    def display(self, n: int, msg: str):
        for i in range(n):
            print(f"{msg} - Thread: {current_thread().name}")
            time.sleep(0.1)

    @classmethod
    def display_classmethod(cls):
        for i in range(3):
            print(f"From class method - Thread: {current_thread().name}")
            time.sleep(0.1)

    @staticmethod
    def display_static():
        for i in range(3):
            print(f"From static method - Thread: {current_thread().name}")
            time.sleep(0.1)

# Example usage
e = Example()
t1 = Thread(target=e.display, args=(3, "Instance Method"))
t2 = Thread(target=Example.display_classmethod)
t3 = Thread(target=Example.display_static)

t1.start()
t2.start()
t3.start()
