import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		int N, result = 0;
		Integer[] a, b;
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		a = new Integer[N];
		b = new Integer[N];
		st = new StringTokenizer(reader.readLine());
		for(int i=0; i<N; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(reader.readLine());
		for(int i=0; i<N; i++) {
			b[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(a);
		Arrays.sort(b, Collections.reverseOrder());
		for(int i=0; i<N; i++) {
			result += a[i] * b[i];
		}
		System.out.println(result);
	}
}
