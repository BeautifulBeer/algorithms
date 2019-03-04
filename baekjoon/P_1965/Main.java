import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {	

	public static void main(String[] args) throws Exception{
		int n, lisLength, tmpIdx;
		int[] lis, arr;
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(reader.readLine());
		lis = new int[n]; arr = new int[n];
		st = new StringTokenizer(reader.readLine());
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		lis[0] = arr[0];
		lisLength = 1;
		for(int i=1; i<n; i++) {
			tmpIdx = 0;
			while(tmpIdx != lisLength) {
				if(lis[tmpIdx] < arr[i]) {
					tmpIdx++;
				}else {
					lis[tmpIdx] = arr[i];
					break;
				}
			}
			if(tmpIdx == lisLength) {
				lis[tmpIdx] = arr[i];
				lisLength++;
			}
		}
		System.out.println(lisLength);
	}
}
