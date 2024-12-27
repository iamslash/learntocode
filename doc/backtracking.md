- [**Backtracking의 정의**](#backtracking의-정의)
- [**Backtracking의 기원**](#backtracking의-기원)
- [**N-Queens 문제란?**](#n-queens-문제란)
- [**Backtracking을 이용한 N-Queens 해결**](#backtracking을-이용한-n-queens-해결)
  - [**핵심 아이디어**](#핵심-아이디어)
  - [**N-Queens 문제의 Backtracking 코드**](#n-queens-문제의-backtracking-코드)
- [**5. Backtracking의 적용 과정 (예시: 4-Queens 문제)**](#5-backtracking의-적용-과정-예시-4-queens-문제)
  - [**단계별 탐색**](#단계별-탐색)
- [**6. Backtracking의 장점**](#6-backtracking의-장점)
- [**7. 결론**](#7-결론)

---

### **Backtracking의 정의**
- **Backtracking**은 탐색 과정에서 잘못된 경로를 발견하면 **되돌아가(Backtrack)** 다른 경로를 탐색하는 방법입니다.
- **효율적인 탐색 전략**으로, 특히 조합론적 문제와 제약 조건을 만족하는 해를 찾는 문제에 적합합니다.
- **Pruning(가지치기)**를 통해 불필요한 탐색을 줄이고, 탐색 공간을 체계적으로 관리합니다.
- [backtracking vs branch and bound](/doc/combinatorial_search.md#backtracking-vs-branch-and-bound-subset-sum-problem) 를 참고하면 branch and bound 와의 차이를 이해할 수 있다.

---

### **Backtracking의 기원**
- **Backtracking**이라는 용어와 체계적인 기법은 1950년대에 미국의 수학자 **데이비드 H. 레빈슨(David H. Levinson)**과 **도널드 러스틱(Donald Loveland)**에 의해 체계적으로 연구되었습니다.
- 이후 **1958년**에 미국의 컴퓨터 과학자 **W. F. Miller**와 **F. W. Tonge**가 Backtracking을 알고리즘 설계 기법으로 발전시켰습니다.
- 20세기 중반 이후 컴퓨터의 발전과 함께 조합론적 문제를 해결하는 중요한 도구로 자리 잡았습니다.

---

### **N-Queens 문제란?**
- **N-Queens 문제**는 N×N 체스판에 N개의 퀸을 배치하되, 서로 공격하지 않도록 배치하는 문제입니다.
- **퀸의 공격 조건**:
  1. 같은 행에 퀸이 있을 수 없음.
  2. 같은 열에 퀸이 있을 수 없음.
  3. 같은 대각선에 퀸이 있을 수 없음.

---

### **Backtracking을 이용한 N-Queens 해결**
#### **핵심 아이디어**
1. **한 행씩 탐색**:
   - 체스판의 각 행에 퀸을 배치하며, 조건을 만족하지 않는 배치를 가지치기(Pruning).
2. **재귀적 탐색**:
   - 한 행에 퀸을 배치한 후, 다음 행에 대한 가능한 배치를 재귀적으로 탐색.
3. **되돌아가기**:
   - 조건을 만족하지 않으면 이전 단계로 돌아가 다른 배치를 시도(Backtracking).

#### **N-Queens 문제의 Backtracking 코드**
```java
public class NQueens {
    static void solveNQueens(int n) {
        int[] board = new int[n];
        placeQueens(board, 0, n);
    }

    static void placeQueens(int[] board, int row, int n) {
        if (row == n) {
            printBoard(board, n);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                placeQueens(board, row + 1, n);
            }
        }
    }

    static boolean isSafe(int[] board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || Math.abs(board[i] - col) == Math.abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    static void printBoard(int[] board, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                System.out.print((board[row] == col ? "Q " : ". "));
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 8; // 8-Queens
        solveNQueens(n);
    }
}
```

---

### **5. Backtracking의 적용 과정 (예시: 4-Queens 문제)**

#### **단계별 탐색**
1. 첫 번째 행에 퀸 배치:  
   - (0, 0)에 배치 → 두 번째 행으로 이동.

2. 두 번째 행에 퀸 배치:  
   - (1, 0): 같은 열, 공격 가능 → 가지치기.  
   - (1, 1): 대각선, 공격 가능 → 가지치기.  
   - (1, 2): 안전 → 세 번째 행으로 이동.

3. 세 번째 행에 퀸 배치:  
   - 조건에 맞는 배치를 반복적으로 찾음.

4. 모든 퀸이 배치되면 **해를 출력**.  
   - 배치가 불가능한 경우, 이전 단계로 돌아가 다른 배치를 탐색(Backtracking).

---

### **6. Backtracking의 장점**
- **효율적인 탐색**:
  - Pruning을 통해 불필요한 경로를 배제하므로, 탐색 공간을 효과적으로 줄입니다.
- **일반성**:
  - N-Queens뿐만 아니라 Sudoku, 퍼즐 문제, CSP(Constraint Satisfaction Problem) 등 다양한 문제에 적용 가능합니다.

---

### **7. 결론**
Backtracking은 N-Queens 문제와 같은 조합 탐색 문제를 해결하는 데 필수적인 기법입니다.  
- **Pruning**을 통해 탐색 공간을 줄이고, **재귀적 탐색**으로 모든 가능한 해를 체계적으로 검토합니다.
- N-Queens 문제는 Backtracking의 효율성과 강점을 보여주는 대표적인 사례입니다.
  