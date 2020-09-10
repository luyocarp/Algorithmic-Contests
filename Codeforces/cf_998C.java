import java.util.*;

public class task {
	public static void Solve(int n, int x, int y, String s) {
		int block_of_zeros = 0;
		boolean active = false;
		for(int i = 0; i < n; ++i) {
			if(s.charAt(i) == '0' && !active) {
				active = true;
				block_of_zeros ++;
			}
			else if(s.charAt(i) == '1') active = false;
		}
		long ans = 0;
		if(block_of_zeros == 0) ans = 0;
		else ans = y + Math.min(x, y) * (long) (block_of_zeros - 1);
		System.out.println(ans);
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);	
		int n, x, y;
		n = Integer.parseInt(sc.next());
		x = Integer.parseInt(sc.next());
		y = Integer.parseInt(sc.next());
		sc.nextLine();
		String s = sc.nextLine();
		Solve(n, x, y, s);
	}
}
