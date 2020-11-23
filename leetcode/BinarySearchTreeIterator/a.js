//Copyright (C) 2019 by iamslash

function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

function TreeNode(x, l, r) {
    this.val = x;
    this.left = l;
    this.right = r;
}

// //////////////////////////////////////////////////
// // 176ms 2.64%
// // O(N) O(N)
// var BSTIterator = function(root) {
//     this.stck = [];
//     this.addChild(root);
// };

// BSTIterator.prototype.next = function() {
//     const node = this.stck.pop();
//     this.addChild(node.right);
//     return node.val;
// };

// BSTIterator.prototype.hasNext = function() {
//     return this.stck.length > 0;
// };

// BSTIterator.prototype.addChild = function(node) {
//     while (node) {
//         this.stck.push(node);
//         node = node.left;
//     } 
// }

// 172ms 3.17%
// O(N) O(N)
var BSTIterator = function(root) {
    this.stck = [];
    this.prepare(root, this.stck);
}

BSTIterator.prototype.hasNext = function() {
    return this.stck.length > 0;
}

BSTIterator.prototype.next = function() {
    if (!this.hasNext())
        return false;
    var node = this.stck.pop();
    this.prepare(node.right);
    return node.val;
}

BSTIterator.prototype.prepare = function(node) {
    while (node) {
        this.stck.push(node);
        node = node.left;
    }
}

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = Object.create(BSTIterator).createNew(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */

var root  = new TreeNode(7,
                  new TreeNode(3),
                  new TreeNode(15));
var it    = new BSTIterator(root);
while (it.hasNext()) {
    console.log(it.next());
}
