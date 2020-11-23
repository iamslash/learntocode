# -*- coding: utf-8 -*-
# Copyright (C) 2016 by iamslash
# > python3 a.py

import sys

def cycle_len(CACHE, n):
    # base condition
    if n == 1:
        return 1

    # memoization
    if CACHE[n] > 0:
        return CACHE[n]
    
    # recursion
    r = 0
    if n % 2 == 0:
        r = 1 + cycle_len(CACHE, int(n/2))
    else:
        r = 1 + cycle_len(CACHE, n*3 + 1)
    CACHE[n] = int(r)

    return CACHE[n]

if __name__ == "__main__":

    for line in sys.stdin:
        CACHE = [-1] * 10000000
        # print(len(CACHE))
        
        line = line.strip()
        l = line.split(' ')
        I = int(l[0])
        J = int(l[1])

        r = 0
        for n in range(I, J+1):
            r = max(r, cycle_len(CACHE, n))
            
        print('{} {} {}'.format(I, J, r))
