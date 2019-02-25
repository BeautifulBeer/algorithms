import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws NumberFormatException, IOException{
		int T, N, H, W, x=0, y=0, direct=0, tmp_x, tmp_y;
		//x is height, y is col
		char[] dic = {'<','^','>','v'};
		int[] dx = {0, -1, 0, 1};
		int[] dy = {-1, 0, 1, 0};
		char[][] map;
		String str;
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
				BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		T = Integer.parseInt(reader.readLine());
		map = new char[20][];
		for(int i=0; i<20; i++) {
			map[i] = new char[20];
		}
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(reader.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			for(int i=0; i<H; i++) {
				str = reader.readLine();
				for(int j=0; j<str.length(); j++) {
					map[i][j] = str.charAt(j);
					if(map[i][j] == '<') {
						x = i;
						y = j;
						direct = 0;
					}else if(map[i][j] == '>') {
						x = i;
						y = j;
						direct = 2;
					}else if(map[i][j] == '^') {
						x = i;
						y = j;
						direct = 1;
					}else if(map[i][j] == 'v') {
						x = i;
						y = j;	
						direct = 3;
					}

				}
			}
			N = Integer.parseInt(reader.readLine());
			str = reader.readLine();
			for(int i=0; i<str.length(); i++) {
//				for(int j=0; j<H; j++) {
//					for(int k=0; k<W; k++) {
//						sb.append(map[j][k]);
//					}
//					sb.append('\n');
//				}
				if(str.charAt(i) != 'S') {
					if(str.charAt(i) == 'U') {
						direct = 1;
					}else if(str.charAt(i) == 'D') {
						direct = 3;
					}else if(str.charAt(i) == 'L') {
						direct = 0;
					}else if(str.charAt(i) == 'R') {
						direct = 2;
					}
					if(x + dx[direct] >= 0 && x + dx[direct] < H && y + dy[direct] >= 0 && y + dy[direct] < W && map[x+dx[direct]][y+dy[direct]] == '.') {
						map[x][y] = '.';
						x += dx[direct];
						y += dy[direct];
					}
					map[x][y] = dic[direct];
				}else {
					tmp_x = x; tmp_y = y;
					while(tmp_x + dx[direct] >= 0 && tmp_x + dx[direct] < H && tmp_y + dy[direct] >= 0 && tmp_y + dy[direct] < W) {
						tmp_x += dx[direct];
						tmp_y += dy[direct];
//						System.out.println(tmp_x + ", " + tmp_y);
						if(map[tmp_x][tmp_y] == '#') {
							break;
						}else if(map[tmp_x][tmp_y] == '*') {
							map[tmp_x][tmp_y] = '.';
							break;
						}
					}
				}
			}
			sb.append("#").append(t).append(' ');
			for(int i=0; i<H; i++) {
				for(int j=0; j<W; j++) {
					sb.append(map[i][j]);
				}
				sb.append('\n');
			}
		}
		System.out.println(sb.toString());

	}

}
