import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException{
		StringBuilder sb = new StringBuilder();
		int T, N, P, from, to;
		int[] bus = new int[5000 + 1];
		StringTokenizer st;
//		BufferedReader reader = new BufferedReader(new FileReader("src/s_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			sb.setLength(0);
			Arrays.fill(bus, 0);
			N = Integer.parseInt(reader.readLine());
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				for(int j=from; j<=to; j++) {
					bus[j]++;
				}
			}
			sb.append('#').append(t).append(' ');
			P = Integer.parseInt(reader.readLine());
			for(int i=0; i<P-1; i++) {
				sb.append(bus[Integer.parseInt(reader.readLine())]).append(' ');
			}
			sb.append(bus[Integer.parseInt(reader.readLine())]).append('\n');
			System.out.print(sb.toString());
		}
	}
}
