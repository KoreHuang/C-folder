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
public class MagicRing {

    public static void main(String []args){
        int n,k;
        Scanner scn=new Scanner(System.in);
        n=scn.nextInt();
        k=scn.nextInt();
        int a[]=new int[n+1];
        for (int i=1;i<=n;i++) {
            a[i]=scn.nextInt();
        }


        for (int i=0;i<k;i++) {
            int m = a[1];
            for (int j=0;j<=n;j++) {
                if(j == n) {
                    a[j] = (m+a[j])%100;
                }else {
                    a[j] = (a[j+1]+a[j])%100;
                }

            }
        }

        for (int i=1;i<n;i++) {
            System.out.printf("%d ",a[i]);
        }
        System.out.printf("%d",a[n]);

        }

}
