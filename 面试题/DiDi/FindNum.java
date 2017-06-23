package DiDi;

import java.util.*;

/**
 * designed by Steve Ke on 2017/5/7.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/5/7
 */
class MapKeyComparator implements Comparator<String> {
    public int compare(String str1, String str2) {
        return str1.compareTo(str2);
    }
}
public class FindNum {

    public static void main(String []args){
            Scanner scanner=new Scanner(System.in);
            String str=scanner.nextLine();
            String numStr=scanner.nextLine();
            str=str.toLowerCase();
            StringBuilder sb=new StringBuilder();
            Map<String,String> alphabetToNum=getNumAlphabet();
            for(int i=0;i<str.length();i++){
                if(alphabetToNum.get(str.charAt(i)+"")!=null){
                    sb.append(alphabetToNum.get(str.charAt(i)+""));
                }else {
                    sb.append(" ");
                }
            }
            String target[]=sb.toString().split(" ");
            String sec[]=str.split(" ");
            Map<String ,String > rest=new HashMap<>();
            for(int i=0;i<sec.length;i++){
                rest.put(target[i],sec[i]);
            }
            Map<String, String> map = new TreeMap<String, String>();

            for(String word:target){
                int lcs=compute(numStr.toCharArray(),word.toCharArray());
                if(map.get(lcs+"")!=null)continue;
                map.put(lcs+"",word);
            }
            TreeMap<String, String> resultMap = (TreeMap<String, String>) sortMapByKey(map);
            System.out.println(rest.get(resultMap.get(resultMap.lastKey())));
    }

    public static int compute(char[] str1, char[] str2) {
        int size1 = str1.length;
        int size2 = str2.length;
        if (size1 == 0 || size2 == 0) return 0;

        // the start position of substring in original string
        int start1 = -1;
        int start2 = -1;
        // the longest length of common substring
        int longest = 0;

        // record how many comparisons the solution did;
        // it can be used to know which algorithm is better
        int comparisons = 0;

        for (int i = 0; i < size1; ++i) {
            int m = i;
            int n = 0;
            int length = 0;
            while (m < size1 && n < size2) {
                ++comparisons;
                if (str1[m] != str2[n]) {
                    length = 0;
                } else {
                    ++length;
                    if (longest < length) {
                        longest = length;
                        start1 = m - longest + 1;
                        start2 = n - longest + 1;
                    }
                }

                ++m;
                ++n;
            }
        }

        // shift string2 to find the longest common substring
        for (int j = 1; j < size2; ++j) {
            int m = 0;
            int n = j;
            int length = 0;
            while (m < size1 && n < size2) {
                ++comparisons;
                if (str1[m] != str2[n]) {
                    length = 0;
                } else {
                    ++length;
                    if (longest < length) {
                        longest = length;
                        start1 = m - longest + 1;
                        start2 = n - longest + 1;
                    }
                }

                ++m;
                ++n;
            }
        }
        return longest;
    }
    public static Map<String, String> sortMapByKey(Map<String, String> map) {
        if (map == null || map.isEmpty()) {
            return null;
        }
        Map<String, String> sortMap = new TreeMap<String, String>(new MapKeyComparator());
        sortMap.putAll(map);
        return sortMap;
    }

    public static int getMaxSubstringLen(String x, String y) {
        int xLen = x.length() + 1;
        int yLen = y.length() + 1;

        int rLen = xLen > yLen ? xLen : yLen;
        int cLen = xLen < yLen ? xLen : yLen;
        int[][] c = new int[rLen][cLen];
        for (int i = 1; i < rLen; i++) {
            for (int j = 1; j < cLen; j++) {
                if (x.charAt(i - 1) == y.charAt(j - 1)) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }
        return c[xLen - 1][yLen - 1];
    }

    public static Map<String,String> getNumAlphabet(){
        Map<String,String> res=new HashMap<>();
        res.put("a","2");
        res.put("b","2");
        res.put("c","2");res.put("d","3");
        res.put("e","3");
        res.put("f","3");res.put("g","4");
        res.put("h","4");
        res.put("i","4");res.put("j","5");
        res.put("k","5");
        res.put("l","5");res.put("m","6");
        res.put("n","6");
        res.put("o","6");res.put("p","7");
        res.put("q","7");
        res.put("r","7");res.put("s","7");
        res.put("t","8");
        res.put("u","8");res.put("v","8");
        res.put("w","9");
        res.put("x","9");
        res.put("y","9");
        res.put("z","9");
        return res;
    }



}
