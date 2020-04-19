import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {
	
	static int T;
	static StringTokenizer st;
	static int data[] = new int[12+1];
	static int cache[] = new int[12+1];
	static int cost[] = new int[4];
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine().trim());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(reader.readLine());
			for(int i=0; i<4; i++) {
				cost[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(reader.readLine());
			for(int i=1; i<=12; i++) {
				data[i] = Integer.parseInt(st.nextToken());
			}
			cache[0] = 0;
			for(int i=1; i<=12; i++) {
				cache[i] = Math.min(cache[i-1]+cost[0]*data[i], cache[i-1]+cost[1]);
				if(i >= 3) {
					cache[i] = Math.min(cache[i], cache[i-3] + cost[2]);
				}
			}
			cache[12] = Math.min(cache[12], cost[3]);
			System.out.println("#"+t+" "+cache[12]);
		}
	}
}
