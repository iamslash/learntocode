# -*- coding: utf-8 -*-

import sys
import hashlib
import struct
import pprint

g_value_idx = 2

class ConsistentHash:
    def __init__(self, kvlist, replica, hashfunc = None):
        self.hashfunc = hashfunc
        if not self.hashfunc:
            self.hashfunc = self.ketamahash
        self.kvlist = kvlist
        self.replica = replica
        self.continuum = self.rebuild(kvlist)

    def ketamahash(self, key):
        return struct.unpack('<I', hashlib.md5(key.encode('utf-8')).digest()[0:4])

    def _hash(self, key):
        return self.hashfunc(key)

    def rebuild(self, kvlist):
        continuum = [(k, i, v, self._hash("%s:%s"%(k, i))) \
                     for k, v in kvlist \
                     for i in range(self.replica)]
        continuum.sort(key = lambda x: x[3])
        return continuum

    def get(self, key):
        h = self._hash(key)[0]
        # 링의 해시값을 초과하면 링의 가장 처음녀석의 밸류를 넘기자.
        if h > self.continuum[-1][3][0]:
            return self.continuum[0][2]
        return self.find_near_value(h)

    def find_near_value(self, h):
        size = len(self.continuum)
        begin = left = 0
        end = right = size

        while left < right:
            mid = int(left + (right - left) / 2)
            if self.continuum[mid][3][0] < h:
                left = mid + 1
            else:
                right = mid
        if right == end:
            right = begin
        return right, self.continuum[right][2]

def main():
    pass

if __name__ == "__main__":
    replica = 2
    kvlist = [("host1", "value1"), ("host2", "value2"), ("host3", "value3"), ("host4", "value4")]
    ch = ConsistentHash(kvlist, replica)
    pprint.pprint(ch.continuum)
    v = ch.get(sys.argv[1])
    print(v[0], ch.continuum[v[0]])
