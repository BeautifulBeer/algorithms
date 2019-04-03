import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static int T, p, q, a, b, c, d, e, f, dot, R, C, S;
	static String[] masterStr;
	static String[] myStr;
	static int[][] masterCache;
	static int[][] myCache;

	// 괄호를 세는 함수
	static void CountBracket(String[] strs, int[][] arr, int length) {
		a = b = c = d = e = f = 0;
		for(int i=0; i<length; i++) {
			for(int j=0; j<strs[i].length(); j++) {
				switch(strs[i].charAt(j)) {
				case '(':
					a++;
					break;
				case ')':
					b++;
					break;
				case '{':
					c++;
					break;
				case '}':
					d++;
					break;
				case '[':
					e++;
					break;
				case ']':
					f++;
					break;
				}
			}
			arr[i][0] = a;
			arr[i][1] = b;
			arr[i][2] = c;
			arr[i][3] = d;
			arr[i][4] = e;
			arr[i][5] = f;
			dot = 0;
			for(int j=0; j<strs[i].length(); j++) {
				if(strs[i].charAt(j) == '.') {
					dot++;
				}else {
					break;
				}
			}
			arr[i][6] = dot;
		}
	}
	
	// 마스터한 사람들의 코드를 이용해서 현재 선정한 R, C, S가 유효한 값인지 확인
	static boolean check() {
		int tmp;
		for(int i=1; i<p; i++) {
			tmp = R * (masterCache[i-1][0] - masterCache[i-1][1]) +
					C * (masterCache[i-1][2] - masterCache[i-1][3]) +
					S * (masterCache[i-1][4] - masterCache[i-1][5]);
			if(masterCache[i][6] != tmp) {
				return false;
			}
		}
		return true;
	}
	
	static void solve() {
		int tmp;
		for(int i=1; i<q; i++) {
			if(myCache[i][6] == -2)continue;
			tmp = R * (myCache[i-1][0] - myCache[i-1][1]) +
					C * (myCache[i-1][2] - myCache[i-1][3]) +
					S * (myCache[i-1][4] - myCache[i-1][5]);
			if(myCache[i][6] == -1) {
				myCache[i][6] = tmp;
			}else {
				if(myCache[i][6] != tmp) {
					myCache[i][6] = -2;
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException {
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		masterStr = new String[10];
		myStr = new String[10];
		masterCache = new int[10][7];
		myCache = new int[10][7];
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(reader.readLine());
			p = Integer.parseInt(st.nextToken()); q = Integer.parseInt(st.nextToken());
			for(int i=0; i<p; i++) {
				masterStr[i] = reader.readLine();
			}
			for(int i=0; i<q; i++) {
				myStr[i] = reader.readLine();
			}
			CountBracket(masterStr, masterCache, p);
			CountBracket(myStr, myCache, q);
			for(int i=0; i<q; i++) {
				myCache[i][6] = -1;
			}
			for(R=1; R<=20; R++) {
				for(C=1; C<=20; C++) {
					for(S=1; S<=20; S++) {
						if(check()) {
							solve();
						}
					}
				}
			}
			System.out.print("#"+t+" 0 ");
			for(int i=1; i<q; i++) {
				if(myCache[i][6] == -2) {
					System.out.print("-1 ");
				}else {
					System.out.print(myCache[i][6]+" ");
				}
			}
			System.out.println();
		}
	}

}
