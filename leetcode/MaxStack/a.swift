// 159ms 88.57% 14.8MB 97.14%
// array
class MaxStack {
    var stck: [Int] = []
    let emptyVal: Int = -100_000_001
    
    func push(_ x: Int) {
        stck.append(x)
    }
    
    func pop() -> Int {
        return stck.removeLast()
    }
    
    func top() -> Int {
        return stck.last ?? emptyVal
    }
    
    func peekMax() -> Int {
        guard let maxVal = stck.max() else {
            return emptyVal
        }
        return maxVal
    }
    
    func popMax() -> Int {
        guard let maxVal = stck.max(),
              let maxIdx = stck.lastIndex(of: maxVal) else {
            return emptyVal
        }
        return stck.remove(at: maxIdx)
    }
}
