// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 39.4MB 78.93%
public class ZigzagIterator {
	private int i, j, zigIdx;
  private List<Integer> A, B;
	public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
		i = 0; j = 0; zigIdx = -1;
    A = v1; B = v2;
	}

	public int next() {
		zigIdx++;
    // System.out.printf("i:%d, j:%d, zigIdx:%d\n", i, j, zigIdx);
    if ((zigIdx % 2 == 0 && i < A.size()) ||
       j >= B.size()) {
      if (i > 0) {
        i = i % A.size();
      }
			return A.get(i++);
		}
    if (j > 0) {
      j = j % B.size();
    }
    return B.get(j++);
	}

	public boolean hasNext() {
    return zigIdx < A.size() + B.size() - 1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
