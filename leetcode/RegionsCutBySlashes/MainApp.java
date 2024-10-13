// Copyright (C) 2024 by iamslash

import java.util.*;

// 8ms 55.24% 44.6MB 20.66%
// dfs
// O(N^2) O(N^2)
class Solution {

    private void dfs(int[][] G, int y, int x) {
        G[y][x] = 1;

        int m = G.length;
        int[] d = {-1, 0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int ny = y + d[i], nx = x + d[i + 1];
            if (ny < 0 || ny >= m || nx < 0 || nx >= m ||
                G[ny][nx] == 1) {
                continue;
            }
            dfs(G, ny, nx);
        }       
    }
    
    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int[][] G = new int[n * 3][n * 3]; 

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                char c = grid[y].charAt(x);
                if (c == '/') {
                    G[y * 3][x * 3 + 2] = G[y * 3 + 1][x * 3 + 1] = G[y * 3 + 2][x * 3] = 1;
                } else if (c == '\\') {
                    G[y * 3][x * 3] = G[y * 3 + 1][x * 3 + 1] = G[y * 3 + 2][x * 3 + 2] = 1;
                }
            }
        }

        int regions = 0, m = n * 3;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < m; ++x) {
                if (G[y][x] == 0) {
                    dfs(G, y, x);
                    regions++;
                }
            }
        }
        return regions;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] grid1 = {" /", "/ "};
        System.out.println(solution.regionsBySlashes(grid1)); // 2

        String[] grid2 = {" /", "  "};
        System.out.println(solution.regionsBySlashes(grid2)); // 1

        String[] grid3 = {"/\\", "\\/"};
        System.out.println(solution.regionsBySlashes(grid3)); // 5
    }
}

// 6ms 73.53% 42.6MB 43.81%
// disjoint set
// O(N^2) O(N^2)
class UnionFind {
    int[] prnt;
    int[] rank;

    public UnionFind(int n) {
        this.prnt = new int[n];
        this.rank = new int[n];

        for (int i = 0; i < n; ++i) {
            this.prnt[i] = i;
            this.rank[i] = 0;
        }
    }

    public int find(int x) {
        if (prnt[x] != x) {
            prnt[x] = find(prnt[x]);
        }
        return prnt[x];
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                prnt[rootY] = prnt[rootX];
            } else if (rank[rootX] < rank[rootY]) {
                prnt[rootX] = prnt[rootY];
            } else {
                prnt[rootY] = prnt[rootX];
                rank[rootX]++;
            }
        }
    }
}
class Solution {
    
    public int regionsBySlashes(String[] grid) {
        int n = grid.length, m = n * n * 4;
        UnionFind uf = new UnionFind(m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j) * 4;
                char c = grid[i].charAt(j);

                if (c == '/') {
                    uf.union(idx + 0, idx + 3);
                    uf.union(idx + 1, idx + 2);
                } else if (c == '\\') {
                    uf.union(idx + 0, idx + 1);
                    uf.union(idx + 2, idx + 3);
                } else {
                    uf.union(idx + 0, idx + 1);
                    uf.union(idx + 1, idx + 2);
                    uf.union(idx + 2, idx + 3);
                }

                if (i + 1 < n) {
                    uf.union(idx + 2, (idx + 4 * n) + 0);
                }
                if (j + 1 < n) {
                    uf.union(idx + 1, (idx + 4) + 3);
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < m; ++i) {
            if (uf.find(i) == i) {
                regions++;
            }
        }

        return regions;
    }

}
