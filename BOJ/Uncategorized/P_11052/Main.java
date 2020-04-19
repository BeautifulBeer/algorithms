

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception{
		int N;
		int tmp;
		int[] cards;
		int[] cache;
		String[] tokens;
		//				BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		cards = new int[N+1];
		cache = new int[N+1];
		tokens = reader.readLine().split("\\s");
		for(int i=0; i<N; i++) {
			cards[i+1] = Integer.parseInt(tokens[i]);
		}
		tmp = -1;
		cache[0] = 0;
		for(int i=1; i<=N; i++) {
			cache[i] = cards[i]; 
			for(int j=0; j<i; j++) {
				tmp = Math.max(cache[j] + cache[i-j], tmp);
			}
			cache[i] = tmp;
		}
		System.out.println(cache[N]);
	}
}
