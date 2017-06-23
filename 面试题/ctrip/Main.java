package ctrip;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/11.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/11
 */

public class Main{
    public static String getStringFromChar(char[][] chess){
        StringBuffer result=new StringBuffer();
        for(int i=0;i<chess.length;i++){
            for(int j=0;j<chess[i].length;j++){
                result.append(chess[i][j]);
            }
        }
        return result.toString();
    }

    public static String[] getNext(String src){
        char []seq=src.toCharArray();
        char chess[][]=new char[(int)Math.sqrt(src.length())][(int)Math.sqrt(src.length())];
        int k=0;
        for(int i=0;i<chess.length;i++){
            for(int j=0;j<chess[i].length;j++){
                chess[i][j]=src.charAt(k++);
            }
        }

        String next[]=null;
        char tmp=0;
        for(int i=0;i<chess.length;i++){
            for(int j=0;j<chess[i].length;j++){
                if(chess[i][j]=='0'){
                    if(i-1<0&&j-1<0){
                        next=new String[2];
                        char[][] tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i][j+1];
                        tmpChess[i][j+1]=tmp;
                        next[0]=getStringFromChar(tmpChess);
                        tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i+1][j];
                        tmpChess[i+1][j]=tmp;
                        next[1]=getStringFromChar(tmpChess);
                        return next;
                    }
                    if(i+1>chess.length&&j-1<0){
                        next=new String[2];
                        char[][] tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i-1][j];
                        tmpChess[i-1][j]=tmp;
                        next[0]=getStringFromChar(tmpChess);
                        tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i][j+1];
                        tmpChess[i][j+1]=tmp;
                        next[1]=getStringFromChar(tmpChess);
                        return next;
                    }
                    if(i+1>chess.length&&j+1<chess[i].length){
                        next=new String[2];
                        char[][] tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i-1][j];
                        tmpChess[i-1][j]=tmp;
                        next[0]=getStringFromChar(tmpChess);
                        tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i][j-1];
                        tmpChess[i][j-1]=tmp;
                        next[1]=getStringFromChar(tmpChess);
                        return next;
                    }
                    if(i-1<0&&j+1<chess[i].length){
                        next=new String[2];
                        char[][] tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i][j]=tmpChess[i][j-1];
                        tmpChess[i][j-1]=tmp;
                        next[0]=getStringFromChar(tmpChess);
                        tmpChess=chess.clone();
                        tmp=tmpChess[i][j];
                        tmpChess[i+1][j]=tmpChess[i][j];
                        tmpChess[i+1][j]=tmp;
                        next[1]=getStringFromChar(tmpChess);
                        return next;
                    }







                }
            }
        }

        return next;
    }

    /*请完成下面这个函数，实现题目要求的功能*/
    /*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
    /******************************开始写代码******************************/
    static int run(String numbers){
        int result=0;



        return result;
    }
    /******************************结束写代码******************************/

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String numbers = new String();
        for(int rows=3; rows>0; rows--){
            for(String n: scan.nextLine().split(" ")){
                numbers += n;
            }
        }

        int res = run(numbers);

        System.out.println(String.valueOf(res));
    }
}

