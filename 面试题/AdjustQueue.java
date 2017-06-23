import java.util.Scanner;

public class AdjustQueue {
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        String originalQueue=scanner.nextLine();
        int length=originalQueue.length();
        int minExg=cal(originalQueue);

        System.out.println(minExg);

    }
   public static int cal(String p){
        int g=0,b=0;
        int cntg=0,cntb=0;
        for(int i=0;i<p.length();i++){
            if(p.charAt(i) == 'G'){
                g++;
                cntg += b;
            }
            else{
                b++;
                cntb += g;
            }
        }
        return cntg>cntb?cntb:cntg;
    }

}
