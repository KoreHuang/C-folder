package com.steve.grammerparse;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

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
public class FirstSet {

    //所有非终结符的first集
    private Map<String,Set<String>> sets=new HashMap<>();

    public FirstSet(){
        for(String nonterminal:CommonCollection.generators.keySet()){
            sets.put(nonterminal,new HashSet<String>());
        }//为每个非终结符构建空集合，以备将满足候选集合的终结符加入其中
    }

    public void createFirstSet(){

        for(Map.Entry<String,Set<String>> currentIndex:sets.entrySet()){
            String nonterminal=currentIndex.getKey();
            Set<String> firstSet=currentIndex.getValue();
            PrincipleGenerator generator=CommonCollection.generators.get(nonterminal);


        }

    }


}
