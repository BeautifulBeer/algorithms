

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		int n;
		int[] cache;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(reader.readLine());
		cache = new int[1000 + 1];
		cache[0] = 0;
		cache[1] = 1;
		cache[2] = 2;
		for(int i=3; i<=n; i++) {
			cache[i] = (cache[i-1] + cache[i-2]) % 10007;
		}
		System.out.println(cache[n]);
	}
}
