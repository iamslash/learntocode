// Copyright (C) 2017 by iamslash
//https://algospot.com/judge/problem/read/KAKURO2

// CANDS[len][sum][known]
int CANDS[10][46][1024];

int get_size(int bm) {
  return 0;
}
int get_sum(int bm) {

}
// // get_cands(2, 5, [])
// // get_cands(3, 6, [3])
// // len : empty cell count
// // sum : sum of cells
// // known : bit mask of already found
// int get_cands(int len, int sum, int known) {
//   int r = 0;
//   // find all sets
//   // have known
//   // size is len
//   // sum is sum
//   for (int set = 0; set < 1024; set += 2) {
//     if ((set & known) == known &&
//         get_size(set) == len &&
//         get_sum(set) == sum) {
//       r |= set;
//     }
//   }
//   return r & ~known;
// }

int build_cands() {
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 46; ++j)
      for (int k = 0; k < 1024; ++k)
        CANDS[i][j][k] = 0;
  for (int set = 0; set < 1024; set += 2) {
    int l = get_size(set);
    int s = get_sum(set);
    int subset = set;
    while (true) {
      CANDS[l][s][subset] |= (set & ~subset);
      if (subset == 0)
        break;
      subset = (subset - 1) & set;
    }
  }    
}
