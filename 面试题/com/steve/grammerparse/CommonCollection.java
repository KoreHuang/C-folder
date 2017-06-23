package com.steve.grammerparse;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
public class CommonCollection {
    /**
     * 产生式集合
     */
    public static Map<String,PrincipleGenerator> generators=new HashMap<>();
    /**
     * 非终结符集合
     */
    public static List<String> nonterminals=new ArrayList<>();

    /**
     * 空符号
     */
    public static final String emptyWord="ε";

    /**
     * 判断某个字符是否为非终结符号
     * @param ch
     * @return
     */
    public static boolean isNonterminal(String ch){
        return generators.containsKey(ch);
    }
}
