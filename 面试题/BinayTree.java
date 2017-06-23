import java.util.LinkedList;
import java.util.Queue;

/**
 * designed by Steve Ke on 2017/3/23.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/3/23
 */
public class  BinayTree {

    
    static class BiNode{
        int key;
        BiNode left,right;
        public BiNode(int key){
            this.key=key;
            left=null;right=null;
        }
    }
    public static BiNode createBiTree(int []data){
        BiNode root=null;
        BiNode []queen=new BiNode[data.length];

        for(int i=0;i<data.length;i++){
            queen[i]=new BiNode(data[i]);
        }
        for(int i=data.length/2-1;i>-1;i--){
           if(2*i+1<data.length){
               queen[i].left=queen[2*i+1];
           }
           if(2*i+2<data.length){
               queen[i].right=queen[2*i+2];
           }
        }
        root=queen[0];
        return root;
    }
    public static void preOrderBiTree(BiNode root){
        if(root!=null){
            System.out.println(root.key);
            preOrderBiTree(root.left);
            preOrderBiTree(root.right);
        }
    }
    public static void scaleOreder(BiNode root){
        Queue<BiNode> orderQueue=new LinkedList<BiNode>();
        orderQueue.offer(root);
        BiNode top=null;
        while (!orderQueue.isEmpty()){
                top=orderQueue.poll();
                if(top!=null) {
                    if (top.left != null) {
                        orderQueue.offer(top.left);
                    }
                    if (top.right != null) {
                        orderQueue.offer(top.right);
                    }
                    System.out.println(top.key);
                }
        }
    }


    public static void main(String []args){
        int datas[]={1,2,3,4,5,6,7,8};
        BiNode root=createBiTree(datas);
        //preOrderBiTree(root);
        scaleOreder(root);
    }




}
