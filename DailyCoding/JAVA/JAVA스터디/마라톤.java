import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String,Integer> m=new HashMap<String,Integer>();
        for(int i=0;i<completion.length;i++){
            if(m.get(completion[i])!=null){
                m.put(completion[i],m.get(completion[i])+1);
            }else{
             m.put(completion[i],1);
            }
        }
        for(int i=0;i<participant.length;i++){
            if(m.get(participant[i])==null){ answer=participant[i];}
            else{
                if(m.get(participant[i])>=1){
                m.put(participant[i],m.get(participant[i])-1);
                }else{
                    answer=participant[i];
                }
            }
        }
        return answer;
    }
}