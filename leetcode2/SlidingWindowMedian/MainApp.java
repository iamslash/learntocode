// Copyright (C) 2025 by iamslash

import java.util.*;

// 93ms 44.37% 56.66MB 48.20%
// double heap
// O(NlgK) O(N)
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        // 결과 배열 초기화
        double[] result = new double[nums.length - k + 1];
        
        // TreeSet을 사용하여 maxHeap과 minHeap 구현
        // 값이 같을 경우 인덱스로 구분하기 위해 커스텀 비교자 사용
        TreeSet<Integer> maxHeap = new TreeSet<>((a, b) -> 
            nums[a] != nums[b] ? Integer.compare(nums[b], nums[a]) : a - b);
        TreeSet<Integer> minHeap = new TreeSet<>((a, b) -> 
            nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b);
        
        // 초기 k개 요소 처리
        for (int i = 0; i < k; i++) {
            maxHeap.add(i);
        }
        
        // 힙 균형 맞추기
        rebalance(maxHeap, minHeap);
        
        // 첫 번째 윈도우의 중앙값 계산
        result[0] = getMedian(nums, maxHeap, minHeap, k);
        
        // 슬라이딩 윈도우 이동
        for (int i = k; i < nums.length; i++) {
            // 이전 윈도우에서 제거할 요소
            int outIndex = i - k;
            
            // 새로운 요소 추가
            if (maxHeap.isEmpty() || nums[i] <= nums[maxHeap.first()]) {
                maxHeap.add(i);
            } else {
                minHeap.add(i);
            }
            
            // 제거할 요소가 어느 힙에 있는지 확인하고 제거
            if (maxHeap.contains(outIndex)) {
                maxHeap.remove(outIndex);
            } else {
                minHeap.remove(outIndex);
            }
            
            // 힙 균형 다시 맞추기
            rebalance(maxHeap, minHeap);
            
            // 현재 윈도우의 중앙값 계산
            result[i - k + 1] = getMedian(nums, maxHeap, minHeap, k);
        }
        
        return result;
    }
    
    // 두 힙의 크기를 균형있게 조정
    private void rebalance(TreeSet<Integer> maxHeap, TreeSet<Integer> minHeap) {
        // maxHeap은 항상 minHeap보다 같거나 하나 더 많은 요소를 가져야 함
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.pollFirst());
        }
        
        while (maxHeap.size() < minHeap.size()) {
            maxHeap.add(minHeap.pollFirst());
        }
    }
    
    // 현재 윈도우의 중앙값 계산
    private double getMedian(int[] nums, TreeSet<Integer> maxHeap, TreeSet<Integer> minHeap, int k) {
        if (k % 2 == 1) {
            // k가 홀수인 경우, maxHeap의 최상위 요소가 중앙값
            return nums[maxHeap.first()];
        } else {
            // k가 짝수인 경우, maxHeap과 minHeap의 최상위 요소의 평균이 중앙값
            return ((double) nums[maxHeap.first()] + nums[minHeap.first()]) / 2.0;
        }
    }
}
