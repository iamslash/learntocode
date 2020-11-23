# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

class Stack:
    def __init__(self):
        self.data = []
    def push(self, x : int):
        self.data.append(x)
    def is_empty(self) -> bool:
        return len(self.data) == 0
    def top(self) -> int:
        return self.data[-1]
    def pop(self) -> bool:
        if self.is_empty():
            return False
        self.data.pop()
        return True

if __name__ == "__main__":
    stck = Stack()

    stck.push(2)
    stck.push(3)
    stck.push(4)
    print(stck.top()) # 4

    print(stck.is_empty()) # True

    stck.pop()
    stck.pop()
    print(stck.top()) # 2

    
