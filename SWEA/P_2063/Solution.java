import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Solution {
	
	public static void main(String[] args) throws Exception {
		int N, tmp;
		String[] tokens;
		int[] arr;
//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		tokens = reader.readLine().split(" ");
		arr = new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(tokens[i]);
		}
		for(int i=N; i>0; i--) {
			for(int j=1; j<i; j++) {
				if(arr[j-1] > arr[j]) {
					tmp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = tmp;
				}
			}
		}
		System.out.println(arr[N/2]);
	}

}
