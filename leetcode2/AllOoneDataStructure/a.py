# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

# 173ms 85.95% 33.2MB 34.83%
# bidirectional indexing, doubly linked list
class Node:
    def __init__(self, key_set, count, prev=None, next=None):
        self.key_set = key_set
        self.count = count
        self.next = next
        self.prev = prev

class AllOne:
    def __init__(self):
        self.head = Node({""}, count=0)
        self.tail = Node({""}, count=float('inf'), prev=self.head)
        self.head.next = self.tail
        self.key_node_dict = {}

    def inc(self, key: str) -> None:
        if key in self.key_node_dict:
            node = self.key_node_dict[key]
            inc_cnt = node.count + 1
            if len(node.key_set) == 1:
                if inc_cnt == node.next.count:
                    node.next.key_set.add(key)
                    self.key_node_dict[key] = node.next
                    node.next.prev, node.prev.next = node.prev, node.next
                else:
                    node.count = inc_cnt
            else:
                node.key_set.remove(key)
                if inc_cnt == node.next.count:
                    node.next.key_set.add(key)
                    self.key_node_dict[key] = node.next
                else:
                    new_node = Node(key_set={key}, count=inc_cnt, prev=node, next=node.next)
                    node.next.prev = new_node
                    node.next = new_node
                    self.key_node_dict[key] = new_node
        else:
            if self.head.next.count == 1:
                self.head.next.key_set.add(key)
                self.key_node_dict[key] = self.head.next
            else:
                node = Node(key_set={key}, count=1, prev=self.head, next=self.head.next)
                self.head.next.prev = node
                self.head.next = node
                self.key_node_dict[key] = node

    def dec(self, key: str) -> None:
        node = self.key_node_dict[key]
        if node.count == 1:
            if len(node.key_set) == 1:
                node.next.prev, node.prev.next = node.prev, node.next
            else:
                node.key_set.remove(key)
            del self.key_node_dict[key]
        else:
            dec_cnt = node.count - 1
            if len(node.key_set) == 1:
                if dec_cnt == node.prev.count:
                    node.prev.key_set.add(key)
                    self.key_node_dict[key] = node.prev
                    node.next.prev, node.prev.next = node.prev, node.next
                else:
                    node.count = dec_cnt
            else:
                node.key_set.remove(key)
                if dec_cnt == node.prev.count:
                    node.prev.key_set.add(key)
                    self.key_node_dict[key] = node.prev
                else:
                    new_node = Node(key_set={key}, count=dec_cnt, prev=node.prev, next=node)
                    node.prev.next = new_node
                    node.prev = new_node
                    self.key_node_dict[key] = new_node

    def getMaxKey(self) -> str:
        return next(iter(self.tail.prev.key_set))

    def getMinKey(self) -> str:
        return next(iter(self.head.next.key_set))
