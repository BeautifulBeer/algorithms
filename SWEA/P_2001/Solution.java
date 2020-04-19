import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
 	
    public static void main(String[] args) throws Exception{
       int testCase, N, M, result, tmp_idx, tmp;
       int[][] arr = new int[15][15];
//       BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
       BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st;
       testCase = Integer.parseInt(reader.readLine());
       for(int i=1; i<=testCase; i++) {
    	   result = 0;
    	   st = new StringTokenizer(reader.readLine());
    	   N = Integer.parseInt(st.nextToken());
    	   M = Integer.parseInt(st.nextToken());
    	   //load data
    	   for(int j=0; j<N; j++) {
    		   st = new StringTokenizer(reader.readLine());
    		   tmp_idx = 0;
    		   while(st.hasMoreTokens()) {
    			   arr[j][tmp_idx] = Integer.parseInt(st.nextToken());
    			   tmp_idx++;
    		   }
    	   }
    	   
    	   for(int j=M-1; j<N; j++) {
    		   for(int k=M-1; k<N; k++) {
    			   tmp = 0;
    			   for(int l=0; l<M; l++) {
    				   for(int m=0; m<M; m++) {
    					   tmp += arr[j-l][k-m];
    				   }
    			   }
    			   if(result < tmp) {
    				   result = tmp;
    			   }
    		   }
    	   }
    	   System.out.format("#%d %d\n", i, result);
       }
    }
}