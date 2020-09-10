import java.util.*;

public class task {	

	public static void Solve(int n, int k, int [] a) {
		int l = n, r = -1;
		for(int i = 0; i < n; ++i) 
			if(a[i] > k) {
				l = Math.min(l, i);
				r = Math.max(r, i);
			}
		
		if(l == n) {
			assert(r == -1);
			System.out.println(n);
		}
		else {
			assert(l <= r);
			System.out.println(n + l - r - 1);
		}
	}

	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());

		int [] a = new int [1 << 7];
		for(int i = 0; i < n; ++i) a[i] = Integer.parseInt(sc.next());
		Solve(n, k, a);		
	}	
}
