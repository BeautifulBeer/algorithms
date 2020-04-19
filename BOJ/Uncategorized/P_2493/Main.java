import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	static class Tower{
		int height;
		int idx;
		
		public Tower(int height, int idx) {
			super();
			this.height = height;
			this.idx = idx;
		}
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		int N, height, index = 0, removes;
		int[] result;
		StringTokenizer st;
		LinkedList<Tower> list = new LinkedList<>();
//		ArrayList<Tower> removeList = new ArrayList<>();
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		result = new int[N];
		st = new StringTokenizer(reader.readLine());
		while(st.hasMoreTokens()) {
			height = Integer.parseInt(st.nextToken());
			if(!list.isEmpty()) {
				removes = 0;
				for(int i=list.size()-1; i>=0; i--) {
					if(list.get(i).height > height) {
						result[index] = list.get(i).idx + 1;
						break;
					}else {
						removes++;
					}
				}
				for(int i=0; i<removes; i++) {
					list.removeLast();	
				}
			}
			list.add(new Tower(height, index));
			index++;
		}
		for(int i=0; i<N; i++) {
			System.out.print(result[i] + " ");
		}
		System.out.println();
	}

}
