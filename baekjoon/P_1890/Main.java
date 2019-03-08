import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N, tmpx, tmpy;
	static long path;
	static int map[][];
	static long paths[][];
		
	public static void main(String[] args) throws Exception{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		map = new int[N][N];
		paths = new long[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(reader.readLine());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				paths[i][j] = 0;
			}
		}
		paths[0][0] = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(map[i][j] == 0)continue;
				tmpx = i + map[i][j];
				tmpy = j + map[i][j];
				if(tmpx >= 0 && tmpx < N) {
					paths[tmpx][j] += paths[i][j];
				}
				if(tmpy >= 0 && tmpy < N) {
					paths[i][tmpy] += paths[i][j];
				}
			}
		}
		System.out.println(paths[N-1][N-1]);
	}
}
