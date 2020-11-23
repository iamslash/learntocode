function ListNode(val, next = null) {
  this.val = val;
  this.next = next;
}

// r
//     s
//     f
// 1 2 1
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
};

var h = new ListNode(1, new ListNode(2, new ListNode(1)));

console.log(isPalindrome(h));