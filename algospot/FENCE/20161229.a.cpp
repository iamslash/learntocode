#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int get_max_square_size(vector<int> & h)
{
  // 남아 있는 판자들의 위치들을 저장한다.
  std::stack<int> remaining;
  h.push_back(0);
  int r = 0;
  for (int i = 0; i < h.size(); ++i) {
    // 남아 있는 판자들 중 오른쪽 끝 판자가 h[i]보다 높다면
    // 이 판자의 최대 사각형은 i에서 끝난다.
    while (!remaining.empty() &&
           h[remaining.top()] >= h[i]) {
      int j = remaining.top();
      remaining.pop();
      int width = -1;

      // j번째 판 자 왼쪽에 판자가 하나도 안 남아 있는 경우 left[j] =
      // -1.  아닌 경우 left[j] = 남아 있는 판자중 가장 오른쪽에 있는
      // 판자의 번호
      if (remaining.empty())
        width = i;
      else
        width = (i - remaining.top() - 1);
      r = max(r, h[j] * width);
    }
    remaining.push(i);
  }
  return r;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        vector<int> H;
        scanf("%d", &N);
        for(int n=0; n<N; ++n)
        {
            int h;
            scanf("%d", &h);
            H.push_back(h);
        }

        printf("%d\n", get_max_square_size(H));
    }
  
    return 0;
}
