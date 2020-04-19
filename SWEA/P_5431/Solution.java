import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
 
	
    public static void main(String[] args) throws Exception{
    	int testCase, N, K;
    	boolean[] submit = new boolean[100 + 1];
//    	BufferedReader reader = new BufferedReader(new FileReader("src\\sample_input.txt"));
    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st;
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	testCase = Integer.parseInt(reader.readLine());
    	for(int i=1; i<=testCase; i++) {
    		st = new StringTokenizer(reader.readLine(), " ");
    		N = Integer.parseInt(st.nextToken());
    		K = Integer.parseInt(st.nextToken());
    		st = new StringTokenizer(reader.readLine(), " ");
//        	boolean[] submit = new boolean[100 + 1];
    		for(int j=1; j<=N; j++) {
    			submit[j] = false;
    		}
    		for(int j=0; j<K; j++) {
    			submit[Integer.parseInt(st.nextToken())] = true;
    		}
    		bw.write("#" + i + " ");
    		for(int j=1; j<=N; j++) {
    			if(!submit[j]) {
    				bw.write(j + " ");	
    			}
    		}
    		bw.write("\n");
    	}
    	bw.close();
    	reader.close();
    }
}