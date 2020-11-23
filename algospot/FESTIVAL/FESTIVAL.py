import sys
import gc

C = int(raw_input().strip())

l_r = []

for n_case in range(C):
    gc.collect()

    l       = map((lambda x: int(x)), raw_input().strip().split(' '))
    N       = l[0] # 6
    L       = l[1] # 3

    l_costs = map((lambda x: int(x)), raw_input().strip().split(' ')) # [1, 2, 3, 1, 2, 3]
    
    l_rr = []
    for i in range(N - L + 1):
        for j in range(i + L, N + 1): 
            #print(i, j, N - L + 1, i + L, N)
            l = l_costs[i : j]
            #print(i, j)
            l_rr.append(l)
    #print(l_rr)
    l_rr = map( (lambda x: sum(x)/float(len(x))), l_rr)
    l_r.append(min(l_rr))

for n_r in l_r: print("{0:0.11f}".format(n_r))
