import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
	
		
	public static long modular(long base, long exp, long mod) {
//		System.out.println(base + ", " + exp + ", " + mod);
		if(base == 1 || exp == 0)return 1;
		if(exp == 1)return base % mod;
		if(exp % 2 != 0) {
			return (base * modular((base * base)%mod, exp/2, mod)) % mod;
		}else {
			return modular((base * base)%mod, exp/2, mod);
		}
	}
	
	public static void main(String[] args) throws Exception{
		String[] tokens;
		int testCase, N, R;
		long result;
		long mod = 1234567891;
		long exp = mod - 2;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			result = 1;
			tokens = reader.readLine().split("\\s");
			N = Integer.parseInt(tokens[0]);
			R = Integer.parseInt(tokens[1]);
			if(N==R || R==0) {
				result = 1;
			}else {
				for(long j=2; j<=R; j++) {
					result = (result * j) % mod;
				}
				result = modular(result, exp, mod);
				for(long j=N-R+1; j<=N; j++) {
					result = (result * j) % mod;
				}
				
			}
			System.out.println("#" + i + " " + result);
		}
	}
}