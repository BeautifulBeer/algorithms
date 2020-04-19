import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {

	static class Student implements Comparable<Student>{
		int from, to;

		public Student(int from, int to) {
			super();
			this.from = from;
			this.to = to;
		}

		@Override
		public int compareTo(Student o) {
			// TODO Auto-generated method stub
			return (from == o.from)?to - o.to: from - o.from;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		int maxNum = 200, T, N, result=0, from, to;
		StringTokenizer st;
		PriorityQueue<Student> pq = new PriorityQueue<>();
		int roomNum[] = new int[maxNum+1];
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//		BufferedReader reader = new BufferedReader(new FileReader("src/sample_input.txt"));
		T = Integer.parseInt(reader.readLine().trim());
		for(int t=1; t<=T; t++) {
			result = 0;
			N = Integer.parseInt(reader.readLine().trim());
			for(int i=1; i<=maxNum; i++) {
				roomNum[i] = 0;
			}
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine().trim());
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				if(from % 2 == 0) {
					from = from / 2;
				}else {
					from = from / 2 + 1;
				}
				if(to % 2 == 0) {
					to = to / 2;
				}else {
					to = to / 2 + 1;
				}
				if(from > to) {
					pq.offer(new Student(to, from));
				}else {
					pq.offer(new Student(from, to));
				}
			}
			Student tmp;
			while(!pq.isEmpty()) {
				tmp = pq.poll();
				for(int i=tmp.from; i<=tmp.to; i++) {
					roomNum[i]++;
				}
			}
			for(int i=1; i<=maxNum; i++) {
				result = Math.max(result, roomNum[i]);
			}
			System.out.println("#"+t+" "+result);
		}
	}

}
