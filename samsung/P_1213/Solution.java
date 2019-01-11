import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
	

    public static void main(String[] args) throws Exception{
    	int testCase, answer;
    	String target, line;
    	Pattern p;
    	Matcher m;
//    	BufferedReader reader = new BufferedReader(new FileReader("src\\test_input.txt"));
    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//    	testCase = Integer.parseInt(reader.readLine());
    	for(int i=1; i<=10; i++) {
    		testCase = Integer.parseInt(reader.readLine());
    		answer = 0;
    		target = reader.readLine();
    		line = reader.readLine();
    		p = Pattern.compile(target);
    		m = p.matcher(line);
    		while(m.find()) {
    			answer++;
    		}
    		System.out.println("#"+testCase+" "+answer);    		
    	}
    }
}