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
	
	static int T, N, tmp, count;
	static int inputs[] = new int[100];
	static int number[] = new int[10000+1];
	
	public static void main(String[] args) throws NumberFormatException, IOException{
//		System.setIn(new FileInputStream("src/sample_input.txt"));
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			count = 1;
			N = Integer.parseInt(reader.readLine());
			st = new StringTokenizer(reader.readLine());
			Arrays.fill(number, 0);
			tmp = 0;
			number[tmp]++;
			for(int i=0; i<N; i++) {
				inputs[i] = Integer.parseInt(st.nextToken());
				tmp += inputs[i];
				for(int j=tmp; j>=0; j--) {
					if(number[j] != 0) {
						if(number[inputs[i] + j]++ == 0) {
//							System.out.println("j : " + j + " " + (inputs[i] + j));
							count++;
						}
					}
				}
			}
			System.out.println("#"+t+" "+count);
		}
	}
}
