import java.util.*;
public class Dominos2 {
  public static void dfs(int idx, ArrayList <ArrayList<Integer>> adj, ArrayList<Boolean> parados) {
    parados.set(idx, false);
    for (int k : adj.get(idx)) {
      if (parados.get(k))
        dfs(k, adj, parados);
    }
  }
  public static void main (String args[]) {
    int t, n, m, l;
    Scanner sc = new Scanner(System.in);
    t = sc.nextInt();
    for (int i = 0; i < t; i++) {
      n = sc.nextInt();
      m = sc.nextInt();
      l = sc.nextInt();
      ArrayList <ArrayList<Integer>> adj = new ArrayList <ArrayList<Integer>> (n);
      for (int j = 0; j < n; j++) {
        adj.add(j, new ArrayList<Integer>());
      }
      //lectura de m relaciones
      for (int j = 0; j < m; j++) {
        int x = sc.nextInt();
        int y = sc.nextInt();
        if (x == y) continue;
        adj.get(x - 1).add(y - 1);
      } 
      //lista de elementos que se caera
      ArrayList<Boolean> parados = new ArrayList<>(Collections.nCopies(n, true));
      //lectura de l elementos empujados
      HashSet<Integer> empujados = new HashSet<Integer>();
      for (int j = 0; j < l; j++) {
        empujados.add(sc.nextInt() - 1); 
      }
      //System.out.println(empujados);
      for (int j : empujados) {
        dfs(j, adj, parados);
      }
      int result = 0;
      for (boolean j : parados) {
        if (!j) result++;
      }
      System.out.printf(result + "\n");


      //System.out.printf("1: %d\n", adj.get(0).get(0));
      //System.out.println(caidos);

    }
  }
}

