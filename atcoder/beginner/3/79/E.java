import java.util.*;
import java.math.*;
public class E {
  public static void main (String args[]) {
    int n;
    String s;
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    sc.nextLine();
    s = sc.nextLine();
    char mult[] =new char[n];
    for(int i = 0; i < n; ++i) mult[i] = '1';
    BigInteger m= new BigInteger(new String(mult));
    BigInteger sum = new BigInteger("0");
    for(int i = 1; i <= n; ++i) {
      //System.out.println(m.multiply(new BigInteger(s.substring(i-1,i))));
      int f = i * (int)( s.charAt(i-1) - '0' );
      sum = sum.add(m.multiply(new BigInteger(Integer.toString(f))));
      m= m.divide(new BigInteger("10"));
    }
    System.out.println(sum);
  }
}

