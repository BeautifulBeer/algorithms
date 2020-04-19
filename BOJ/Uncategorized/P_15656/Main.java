import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static StringBuilder sb;
	static int N, M;
	static int[] perm;
	static int[] numbers;
	
	static void permutation(int depth) {
		if(depth == M) {
			for(int i=0; i<M; i++) {
				sb.append(perm[i]).append(' ');
			}
			sb.append('\n');
			return;
		}
		for(int i=0; i<N; i++) {
			perm[depth] = numbers[i];
			permutation(depth+1);
		}
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException {
		sb = new StringBuilder();
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
		numbers = new int[N]; perm = new int[M];
		st = new StringTokenizer(reader.readLine());
		for(int i=0; i<N; i++) {
			numbers[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(numbers);
		permutation(0);
		System.out.println(sb.toString());
	}

}
