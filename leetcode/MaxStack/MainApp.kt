/* Copyright (C) 2022 by iamslash */

import java.util.*

// 343ms 88.57% 49.4MB 82.86%
// stack, priority queue
//    push: O(NlgN)
//     pop: O(NlgN)
//     top: O(1)
// peekMax: O(1)
//  popMax: O(N)
class MaxStack() {
    private val deq: Deque<Int> = ArrayDeque<Int>()
    private val pq: Queue<Int> = PriorityQueue<Int>({ a, b -> b - a })
    fun push(x: Int) {
        deq.offerLast(x)
        pq.offer(x)
    }

    fun pop(): Int {
        val e = deq.pollLast()
        pq.remove(e)
        return e
    }

    fun top(): Int {
        return deq.peekLast()
    }

    fun peekMax(): Int {
        return pq.peek()
    }

    fun popMax(): Int {
        val e = pq.poll()
        deq.removeLastOccurrence(e)
        return e
    }
}
