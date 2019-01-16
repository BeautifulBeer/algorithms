import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws Exception {
		int testCase, destRow = 0, destCol = 0, direction;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int[] dx = {0, -1, 1}; // up, left, right
		int[] dy = {-1, 0, 0};
		int[][] arr = new int[100][100];
		String[] tokens;
		for(int i=1; i<=10; i++) {
			testCase = Integer.parseInt(reader.readLine());
			direction = 0;
			for(int j=0; j<99; j++) {
				tokens = reader.readLine().split("\\s");
				for(int k=0; k<100; k++) {
					arr[j][k] = Integer.parseInt(tokens[k]);
				}
			}
			tokens = reader.readLine().split("\\s");
			for(int j=0; j<100; j++) {
				arr[99][j] = Integer.parseInt(tokens[j]);
				if(arr[99][j] == 2) {
					destRow = 99;
					destCol = j;
				}
			}
			//check reach end
			while(destRow > 0 && destCol >= 0 && destCol < 100) {
				if(direction == 0 && destCol - 1 >= 0 && arr[destRow][destCol-1] == 1) {
					direction = 1;
				}else if(direction == 0 && destCol + 1 < 100 && arr[destRow][destCol+1] == 1) {
					direction = 2;
				}else if(arr[destRow-1][destCol] == 1){
					direction = 0;
				}
				destCol += dx[direction];
				destRow += dy[direction];
			}
			System.out.println("#" + testCase + " " + destCol);
		}
	}
}



 



