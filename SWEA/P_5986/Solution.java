import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Solution {
	static ArrayList<Integer> primes = new ArrayList<>();
	static int N;
		
	public static void main(String[] args) throws NumberFormatException, IOException{
		int tmp, T, result;
		boolean[] sieves = new boolean[1000];
		int[] sievePrime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		//sieve
		for(int i=0; i<sievePrime.length; i++) {
			tmp = sievePrime[i] * 2;
			while(tmp < 1000) {
				sieves[tmp] = true;
				tmp += sievePrime[i];
			}
		}
		for(int i=2; i<1000; i++) {
			if(!sieves[i]) {
				primes.add(i);
			}
		}
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			result = 0;
			N = Integer.parseInt(reader.readLine());
			for(int i=0; i<primes.size(); i++) {
					tmp = primes.get(i);
					if(tmp > N) {
						break;
					}
				for(int j=i; j<primes.size(); j++) {
					tmp = primes.get(j) + primes.get(i);
					if(tmp > N) {
						break;
					}
					for(int k=j; k<primes.size(); k++) {
						tmp = primes.get(k) + primes.get(j) + primes.get(i);
						if(tmp > N) {
							break;
						}
						if(tmp == N) {
							result++;
						}
					}
				}
			}
			System.out.println("#"+t+" "+result);
		}		
	}
}
