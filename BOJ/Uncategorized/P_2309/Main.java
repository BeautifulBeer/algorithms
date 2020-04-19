import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;

public class Main {

	public static void findDwarf(int[] arr, Deque<Integer> dq, int idx, int sum) {
		if(sum == 100 & dq.size() == 7) {
			ArrayList<Integer> list = new ArrayList<Integer>(dq);
			Collections.sort(list);
			for(int num : list) {
				System.out.println(num);
			}
			return;
		}
		if(idx == arr.length || dq.size() == 7) {
			return;
		}
		dq.addFirst(arr[idx]);
		findDwarf(arr, dq, idx+1, sum+arr[idx]);
		dq.removeFirst();
		findDwarf(arr, dq, idx+1, sum);
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int[] arr;
		Deque<Integer> dq = new LinkedList<Integer>();
		arr = new int[9];
		for(int i=0; i<9; i++) {
			arr[i] = Integer.parseInt(reader.readLine()); 
		}
		findDwarf(arr, dq, 0, 0);
	}
	
}
