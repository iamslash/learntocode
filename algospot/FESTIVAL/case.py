import sys
import random

if __name__ == '__main__':
    #print(sys.argv)

    if len(sys.argv) != 2:
        print('usage) case.py C')
        print('example) case.py 1')
        sys.exit()
    C = int(sys.argv[1])
    N = 0
    L = 0


    print(C)
    for i in xrange(C):

        N = random.randrange(1, 1001)
        L = random.randrange(1, N+1)

        print(" ".join([str(x) for x in [N, L]]))
        print(" ".join([str(x%3+1) for x in xrange(N)]))
