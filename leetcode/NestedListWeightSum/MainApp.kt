/* Copyright (C) 2022 by iamslash */

import java.util.*

abstract class NestedInteger {
    constructor()
    constructor(value: Int)
    abstract fun isInteger(): Boolean
    abstract fun getInteger(): Int?
    abstract fun setInteger(value: Int): Unit
    abstract fun add(ni: NestedInteger): Unit
    abstract fun getList(): List<NestedInteger>?
}

// 136ms 93.16% 33.5MB 93.16%
// Design
class Solution {
    fun dfs(nestedList: List<NestedInteger>, depth: Int): Int {
        var sum = 0
        for (ni in nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger()!! * depth
            } else {
                sum += dfs(ni.getList(), depth + 1)
            }
        }
        return sum
    }
    fun depthSum(nestedList: List<NestedInteger>): Int {
        return dfs(nestedList, 1)
    }
}

fun main() {
    println("Hello World")
}
