import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
 
    public static void main(String[] args) throws Exception{
        int testCase, end, front;
        boolean flag;
        String line;
//      BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        testCase = Integer.parseInt(reader.readLine());
        for(int i=1; i<=testCase; i++) {
            line = reader.readLine();
            front = 0;
            end = line.length()-1;
            flag = false;
            while(line.charAt(front) == line.charAt(end)) {
                if(front == end || front + 1 == end) {
                    flag = true;
                    break;
                }
                front++;
                end--;
            }
            System.out.format("#%d %d\n", i, (flag)?1:0);
        }
    }
}