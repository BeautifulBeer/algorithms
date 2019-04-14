import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {	
	
	static int N, M, K, x, y, z, tmpx, tmpy;
	static int map[][][] = new int[10+1][10+1][1011+1];
	static int buf[] = new int[1011+1];
	static int fertilizer[][] = new int[10+1][10+1];
	static int delta[][] = {
			{0, -1},
			{-1, -1},
			{-1, 0},
			{-1, 1},
			{0, 1},
			{1, 1},
			{1, 0},
			{1, -1}
	};
	
	// 나무 번식
	static void plantTree(int x, int y, int num) {
		for(int i=0; i<8; i++) {
			tmpx = x + delta[i][0]; tmpy = y + delta[i][1];
			if(tmpx < 1 || tmpx > N || tmpy < 1 || tmpy > N) {
				continue;
			}
			map[tmpx][tmpy][1] += num;
		}
	}
	
	// 살아남은 나무 수 세기
	static long countTree() {
		long result = 0;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				for(int l=1; l<=K+11; l++) {
					result += map[i][j][l];
				}
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(reader.readLine());
			for(int j=1; j<=N; j++) {
				map[i][j][0] = 5;
				fertilizer[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(reader.readLine());
			x = Integer.parseInt(st.nextToken()); y = Integer.parseInt(st.nextToken()); z = Integer.parseInt(st.nextToken());
			map[x][y][z]++;
		}
		//K년 반복
		for(int k=1; k<=K; k++) {
			// 봄, 여름
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					int dead = 0;
					for(int l=1; l<=k+10; l++) {
						buf[l] = 0;
					}
					for(int l=1; l<k+10; l++) {
						if(map[i][j][0] >= l) { // 양분이 있을때
							int v = map[i][j][0] / l - map[i][j][l];
							if(v >= 0) {
								map[i][j][0] -= map[i][j][l] * l;
								buf[l+1] = map[i][j][l];
								map[i][j][l] = 0;
							}else {
								v += map[i][j][l];
								map[i][j][0] -= v*l;
								map[i][j][l] -= v;
								buf[l+1] = v;
								dead += map[i][j][l] * (l/2);
								map[i][j][l] = 0;
							}
						}else { // 양분이 없을때
							dead += map[i][j][l] * (l/2);
							map[i][j][l] = 0;
						}
					}
					for(int l=1; l<=k+10; l++) {
						map[i][j][l] += buf[l];
					}
					map[i][j][0] += dead;
				}
			}
			
			// 가을, 겨울
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					int newTrees = 0;
					for(int l=1; l<=k+10; l++) {
						if(l % 5 == 0) {
							newTrees += map[i][j][l];
						}
					}
					plantTree(i, j, newTrees);
					map[i][j][0] += fertilizer[i][j];
				}
			}
		}
		
		long result = countTree();
		System.out.println(result);
	}
}
