package renren;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/9.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/9
 */
public class Main {

    public static int gcd(int a, int b) {
        int t;
        if (a < b) {
            t = a;
            a = b;
            b = t;
        }
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        int chocllate[]=new int[n];



        for(int i=0;i<n;i++){
            chocllate[i]=scanner.nextInt();
        }

        int i, j;

        j = chocllate[0];
        for (i = 1; i < n; ++i)
            j = gcd(j, chocllate[i]);

        System.out.print(j);
    }

}
