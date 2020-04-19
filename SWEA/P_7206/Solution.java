import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.OptionalInt;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, N;
	static HashMap<Integer, Integer> value = new HashMap<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			value.clear();
			N = Integer.parseInt(reader.readLine());
			System.out.println("#"+t+" "+getTurns(N));
		}
	}
	
	static int getTurns(int num) {
		if(num < 10)return 0;
		if(value.containsKey(num)) {
			return value.get(num);
		}
		String str = String.valueOf(num);
		int len = str.length(), count = 0;
		for(int i=1; i<(1<<len); i++) {
			int mul = 1, tmp = 0;
			for(int j=0; j<len; j++) {
				if((i & (1 << j)) == 0) {
					tmp = tmp * 10 + (str.charAt(j)-'0');
				}else {
					mul *= tmp;
					tmp = str.charAt(j)-'0';
				}
			}
			mul *= tmp;
			tmp = getTurns(mul);
			count = Math.max(count, tmp);
		}
		value.put(num, ++count);
		return count;
	}
}
