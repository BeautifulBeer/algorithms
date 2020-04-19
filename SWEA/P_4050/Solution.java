import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution {

	static long result;
	static int T, N;
	static Integer clothes[];
	
	public static void main(String[] args) throws IOException, NumberFormatException {
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			N = Integer.parseInt(reader.readLine());
			st = new StringTokenizer(reader.readLine());
			clothes = new Integer[N];
			for(int i=0; i<N; i++) {
				clothes[i] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(clothes, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					// TODO Auto-generated method stub
					return o2-o1;
				}
				
			});
			int tmp=0;
			result = 0;
			for(int i=0; i<N; i++) {
				if(++tmp < 3) {
					result += clothes[i];
				}else {
					tmp = 0;
				}
			}
			System.out.println("#"+t+" "+result);
		}
	}

}
