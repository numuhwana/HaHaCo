import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main{

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(st.nextToken());
		int tmp;
		BigInteger [] crs=new BigInteger[1001];
		for(int i=0;i<n;i++) {//과목들
			st=new StringTokenizer(br.readLine());
			tmp=Integer.parseInt(st.nextToken());
			crs[i]=new BigInteger("0");
			for(int j=0;j<tmp;j++) {//과목들에 대한 비트를 표시한다.
				BigInteger bg=new BigInteger("1");
				bg=bg.shiftLeft(Integer.parseInt(st.nextToken()));
				crs[i]=crs[i].or(bg);
			}
		}
		
		//long[][] empsp = new long[10001][50];
		st=new StringTokenizer(br.readLine());
		BigInteger zero=new BigInteger("0");
		int m=Integer.parseInt(st.nextToken());
		for(int i=0;i<m;i++) {
			int cnt=0;
			BigInteger tmp2=new BigInteger("0");
			st=new StringTokenizer(br.readLine());
			tmp=Integer.parseInt(st.nextToken());
			for(int j=0;j<tmp;j++) {
			BigInteger bg=new BigInteger("1");
			tmp2=tmp2.or(bg.shiftLeft(Integer.parseInt(st.nextToken())));
			}
			tmp2=tmp2.not();//비어있지 않은 시간을 구한다.
			for(int j=0;j<n;j++) {//과목들과 비어있지 않은 시간을 and 연산하여 0이면 과목을 넣을수 있다는 뜻이다.
				if(tmp2.and(crs[j]).compareTo(zero)==0) cnt++;
			}
			StringBuilder sb = new StringBuilder();
			sb.append(cnt).append("\n");
			System.out.print(sb);
		}
	}

}
//https://riptutorial.com/ko/java/example/12139/biginteger%EC%97%90-%EB%8C%80%ED%95%9C-%EB%B0%94%EC%9D%B4%EB%84%88%EB%A6%AC-%EB%85%BC%EB%A6%AC-%EC%97%B0%EC%82%B0
