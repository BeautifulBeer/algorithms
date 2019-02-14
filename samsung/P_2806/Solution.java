import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int result;
	static int temp;
	
	static void swap(int[] arr, int a, int b) {
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;		
	}
	
	//check promissing
	static boolean promissing(int[] arr, int depth) {
		boolean flag = true;
		if(depth == 0) {
			flag = true;
		}else {
			if(Math.abs(arr[depth] - arr[depth-1]) == 1) {
				flag = false;
			}
		}
		return flag;
	}
	
	static boolean check(int[] arr) {
		boolean flag = true;
		for(int i=0; i<arr.length; i++) {
			//move left
			for(int j=i-1; j>=0; j--) {
				if(Math.abs(i-j) == Math.abs(arr[i]-arr[j])) {
//					System.out.println(i + " , " + j);
					return false;
				}
			}
			//move right
			for(int j=i+1; j<arr.length; j++) {
				if(Math.abs(i-j) == Math.abs(arr[i]-arr[j])) {
//					System.out.println(i + " , " + j);
					return false;
				}
			}
		}
		return flag;
	}
	
	
	static void search(int[] arr, int depth) {
		if(depth == arr.length) {
			//check
			if(check(arr)) {
				result++;
			}
		}
		for(int i=depth; i<arr.length; i++) {
			swap(arr, depth, i);
			if(promissing(arr, depth)) {
				search(arr, depth+1);	
			}
			swap(arr, depth, i);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		int[] queens;
		int testCase, n;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/sample_input.txt"));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			result = 0;
			n = Integer.parseInt(reader.readLine());
			queens = new int[n];
			for(int j=0; j<n; j++) {
				queens[j] = j; 
			}
			search(queens, 0);
			System.out.println("#" + i + " " + result);			
		}
	}
}
