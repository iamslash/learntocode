/* Copyright (C) 2022 by iamslash */

fun <T: Comparable<T>> List<T>.quickSort(): List<T> {
    // base
    if (size < 2) {
        return this
    }
    // recursion
    val pivot = this.first()
    val (smaller, bigger) = this.drop(1).partition { it < pivot }
    return smaller.quickSort() + pivot + bigger.quickSort()
}

fun main() {
    println(listOf(3, 2, 5, 1, 6).quickSort())  // [1, 2, 3, 5, 6]
    println(listOf("C", "D", "A", "B").quickSort())  // [A, B, C, D]
}
