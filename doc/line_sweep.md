- [**Line Sweep의 정의**](#line-sweep의-정의)
- [**Line Sweep 알고리즘의 역사**](#line-sweep-알고리즘의-역사)
- [**Line Sweep의 특징**](#line-sweep의-특징)
- [**Line Sweep의 적용 문제**](#line-sweep의-적용-문제)
- [**Line Sweep 알고리즘의 작동 방식**](#line-sweep-알고리즘의-작동-방식)
- [**Line Sweep의 예시: 선분 교차 문제**](#line-sweep의-예시-선분-교차-문제)
  - [**코드 예제**](#코드-예제)

---

# **Line Sweep의 정의**
- **Line Sweep**은 2차원 평면에서 정렬된 데이터를 따라가며(선형적으로 "스위핑") 이벤트를 처리하는 알고리즘 기법입니다.
- 주로 **기하학적 문제**를 해결하기 위해 사용되며, 모든 이벤트를 처리하기 위해 정렬된 순서로 데이터를 탐색합니다.

---

# **Line Sweep 알고리즘의 역사**
- **최초 제안**: 
  - Line Sweep 기법의 아이디어는 **컴퓨터 그래픽스**와 **계산 기하학(Computational Geometry)** 분야에서 1970년대 후반에 처음 등장했습니다.
- **주요 공헌자**:
  - **Michael Shamos**와 **Dan Hoey**가 1976년 논문에서 "가장 가까운 점 쌍 문제"에 Line Sweep 알고리즘을 적용하며 이를 대중화시켰습니다.
  - 이후 다양한 계산 기하학 문제에 Line Sweep 기법이 도입되며 널리 사용되었습니다.

---

# **Line Sweep의 특징**
- **정렬 기반 탐색**: 문제의 입력 데이터를 특정 기준(예: x좌표, y좌표 등)으로 정렬한 뒤 순차적으로 처리합니다.
- **효율성**: 이벤트를 순차적으로 탐색하며 불필요한 계산을 줄이는 방식으로, 시간 복잡도를 **O(n log n)**으로 줄이는 데 효과적입니다.
- **동적 데이터 구조 사용**:
  - 현재 상태를 동적으로 관리하기 위해 **이진 탐색 트리**, **우선순위 큐**, **리스트** 등이 사용됩니다.

---

# **Line Sweep의 적용 문제**
1. **선분 교차 찾기**:
   - 여러 선분이 주어질 때, 교차점이 있는지 또는 교차점의 좌표를 찾는 문제.
2. **최소 면적 사각형 문제**:
   - 주어진 점 집합에서 모든 점을 포함하는 최소한의 사각형 찾기.
3. **가장 가까운 점 쌍 문제**:
   - 2차원 평면에서 가장 가까운 두 점의 거리를 계산.
4. **다각형 영역 계산**:
   - 다각형 내부의 면적을 계산.

---

# **Line Sweep 알고리즘의 작동 방식**
1. **입력 정렬**:
   - 모든 이벤트(예: 선분의 시작/끝점, 점의 좌표)를 기준(예: x좌표)으로 정렬.
2. **스위핑(Sweeping)**:
   - 정렬된 순서로 이벤트를 탐색하면서, 현재 상태를 업데이트.
3. **조건 평가**:
   - 이벤트에 따라 특정 조건을 만족하는지 확인(예: 선분 교차 여부).
4. **결과 저장**:
   - 조건을 만족하는 이벤트(예: 교차점, 거리 등)를 결과로 저장.

---

# **Line Sweep의 예시: 선분 교차 문제**
- **문제 정의**:
  - 여러 선분이 주어졌을 때, 이들이 교차하는지 확인하고 교차점의 좌표를 찾습니다.
- **알고리즘**:
  1. 각 선분의 시작점과 끝점을 **x좌표 기준**으로 정렬.
  2. 현재 처리 중인 선분을 **활성 리스트(Active List)**에 추가.
  3. 교차 조건을 확인하고 교차점 계산.
  4. 끝점을 만났을 경우, 활성 리스트에서 제거.

## **코드 예제**
```java
import java.util.*;

public class LineSweep {
    static class Event implements Comparable<Event> {
        int x, type, id;

        public Event(int x, int type, int id) {
            this.x = x;
            this.type = type;
            this.id = id;
        }

        @Override
        public int compareTo(Event other) {
            return Integer.compare(this.x, other.x);
        }
    }

    public static void main(String[] args) {
        int[][] segments = {{1, 5}, {2, 6}, {4, 8}};
        List<Event> events = new ArrayList<>();
        for (int i = 0; i < segments.length; i++) {
            events.add(new Event(segments[i][0], 1, i));
            events.add(new Event(segments[i][1], -1, i));
        }

        Collections.sort(events);

        TreeSet<Integer> active = new TreeSet<>();
        for (Event event : events) {
            if (event.type == 1) {
                if (!active.isEmpty()) {
                    System.out.println("Segments intersect.");
                    return;
                }
                active.add(event.id);
            } else {
                active.remove(event.id);
            }
        }

        System.out.println("No intersections found.");
    }
}
```
