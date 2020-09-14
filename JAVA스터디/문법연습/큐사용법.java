
//큐 사용 예
import java.util.Queue;
import java.util.LinkedList;
public class Program {
	public static void main(String[] args){
		Queue<String> q = new LinkedList<String>();
		q.offer("강감찬"); //"강감찬"
		q.offer("홍길동"); //"강감찬","홍길동"
		System.out.println(q.peek());//"강감찬" 참조
		//여전히 "강감찬","홍길동"
		
		System.out.println(q.poll());//"강감찬" 꺼냄, 현재 "홍길동"
		q.offer("이순신"); //"홍길동", "이순신"
		q.offer("김구"); //"홍길동", "이순신", "김구"
		while(q.isEmpty()==false){
			System.out.println(q.poll());
			//"홍길동", "이순신", "김구" 순으로 꺼냄
		}		
	}