# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# list
# 216ms 85.81% 17MB 8.27%
class BrowserHistory:    

    def __init__(self, homepage: str):
        self.pos = 0
        self.hist = [homepage]

    def visit(self, url: str) -> None:
        self.pos += 1
        self.hist = self.hist[:self.pos]
        self.hist.append(url)

    def back(self, steps: int) -> str:
        self.pos = max(0, self.pos - steps)
        return self.hist[self.pos]

    def forward(self, steps: int) -> str:
        self.pos = min(len(self.hist)-1, self.pos + steps)
        return self.hist[self.pos]
