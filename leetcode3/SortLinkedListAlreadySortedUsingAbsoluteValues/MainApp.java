// Copyright (C) 2021 by iamslash

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 10ms 16.09% 136.MB 11.50%
// hash map
// O(N) O(N)
class Solution {
    public ListNode sortLinkedList(ListNode head) {
        int[] freqs = new int[10001];
        ListNode p = head;
        while (p != null) {
            int idx = p.val + 5000;
            freqs[idx]++;
            p = p.next;
        }
        ListNode newHead = new ListNode();
        p = newHead;
        for (int num = 0; num <= 10000; ++num) {
            while (freqs[num]-- > 0) {
                p.next = new ListNode(num - 5000);
                p = p.next;
            }
        }
        return newHead.next;
    }
}


// h
// 0 -> 2 -> -5 -> 5 -> 10 -> -10
//      c
//            t
// 

// 3ms 82.11% 146.6MB 6.50%
// linked list
// O(N) O(N)
class Solution {
    public ListNode sortLinkedList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode headNode = head;
        ListNode currNode = head;
        while (currNode.next != null) {
            if (currNode.next.val >= currNode.val) {
                currNode = currNode.next;
                continue;
            } else {
                ListNode tempNode = currNode.next;
                currNode.next = tempNode.next;
                tempNode.next = headNode;
                headNode = tempNode;
            }
        }
        return headNode;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
