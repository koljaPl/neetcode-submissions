class MinStack:

    def __init__(self):
        self.stack = []
        self.minimums_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

        if not self.minimums_stack or val <= self.minimums_stack[-1]:
            self.minimums_stack.append(val)

    def pop(self) -> None:
        value = self.stack.pop()

        if value == self.minimums_stack[-1]:
            self.minimums_stack.pop()


    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.minimums_stack[-1]