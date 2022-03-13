# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 1678ms 13.18% 77.9MB 75.00%
# doubly linked list, hash map
# get: O(1) O(N)
# put: O(1) O(N)
class ListNode:

    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None

class DoublyLinkedList:
    
    def __init__(self):
        self.root = ListNode(None, None)
        self.root.next = self.root
        self.root.prev = self.root
        self.size = 0

    def __len__(self):
        return self.size

    def push(self, node):
        node.next = self.root.next
        node.prev = self.root
        node.next.prev = node
        self.root.next = node
        self.size += 1

    def pop(self, node=None):
        if self.size == 0:
            return
        if not node:
            node = self.root.prev
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1
        return node

class LFUCache:

    def __init__(self, capacity: int):
        self.size = 0
        self.capa = capacity
        self.nodeMap = dict()
        self.freqMap = collections.defaultdict(DoublyLinkedList)
        self.minFreq = 0

    def touch(self, node):
        freq = node.freq
        self.freqMap[freq].pop(node)
        if self.minFreq == freq and not self.freqMap[freq]:
            self.minFreq += 1
        node.freq += 1
        freq = node.freq
        self.freqMap[freq].push(node)

    def get(self, key: int) -> int:
        # miss
        if key not in self.nodeMap:
            return -1
        # hit
        node = self.nodeMap[key]
        self.touch(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        # empty
        if self.capa == 0:
            return
        # hit
        if key in self.nodeMap:
            node = self.nodeMap[key]
            self.touch(node)
            node.val = value
            return
        # miss, evict
        if self.size == self.capa:
            node = self.freqMap[self.minFreq].pop()
            del self.nodeMap[node.key]
            self.size -= 1
        # miss, save
        node = ListNode(key, value)
        self.nodeMap[key] = node
        self.freqMap[1].push(node)
        self.minFreq = 1
        self.size += 1

def main():
    pass

if __name__ == "__main__":
    main()
