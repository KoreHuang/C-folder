package leetcode;

/**
 * designed by Steve Ke on 2017/5/8.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/5/8
 */

/**
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the
 fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
 combination of the coins, return -1.

 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)

 Example 2:
 coins = [2], amount = 3
 return -1.
 */
public class CoinCharge {

    public static void main(String []args){
        int coins[]={186,419,83,408};
        int amount= 6249;
        System.out.println(coinChange(coins,amount));
        System.out.println(coinCharge(coins,amount));
    }

    public static int coinCharge(int []coins,int amount){
        int fn[]=new int[amount+1];

        for(int i=0;i<fn.length;i++){
            fn[i]=0x7ffffffe;
        }
        for(int j=0;j<coins.length;j++){
            if(coins[j]<fn.length)
                fn[coins[j]]=1;
        }

        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.length;j++){
                if(i-coins[j]>=0){
                    fn[i]=Math.min(fn[i],fn[i-coins[j]]+1);
                }
            }
        }
        return fn[amount]==0x7ffffffe?-1:fn[amount];
    }

  public static int  coinChange(int[] coins, int amount) {
      int fn[]=new int[amount+1]; //fn数组记录fn[i] 组成i元最少要多少枚硬币
      fn[0]=0;
      for(int i=1;i<=amount;i++){
          int min=2147483647;
          boolean tag=false;
          for(int j=i-1;j>-1;j--){
              if(fn[j]==-1) continue;    //如果对于面值为j的硬币没有解，跳出当前循环
                 else{
                  for(int k=0;k<coins.length;k++){
                      if(coins[k]==i){tag=true;min=1;j=-1;break;}

                      if(coins[k]+j>i){   //如果第k个硬币与fn[j]加起来比i大 跳过本次关于硬币数组的判断，因为再往后也不会有解
                          break;
                      }else if(coins[k]+j==i){
                          tag=true;
                          min=Math.min(min,fn[j]+1);
                      }
                  }
              }
          }
          if(tag){
              fn[i]=min;
          }else{
              fn[i]=-1;
          }
      }
      return fn[amount];
  }
}
