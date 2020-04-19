

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws Exception {
		int n = 0;
		int[] arr = new int[1000001];
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(reader.readLine());
		arr[1] = 0;
		for(int i=2; i<=n; i++) {
			arr[i] = arr[i-1] + 1;
			if(i%2 == 0) {
				arr[i] = Math.min(arr[i], arr[i/2] + 1);
			}
			if(i%3 == 0) {
				arr[i] = Math.min(arr[i], arr[i/3] + 1);
			}
		}
		System.out.println(arr[n]);
	}
}
