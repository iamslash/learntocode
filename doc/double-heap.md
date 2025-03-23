# Double Heap 패턴 활용 가이드

Double Heap 패턴은 데이터 스트림에서 중앙값(median)이나 특정 순위의 요소를 효율적으로 찾기 위한 강력한 기법입니다. 이 패턴은 두 개의 힙(minHeap과 maxHeap)을 사용하여 데이터를 관리합니다.

## minHeap과 maxHeap 정의 방법

### Java에서 PriorityQueue 사용

```java
// 최소 힙 (기본값)
PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// 최대 힙 (Comparator 사용)
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

// 커스텀 비교자를 사용한 최소 힙
PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> a - b);

// 커스텀 비교자를 사용한 최대 힙
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
```


### 인덱스 기반 힙 (중복 값 처리)

```java
// 값이 같을 경우 인덱스로 구분하는 최소 힙
PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> 
    nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b);

// 값이 같을 경우 인덱스로 구분하는 최대 힙
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> 
    nums[a] != nums[b] ? Integer.compare(nums[b], nums[a]) : a - b);
```


## minHeap과 maxHeap의 의미

Double Heap 패턴에서:

- **maxHeap**: 데이터 스트림의 작은 절반을 저장 (최대 힙이므로 루트는 작은 절반 중 가장 큰 값)
- **minHeap**: 데이터 스트림의 큰 절반을 저장 (최소 힙이므로 루트는 큰 절반 중 가장 작은 값)

이 구조를 통해 중앙값을 O(1) 시간에 찾을 수 있습니다:

- 전체 요소 개수가 홀수일 때: maxHeap의 루트가 중앙값
- 전체 요소 개수가 짝수일 때: maxHeap의 루트와 minHeap의 루트의 평균이 중앙값


## rebalance 정의 방법

rebalance는 두 힙의 크기 균형을 유지하는 과정입니다. 일반적으로 maxHeap의 크기는 minHeap의 크기와 같거나 하나 더 큽니다.

```java
private void rebalance(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
    // maxHeap이 minHeap보다 2개 이상 많으면 minHeap으로 이동
    while (maxHeap.size() > minHeap.size() + 1) {
        minHeap.offer(maxHeap.poll());
    }
    
    // minHeap이 maxHeap보다 크면 maxHeap으로 이동
    while (maxHeap.size() < minHeap.size()) {
        maxHeap.offer(minHeap.poll());
    }
}
```


## findMedian / getMedian 구현

중앙값을 찾는 함수는 다음과 같이 구현할 수 있습니다:

```java
private double findMedian(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
    if (maxHeap.size() > minHeap.size()) {
        // 홀수 개의 요소가 있을 때
        return maxHeap.peek();
    } else {
        // 짝수 개의 요소가 있을 때
        return (maxHeap.peek() + minHeap.peek()) / 2.0;
    }
}
```

인덱스 기반 구현:

```java
private double getMedian(int[] nums, PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap, int k) {
    if (k % 2 == 1) {
        // k가 홀수일 때
        return nums[maxHeap.peek()];
    } else {
        // k가 짝수일 때
        return ((double) nums[maxHeap.peek()] + nums[minHeap.peek()]) / 2.0;
    }
}
```


## 빈도수를 이용한 최적화 방법

슬라이딩 윈도우 문제에서는 요소를 제거할 때 효율성 문제가 발생합니다. `PriorityQueue.remove(Object)`는 O(n) 시간이 소요되므로, 지연 삭제(lazy removal) 방식을 사용하여 최적화할 수 있습니다:

```java
// 지연 삭제를 위한 맵 선언
Map<Integer, Integer> delayed = new HashMap<>();

// 요소 제거 (실제로 제거하지 않고 맵에 표시)
delayed.put(valueToRemove, delayed.getOrDefault(valueToRemove, 0) + 1);

// 힙 정리 함수
private void cleanHeap(PriorityQueue<Integer> heap, Map<Integer, Integer> delayed) {
    while (!heap.isEmpty() && delayed.containsKey(heap.peek())) {
        int count = delayed.get(heap.peek());
        if (count > 1) {
            delayed.put(heap.peek(), count - 1);
        } else {
            delayed.remove(heap.peek());
        }
        heap.poll();
    }
}
```

이 방식을 사용하면 요소를 즉시 제거하지 않고, 해당 요소가 힙의 루트에 도달했을 때만 제거하므로 효율성이 크게 향상됩니다.

## 고유 식별자를 이용한 중복 값 처리

중복 값이 있는 경우, 값과 인덱스를 조합하여 고유 식별자를 만들 수 있습니다:

```java
// 고유 식별자 생성 (값 * multiplier + 인덱스)
int multiplier = 100000;
long[] uniqueVals = new long[n];
for (int i = 0; i < n; i++) {
    uniqueVals[i] = (long)nums[i] * multiplier + i;
}
```

이 방식은 TreeSet이나 TreeMap과 같은 자료구조에서 중복 값을 구분할 때 유용합니다.

## 주의사항

1. 힙 불균형 처리: 요소 추가/제거 후 항상 rebalance 함수를 호출해야 합니다.
2. 오버플로우 방지: 큰 수를 다룰 때는 long 타입을 사용하세요.
3. 지연 삭제 사용: 슬라이딩 윈도우에서는 지연 삭제 방식이 효율적입니다.
4. 중앙값 계산: 홀수/짝수 케이스를 올바르게 처리해야 합니다.
