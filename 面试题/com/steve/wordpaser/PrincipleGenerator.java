package com.steve.wordpaser;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * designed by Steve Ke on 2017/5/6.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/5/6
 */
public class PrincipleGenerator {   //产生式
    private String left;            //产生式左部
    private String [] rightSet;     //产生式右部集合

    /**
     * 产生式左部为非终结符
     * 产生式右部为字符串集合
     * @param expression
     */
    public PrincipleGenerator(String expression){
        String exp[]=expression.split("->");
        left=exp[0];
        rightSet=exp[1].split("\\|");
    }

    /**
     * 判断该产生式右部是否包含某个非终结符
     * @param ch
     * @return
     */
    public boolean contains(String ch){
        for(String exp:rightSet){
            if(exp.contains(ch)) return true;
        }
        return false;
    }

    /**
     * 获取产生式右部包含某个终结符或非终结符的推导
     * @param ch
     * @return
     */
    public List<String> getRightSetContains(String ch){
        List<String> result=new ArrayList<>();

        for(String exp:rightSet){
            if(exp.contains(ch)) result.add(exp);
        }

        return result;
    }

    /**
     * 打印产生式
     */
    public void printGenerator(){
        System.out.println(left + " ->");
        for (String t : rightSet) {
            System.out.print(" | " + t);
        }
        System.out.println();
        System.out.println("对应产生式的数目 :" + rightSet.length);
    }


    @Override
    public String toString() {
        return left + "->" + Arrays.toString(rightSet);
    }

    public void setLeft(String left) {
        this.left = left;
    }

    public void setRightSet(String[] rightSet) {
        this.rightSet = rightSet;
    }

    public String getLeft() {
        return left;
    }

    public String[] getRightSet() {
        return rightSet;
    }
}
