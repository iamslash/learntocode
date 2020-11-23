# Abstract

- `recursive function` 의 매개변수가 `int` 가 아닌 경우 `memoization` 을 할 수 있는 방법에 대해 정리한다.
  
# 매개변수가 `vector<int>` 인 경우 `map` 을 사용하자.

다음과 같이 `vector<int>` 를 키로 갖는 `map` 을 이용할 수 있다.

```
std::map<std::vector<int>, int> C;
```

# 매개변수가 `vector<int>` 인 경우 `bijection function` 을 사용하자.

- 매개변수 벡터에 대한 원소가 `[1, n]` 범위의 수라고 하자.
  정수배열의 종류는 `n!` 이다. 정수 배열을 `int` 로
  변환해서 사용하자.

```cpp
int CACHE[N_FACTORIAL]
int map_func(const vector<int>& key);
inf solve(const vector<int>& key) {
    // base condition
    ...
    // memoization
    int& r = CACHE[map_func(key)];
    // recursion
    ...
    return r;
}
```

# 매개변수가  `vector<bool>` 인 경우 `int` 로 변환하자

- 길이 `n` 인 `boolean array` 는 가짓수가 `2^n` 이다. 십진수로 변환하면
  `[0, 2^n-1]` 이다.

# 매개변수가 `vector<int>` 이고 permutation parameters 인 경우 `bijection func` 를 이용하자

- 배열 `X` 가 항상 `[1,2,...,10]` 의 순열이라고 하자. 순열을 바로 숫자로
  표현하면 `CACHE` 의 공간의 낭비가 심각하니 몇번째 순열인지 계산하는
  `bijection function` 을 제작하자.

```cpp
// factorials[i] = i!
int factorials[12];
int get_idx(const std::vector<int>& X) {
    int r = 0;
    for (int i = 0; i < X.size(); ++i) {
        int less = 0;
        //
        for (int j = i + 1; j < X.size(); ++j) {
            if (X[j] < X[i])
                ++less;
        }
        r += factorials[X.size() - i - 1] * less;
    } 
    return r;
}
```

# 매개변수가 `vector<int>` 이고 범위가 좁은 경우 `int` 로 매핑하자

길이 `5` 인 정수 배열의 각 값이 `[0, 9]` 범위 속한다고 하면 각위치의
  숫자들을 늘어 놓으면 십진수 하나에 일대일 대응된다. 배열의 길이가
  `n` 이고 배열의 원소가 `[0, k-1]` 범위에 들어간다면 이것은 `n` 자리의 `k` 진수로
  변환할 수 있다.