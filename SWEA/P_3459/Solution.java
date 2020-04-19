import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException{
		int T;
		long tmp, N, turn, inc;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			inc = 4;
			tmp = 1;
			turn = 1;
			N = Long.parseLong(reader.readLine());
			if(N == 1) {
				System.out.println("#"+t+" Bob");
			}else {
				while(tmp < N) {
					tmp += inc;
					if(N <= tmp) {
						System.out.println("#"+t+" Alice");
						break;
					}
					tmp += inc;
					if(N <= tmp) {
						System.out.println("#"+t+" Bob");
						break;
					}
					inc *= 4;
				}	
			}
		}
	}
}
