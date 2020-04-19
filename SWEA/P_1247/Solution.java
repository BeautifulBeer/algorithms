import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {
	static int n, greedy;
	static Customer home, company;
	static Customer temp;
	static int result;

	static class Customer{
		int x, y;

		public Customer(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return x + " / " + y;
		}
	}

	static void swap(Customer[] arr, int x, int y) {
		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}

	static int distance(Customer a, Customer b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}

	static void search(Customer[] arr, int depth, int cost) {
		if(greedy < cost) {
			return;
		}
		if(depth == n) {
			cost += distance(arr[n-1], company);
			result = Math.min(result, cost);
			return;
		}
		for(int i=depth; i<n; i++) {
			swap(arr, depth, i);
			if(depth == 0) {
				search(arr, depth+1, cost + distance(home, arr[depth]));
			}else {
				search(arr, depth+1, cost + distance(arr[depth-1], arr[depth]));
			}
			swap(arr, depth, i);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		String[] tokens;
		Customer tmpC;
		Customer[] customers = new Customer[10];
		boolean[] checked = new boolean[10];
		int testCase, tmp, tmpidx = 0, minDistance;
				BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			result = Integer.MAX_VALUE;
			n = Integer.parseInt(reader.readLine());
			tokens = reader.readLine().split("\\s");
			home = new Customer(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
			company = new Customer(Integer.parseInt(tokens[2]), Integer.parseInt(tokens[3]));
			for(int j=2; j<tokens.length/2; j++) {
				customers[j-2] = new Customer(Integer.parseInt(tokens[j*2]), Integer.parseInt(tokens[j*2+1]));
				checked[j-2] = false;
			}
			greedy = 0;
			tmpC = company;
			for(int j=0; j<n; j++) {
				minDistance = Integer.MAX_VALUE;
				for(int k=0; k<n; k++) {
					if(!checked[k]) {
						tmp = distance(tmpC, customers[k]);
						if(minDistance > tmp) {
							tmpidx = k;
							minDistance = tmp;
						}
					}
				}
				tmpC = customers[tmpidx];
				checked[tmpidx] = true;
				greedy += minDistance;
			}
			greedy += distance(tmpC, home);
			search(customers, 0, 0);
			System.out.println("#" + i + " " + result);
		}
	}
}
