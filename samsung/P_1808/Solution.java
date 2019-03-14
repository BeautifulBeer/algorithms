
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static int T, X, result;
	static int INF = 10000000;
	static int dp[] = new int[1000000+1];
	
	static int solve(int num) {
		if(dp[num] != 0) {
			return dp[num];
		}
		int num1, num2;
		dp[num] = count(num);
		for(int i=2; i<=Math.sqrt(num); i++) {
			if(num % i == 0) {
				num1 = solve(i);
				num2 = solve(num/i);
				if(num1 != INF && num2 != INF) {
					dp[num] = Math.min(dp[num], num1 + num2 + 1);
				}
			}
		}		
		return dp[num];
	}
	
	static int count(int num) {
		int c = 0, t;
		do {
			t = num % 10;
			if(dp[t] != 1) {
				return dp[t];
			}
			c++;
			num = num / 10;
		}while(num != 0);
		return c;
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(reader.readLine());
			for(int i=0; i<10; i++) {
				dp[i] = (Integer.parseInt(st.nextToken()) == 1)?1:INF;
			}
			X = Integer.parseInt(reader.readLine());
			for(int i=10; i<=X; i++) {
				dp[i] = 0;
			}
			solve(X);
			if(dp[X] == INF) {
				System.out.println("#"+t+" -1");
			}else {
				System.out.println("#"+t+" "+(dp[X]+1));
			}
			
		}
	}

}
