# Abstract

숫자 `num` 이 주어지면 palindrome 여부를 판단해 보자.

# Idea

인덱스 `i, j` 를 활용하여 양 끝에서 가운데로 한칸씩 전진하며
`s[i] != s[j]` 를 검증한다.

```cpp
bool isPalindrome(int num) {
  string s = to_string(num);
  int i = 0, j = s.size()-1;
  while (i < j) {
    if (s[i] != s[j])
      return false;    
    i++, j--;
  }
  return true;
}
```