import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution {

	static long result, tmpMax, tmpMin;
	static int M, N, T;
	static Integer[] time;
	
	static void search(long min_time, long max_time) {
		if(min_time >= max_time) {
			result = (result > min_time) ? min_time : result;
			return;
		}
		long mid_time = (min_time + max_time) / 2, tmp = 0;
		for(int i=0; i<N; i++) {
			tmp += mid_time / time[i];
			if(tmp > M) {
				break;
			}
		}
		if(tmp < M) {
			search(mid_time+1, max_time);
		}else {
			search(min_time, mid_time);
		}
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			result = Long.MAX_VALUE;
			st = new StringTokenizer(reader.readLine());
			N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
			time = new Integer[N];
			for(int i=0; i<N; i++) {
				time[i] = Integer.parseInt(reader.readLine());
			}
			Arrays.sort(time, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					// TODO Auto-generated method stub
					return o2-o1;
				}
				
			});
			tmpMax = (long)time[0] * M;
			tmpMin = 1;
			search(tmpMin, tmpMax);
			System.out.println("#"+t+" "+result);
		}
	}

}
