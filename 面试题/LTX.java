import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/3/25.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/3/25
 */
public class LTX {

    static final int m_length=1<<26;

    static boolean saw[]=new boolean[30];
    static   long total[]=new long[m_length];
    static int get_status(){
        int now=0,d=1;
        for(int i=0;i<26;i++){
            if(saw[i])
                now+=1*d;
            d<<=1;
        }
        return now;
    }
    static long C(long l){
        return l*(l-1)>>2;
    }
    public static void  main(String []args){

        long answ=0;
        int status;
        String str;
        Scanner scanner=new Scanner(System.in);
        str=scanner.nextLine();
        for(int i=0;i<str.length();i++)
        {
            saw[str.charAt(i)-'a']=(saw[str.charAt(i)-'a']?false:true);
            status=get_status();
            total[status]++;
        }
        for(int i=0;i<m_length;i++)


            System.out.println(answ+total[0] );

    }
}
