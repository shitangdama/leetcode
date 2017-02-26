class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.front = []
        self.back = []
    
    def move_back_to_front(self):
        while self.back:
            self.front.append(self.back[-1])
            self.back.pop()

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.back.append(x)

    # @return nothing
    def pop(self):
        if not self.front:
            self.move_back_to_front()
        self.front.pop()

    # @return an integer
    def peek(self):
        if not self.front:
            self.move_back_to_front()
        return self.front[-1]

    # @return an boolean
    def empty(self):
        return not self.back and not self.front
        

# test
q = Queue()
q.push(1)
print q.empty()
print q.peek()
