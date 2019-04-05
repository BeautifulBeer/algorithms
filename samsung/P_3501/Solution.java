import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;
 
public class Solution {
	
	static int p, q, T, num;
	static int used[] = new int[1000000+1];
	static Stack<Integer> st = new Stack<>();
	static String dp(int p, int q) {
		st.clear();
		st.push(p);
		int idx = 0, tmp;
		StringBuilder sb = new StringBuilder();
		while(!st.isEmpty()) {
			p = st.pop();
			if(p == 0) {
				break;
			}
			if(used[p] != -1) {
				num = used[p];
				break;
			}
			used[p] = idx++;
			tmp = p;
			tmp = tmp * 10;
			sb.append(tmp / q);
			tmp = tmp % q;
			st.push(tmp);
		}
		String str = sb.toString();
		if(num == -1) {
			return str;
		}else {
			return str.substring(0, num) + "(" + str.substring(num) + ")";
		}
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		System.setIn(new FileInputStream("src/sample_input.txt"));
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine().trim());
		for(int t=1; t<=T; t++) {
			num = -1;
			st = new StringTokenizer(reader.readLine().trim());
			p = Integer.parseInt(st.nextToken()); q = Integer.parseInt(st.nextToken());
			Arrays.fill(used, -1);
			int quot = p/q;
			p = p % q;
			StringBuilder sb = new StringBuilder();
			sb.append('#').append(t).append(' ');
			sb.append(quot);
			String remains = dp(p,q).trim();
			if(!remains.contentEquals("")) {
				sb.append('.').append(remains);
			}
			System.out.println(sb.toString());
		}
	}
}