# Problem

[Longest Absolute File Path](https://leetcode.com/problems/longest-absolute-file-path/)

문자열 `input` 이 주어진다. `input` 은 영문 소문자와 숫자 그리고 `\n`,
`\t` 로만 구성되어 있다. `\t` 의 개수는 디렉토리의 깊이를
의미한다. 경로의 끝은 확장자가 없으면 디렉토리이고 있으면
파일이다.파일의 경로중 가장 길이가 긴 것의 길이를 구하라.

# Idea

예를 들어 `input
="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"`
의 경우를 살펴보자. 디렉토리 구조는 다음과 같다. `?` 은 깊이 하나를
의미한다.

```
dir
? subdir1
? ? file1.ext
? ? subsubdir1
? subdir2
? ? subsubdir2
? ? ? file2.ext
```

다음과 같은 변수들을 선언한다.

> * `maxlen`: 최대 경로의 길이
> * `curlen`: 현재까지 디렉토리 깊이별 경로의 길이

`line` 으로 `input.splitlines()` 를 순회하면서 다음을 반복한다.

> * `name` 을 선언하여 `line` 에서 `\t` 를 제거한 문자열을
>   저장한다. 디렉토리 이름 혹은 파일 이름이다.
> * `lvl` 을 선언하여 `line` 에서 발견한 `\t` 의 개수를
>   저장한다. 이것은 디렉토리 깊이의 개수이다. 즉, `lvl = len(line) -
>   len(name)` 을 수행한다.
> * `name` 이 파일이면 `maxlen` 을 업데이트한다. 즉, `maxlen =
>   max(maxlen, curlen[lvl] + len(name))` 를 수행한다.
> * `name` 이 디렉토리이면 `curlen` 을 업데이트한다. 즉,
>   `curlen[lvl+1] = curlen[lvl] + len(name) + 1` 을 수행한다.

모든 반복을 마치면 `maxlen` 이 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
