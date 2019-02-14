import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	static long fact[];
	static double comb[];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int testCase;
		double skillA, skillB;
		int[] primes = {2,3,5,7,11,13,17};
		double primeA , primeB;
		String[] tokens;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		fact = new long[18 + 1];
		comb = new double[18 + 1];
		fact[1] = 1;
		for(int i=2; i<=18; i++) {
			fact[i] = fact[i-1] * i;
//			System.out.println(fact[i]);
		}
		comb[2] = fact[18] / fact[16] / 2;
		comb[3] = comb[2] * 16 / 3;
		comb[5] = fact[18] / fact[13] / fact[5];
		comb[7] = fact[18] / fact[11] / fact[7];
		comb[11] = comb[7];
		comb[13] = comb[5];
		comb[17] = 18;
		for(int i=1; i<=testCase; i++) {
			tokens = reader.readLine().split("\\s");
			skillA = (double)(Integer.parseInt(tokens[0]) / 100.0);
			skillB = (double)(Integer.parseInt(tokens[1]) / 100.0);
			primeA = 0;
			primeB = 0;
			for(int j=0; j<primes.length; j++) {
				primeA += comb[primes[j]] * Math.pow(skillA, primes[j]) * Math.pow(1-skillA, 18-primes[j]);
				primeB += comb[primes[j]] * Math.pow(skillB, primes[j]) * Math.pow(1-skillB, 18-primes[j]);
			}
			primeA = 1-primeA;
			primeB = 1-primeB;
			System.out.println(String.format("#%d %.06f", i, Math.round((1-primeA*primeB)*1000000)/1000000.0));
		}
	}
}
