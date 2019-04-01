import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	
	static int N, T, originX, originY, result, tmpx, tmpy;
	// ����
	static int map[][] = new int[20][20];
	// �Ծ����� Ȯ��
	static boolean dessert[] = new boolean[100 + 1];
	// �����̴� ���� = 0 : ������ �Ʒ� , �������� �ð����
	static int delta[][] = {
			{1, 1}, 
			{1, -1},
			{-1 ,-1},			
			{-1, 1}
	};
	
	static void search(int x, int y, int direction) {
		/*System.out.println(x + " " + y + " " + direction);*/
		//����������� �ٽ� ���ƿ���,
		if(originX == x && originY == y) {
			int dCount = 0;
			for(int i=1; i<=100; i++) {
				if(dessert[i]) {
					dCount++;
				}
			}
			if(result < dCount) {
				result = dCount;
			}
			return;
		}
		//�̹� �Ծ��� ����Ʈ üũ
		if(dessert[map[x][y]])return;
		dessert[map[x][y]] = true;
		for(int i=0; i<=1; i++) {
			if(direction+i >= 4)continue;
			tmpx = x + delta[direction+i][0];
			tmpy = y + delta[direction+i][1];
			// ���� üũ
			if(tmpx >= 0 && tmpx < N && tmpy >= 0 && tmpy < N) {
				/*System.out.println("tmp : " + tmpx + " " + tmpy + " " + (direction+i));*/
				search(tmpx, tmpy, direction+i);
			}
		}
		dessert[map[x][y]] = false;	
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		System.setIn(new FileInputStream("src/sample_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			result = 0;
			N = Integer.parseInt(reader.readLine());
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			Arrays.fill(dessert, false);
			for(int i=0; i<N-1; i++) {
				for(int j=1; j<N-1; j++) {
					dessert[map[i][j]] = true;
					originX = i; originY = j;
					search(i+delta[0][0], j+delta[0][1], 0);
					dessert[map[i][j]] = false;
				}
			}
			
			if(result == 0)result = -1;
			System.out.println("#"+t+" "+result);
		}
	}
}
