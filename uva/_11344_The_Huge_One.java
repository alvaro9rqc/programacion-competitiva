import java.util.*;
import java.math.*;

public class _11344_The_Huge_One {
  public static int gcd(int a, int b) {
    return (b == 0)? a: gcd(b, a % b);
  }
  public static int lcm (int a, int b) {
    return a / gcd(a,b) * b;
  }
  public static void main (String args[]) {
    int t;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();
    sc.nextLine();
    while (t-- > 0) {
      String n = sc.nextLine();
      int m = sc.nextInt();
      //System.out.println("->" + m);
      int div = 1;
      HashSet<Integer> set = new HashSet<Integer>();
      for (int i = 0; i < m; ++i) {
        set.add(sc.nextInt());
      }
      sc.nextLine();
      for (Integer i : set) div= lcm(div, i);
      //System.out.println(div);
      BigInteger x = new BigInteger(n);
      BigInteger y = new BigInteger(Integer.toString(div));
      String mod = x.mod(y).toString(10);
      //System.out.println(mod);
      if (mod.equals("0")) 
        System.out.println(n + " - Wonderful.");
      else
        System.out.println(n + " - Simple.");
    }
  }
}

