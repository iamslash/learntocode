// Copyright (C) 2016 by iamslash

// > java MainApp

import java.util.Scanner;

// > java Mainapp
public class MainApp {
  private int[] CACHE = new int[1000000];

  private int CycleLen(int n) {
    // base condition
    if (n == 1)
      return 1;
    
    // memoization
    if (CACHE[n] > 0)
      return CACHE[n];

    // recursion
    if (n % 2 == 0)
      CACHE[n] = 1 + CycleLen(n / 2);
    else
      CACHE[n] = 1 + CycleLen(n * 3 + 1);
      
    return CACHE[n];
  }

  public void Solve() {
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      // init cache
      for (int i = 0; i < 1000000; ++i) {
        CACHE[i] = -1;
      }
      
      String line = s.nextLine();
      String[] split = line.split(" ");
      int I = Integer.parseInt(split[0]);
      int J = Integer.parseInt(split[1]);
      int r = 0;

      for (int i = I; i <= J; ++i) {
        r = Math.max(r, CycleLen(i));
      }
      
      System.out.println(String.format("%d %d %d", I, J, r));
    }
  }
  
  public static void main(String[] args) {
    MainApp mainapp = new MainApp();
    mainapp.Solve();
  }
}
