package Tencent;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/4.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/4
 */
public class FinCommenLCA {
     public static int[] getFullBSTree(int k){
         int fullNode=(int)Math.pow(2,k)-1;
         int []bSTree=new int[fullNode];
         bSTree[fullNode-1]=fullNode;
         for(int i=fullNode-2;i>Math.pow(2,k-1)-2;i--){
             bSTree[i]=bSTree[i+1]-2;
         }
         for(int i=fullNode/2-1;i>-1;i--){
             bSTree[i]=(bSTree[2*i+1]+bSTree[2*i+2])/2;
         }
         return bSTree;
     }
     public static int getMin(int n1,int n2,int n3){
         if(n1>n2){
             return n2>n3?n3:n2;
         }else{
             return n1>n3?n3:n1;
         }
     }

     public static int getCommenParent(int k,int[]n){
         int parent[][]=new int[3][];
         int []bStree=getFullBSTree(k);
         int s,t;
         for(int i=0;i<parent.length;i++) {
             for (int j = 0; j < bStree.length; j++) {
                 if (n[i] == bStree[j]) {
                     parent[i] = new int[(int) Math.log(j + 1) + 1];
                     s = (j - 1) / 2;
                     t = 0;
                     do {
                         parent[i][t++] = s;
                         s = (s - 1) / 2;
                     } while (s > 0);
                     parent[i][t] = s;
                 }
             }
         }
         for(int i=0;i<parent.length;i++){
              reverseArr(parent[i]);
         }
         boolean tag=true;
         t=-1;
         while (tag){
             t++;
             for(int i=1;i<parent.length;i++) {
                 if(parent[i][t]!=parent[i-1][t]||t>k){
                     tag=false;
                 }
             }
         }
         return bStree[parent[0][t-1]];
     }

     public static void reverseArr(int []data){
         int tmp;
         for(int i=0;i<data.length/2;i++){
             tmp=data[i];
             data[i]=data[data.length-i-1];
             data[data.length-i-1]=tmp;
         }
     }

     public static void main(String []args){
         Scanner scanner=new Scanner(System.in);
         int k=scanner.nextInt();
         int n[]=new int[3];
         n[0]=scanner.nextInt();
         n[1]=scanner.nextInt();
         n[2]=scanner.nextInt();
         System.out.println(getCommenParent(k,n));
     }



}
