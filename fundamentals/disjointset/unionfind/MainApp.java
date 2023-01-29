class DisjointSet {
    private int[] prnts;
    public DisjointSet(int n) {
        prnts = new int[n];
        for (int i = 0; i < n; ++i) {
            prnts[i] = i;
        }
    }
    public void merge(int u, int v) {
        prnts[find(v)] = find(u);
    }
    public int find(int u) {
        return prnts[u] == u ? u : (prnts[u] = find(prnts[u]));
    }
    public void reset(int u) {
        prnts[u] = u;
    }
}

class MainApp {
    public static void main(String[] args) {
        DisjointSet ds = new DisjointSet(10);
        ds.merge(1, 2);
        ds.merge(2, 3);
    }
}
