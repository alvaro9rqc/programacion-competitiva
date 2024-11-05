import java.util.*;
import java.math.*;
public class _10359_Tiling {
  public static void main (String args[]) {
    BigInteger a[] = new BigInteger[251];
    BigInteger uno = new BigInteger("1");
    a[0]=new BigInteger("0");
    a[1]=new BigInteger("0");
    a[2]=new BigInteger("2");
    for(int i = 3; i < 251; ++i) 
      a[i] = a[i-2].multiply(a[2]).add(a[i-1].add(a[2]));
    //System.out.println(a[3]);
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextLine()) {
      System.out.println(a[sc.nextInt()].add(uno));
      sc.nextLine();
    }
  }
}

