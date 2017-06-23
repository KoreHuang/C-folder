package qunar;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/1.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/1
 */
public class Main {


//    int q(int n,int m){
//        if(n==1||m==1){
//            return 1;
//        }
//
//        if(n==m){
//            return q(n,m-1)+1;
//        }
//        if(n>m)
//            return q(n,m-1)+q(n-m,m);
//        if(n<m)  return q(n,n);
//    }


    public static void main(String []args){
       Scanner scanner=new Scanner(System.in);
       String input=scanner.nextLine();
       String items[]=input.split(",");
       Map<String,Integer> cnt=new LinkedHashMap<String,Integer>();
       for(String item:items){
           if(cnt.keySet().contains(item)){
               cnt.put(item,cnt.get(item)+1);
           }else {
               cnt.put(item,1);
           }
       }
       for( Map.Entry entry:cnt.entrySet()){
           System.out.println(entry.getKey()+"("+entry.getValue()+")");
       }
   }

}
//    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(System.in);
//        String src=null;
//        while (scanner.hasNext()){
//            src=scanner.nextLine();
//            char[] sqe=src.toCharArray();
//            char[] reSeq=new char[sqe.length];
//            for(int i=0;i<sqe.length;i++){
//                //reSeq[i]
//            }
//            for(char item:sqe){
//
//            }
//        }
//    }
//
//    public static String Transfer(String s){
//        char[] chars = s.toCharArray();
//        double num = 0;
//        int count = 0;
//        for(int i=chars.length-1;i>-1;i--){
//
//            num += (chars[i]-'a')*Math.pow(26,count++);
//
//        }
//        return (int)num+"";
//    }