class DisjointSet {
    int[] prnt;

    DisjointSet(int n) {
        this.prnt = new int[n];
        for (int i = 0; i < n; ++i) {
            prnt[i] = i;
        }
    }

    public void merge(int a, int b) {
        prnt[find(a)] = prnt[find(b)];
    }

    public int find(int u) {
        if (prnt[u] != u) {
            prnt[u] = find(prnt[u]);
        }
        return prnt[u];
    }
    
}

class MainApp {
    public static void main(String[] args) {
        DisjointSet ds = new DisjointSet(10);
        ds.merge(1, 2);
        ds.merge(2, 3);
    }
}
