package JD;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/7.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/7
 */
public class EitherOr {
    public static long solve(){
        long result=0;

        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        String str1;
        scanner.nextLine();
        str1=scanner.nextLine();
        String str2;
        str2=scanner.nextLine();

        for(int i=0;i<n;i++){
            result+=((str1.charAt(n-i-1)-'0')^(str2.charAt(n-i-1)-'0'))*Math.pow(2,i);
        }
        return result;
    }
    public static void main(String []args){
        System.out.println(solve());
    }
}
