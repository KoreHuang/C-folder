package DiDi;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/22.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/22
 */
public class SolveTetris {


    public static int maxEnvelopes(int[][] envelopes) {
        Comparator<int[]> c=new Comparator<int[]>() {
            public int compare(int[] e1, int[] e2) {
                return e1[0]-e2[0];
            }
        };
        Arrays.sort(envelopes, c);
        int max=0;
        int[] res=new int[envelopes.length];
        for (int i = 0; i < res.length; i++) {
            res[i]=1;
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0]<envelopes[i][0]&&envelopes[j][1]<envelopes[i][1]) {
                    res[i]=Math.max(res[i], 1+res[j]);
                }
            }
            max=Math.max(max, res[i]);
        }
        return max;
    }

    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        int [][] terises=new int[n][2];
        for(int i=0;i<n;i++){
            terises[i][0]=scanner.nextInt();
            terises[i][1]=scanner.nextInt();
        }
        System.out.println(maxEnvelopes(terises));
    }

}
