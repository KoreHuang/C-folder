package toutiao;

import java.util.BitSet;
import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/18.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/18
 */
public class Main {



    public static void solve(){
        BitSet bitSetHighBit = new BitSet(Integer.MAX_VALUE);
        BitSet bitSetLowBit = new BitSet(Integer.MAX_VALUE);
        BitSet bitSetLowBitSingle = new BitSet(Integer.MAX_VALUE);
        Scanner scanner=new Scanner(System.in);
        int allNum=0;
        int repeat=0;
        long uid=-1;
        int low,high,spec;
        while (uid!=0){
            allNum++;
            uid=scanner.nextLong();
            if(uid==0) break;
            low =(int) (uid & (0x000000007fffffffl));
            high=(int)((uid & (0x3fffffff80000000l))>>31);
            spec=(int)((uid & (0x4000000000000000l))>>32);
            if(high==0&&bitSetLowBitSingle.get(low)){
                repeat++;
                continue;
            }else if(high==0){
                bitSetLowBitSingle.set(low,true);
                continue;
            }
            if(bitSetHighBit.get(high)&&bitSetLowBit.get(low)&&bitSetLowBitSingle.get(spec)){
                repeat++;
                continue;
            }else{
                bitSetHighBit.set(high,true);
                bitSetLowBit.set(low,true);
                bitSetLowBitSingle.set(spec,true);
            }
        }
        System.out.println(allNum-repeat-1);
    }

    public static void main(String []args){
        solve();
    }


}
