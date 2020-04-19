import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution { 
	static Deque<Integer> stack = new ArrayDeque<Integer>();
	static int result;
	static int dx[] = {0, 0, 1, -1};	
	static int dy[] = {1, -1, 0, 0};
	static int map[][];
	static boolean[] check = new boolean[10000000];
 
	public static void main(String[] args) throws Exception{
		int testCase, num, x, y, depth, cnt;
		String[] tokens;
//				BufferedReader reader = new BufferedReader(new FileReader("src/sample_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		map = new int[4][];
		for(int i=0; i<4; i++) {
			map[i] = new int[4];
		}
		for(int t=1; t<=testCase; t++) {
			result = 0;
			for(int i=0; i<10000000; i++) {
				check[i] = false;
			}
			for(int i=0; i<4; i++) {
				tokens = reader.readLine().split("\\s");
				for(int j=0; j<tokens.length; j++) {
					map[i][j] = Integer.parseInt(tokens[j]);
				}
			}
			for(int i=0; i<4; i++) {
				for(int j=0; j<4; j++) {
					stack.clear();
					stack.addFirst(0);
					stack.addFirst(j);
					stack.addFirst(i);
					stack.addFirst(0);
					while(!stack.isEmpty()) {
						num = stack.removeFirst();
						x = stack.removeFirst();
						y = stack.removeFirst();
						depth = stack.removeFirst();
						if(depth == 7) {
							if(!check[num]) {
								result++;
								//								System.out.println(num);
								check[num] = true;
							}
							continue;
						}
						if(x < 0 || x >= 4 || y < 0 || y >= 4) {
							continue;
						}
						num = num * 10 + map[x][y];
						for(int k=0; k<4; k++) {
							stack.addFirst(depth+1);
							stack.addFirst(y+dy[k]);
							stack.addFirst(x+dx[k]);
							stack.addFirst(num);
						}
					}
				}
			}
			System.out.println("#" + t + " " + result);
		}

	}
}