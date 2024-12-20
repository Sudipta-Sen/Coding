from threading import Thread, current_thread
import time

class MyClass(Thread):
    def __init__(self, n:int, msg: str):
        super().__init__()
        self.n = n
        self.msg = msg

    def run(self):
        for i in range(self.n):
            print(f"{self.msg} - Thread: {current_thread().name}")
            time.sleep(0.1)
        

t1 = MyClass(4, "Hi")
t1.start()