package toutiao;

import java.util.*;

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
public class BtreeOperation {

    static class Btree{
        int key;
        Btree left;
        Btree right;
        public Btree(){}
        public Btree(int key) {
            this.key = key;
        }
    }

    /**
     * 二叉堆的构建
     * @param data
     * @return
     */
    public static Btree createBiTree(int []data){
        Btree root=null;
        Btree []queen=new Btree[data.length];

        for(int i=0;i<data.length;i++){
            queen[i]=new Btree(data[i]);
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


    /**
     * 求二叉树高度
     * @param root
     * @return
     */
    public static int getBtreeLevel(Btree root){
        if(root==null){
            return 0;
        }
        int left=0;
        int right=0;
        if(root.left!=null) left=getBtreeLevel(root.left);
        if(root.right!=null) right=getBtreeLevel(root.right);
        return left>right?left+1:right+1;
    }

    /**
     *  反转二叉树
     * @param root
     * @return
     */
    public static Btree reverseBtree(Btree root){
        if(root==null||(root.left==null&&root.right==null)){
            return root;
        }
        Btree tmp=root.left;
        root.left=root.right;
        root.right=tmp;

        if(root.left!=null){
            root.left=reverseBtree(root.left);
        }
        if(root.right!=null){
            root.right=reverseBtree(root.right);
        }
        return root;
    }

    /**
     * 层次遍历二叉树
     * @param root
     */
    public static void levelOrderBtree(Btree root){
        Queue<Btree> orderQueue=new LinkedList<Btree>();
        orderQueue.offer(root);
        while (!orderQueue.isEmpty()){
            Btree ele=orderQueue.poll();
            System.out.print(ele.key+" ");
            if(ele.left!=null)orderQueue.offer(ele.left);
            if(ele.right!=null)orderQueue.offer(ele.right);
        }
    }

    /**
     * 先序递归遍历
     * @param root
     */
    public static void preOrder(Btree root){
        if(root!=null){
            System.out.print(root.key+" ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    /**
     * 中序递归遍历
     * @param root
     */
    public static void midOrder(Btree root){
        if(root!=null){
            midOrder(root.left);
            System.out.print(root.key+" ");
            midOrder(root.right);
        }
    }

    /**
     * 后序递归遍历
     * @param root
     */
    public static void postOrder(Btree root){
        if(root!=null){
            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.key+" ");
        }
    }

    /**
     * 二叉树节点个数统计
     * @param root
     * @return
     */
    public static int getNodesNum(Btree root){
        if(root==null) return 0;
        int left=getNodesNum(root.left);
        int right=getNodesNum(root.right);
        return left+right+1;
    }
    /**
     * 二叉树中叶子节点个数统计
     */
    public static int getLeafNum(Btree root){
        if(root==null) return 0;
        if(root.left==null&&root.right==null) return 1;
        return  getLeafNum(root.left)+getLeafNum(root.right);
    }



    /**
     * 先序非递归遍历二叉树
     * @param root
     */
    public static void preOrderBitree(Btree root){
        Stack<Btree> stack=new Stack<Btree>();
        Btree p=root;
        while (p!=null||!stack.isEmpty()){
            while (p!=null){
                System.out.print(p.key+" ");
                stack.push(p);
                p=p.left;
            }
            p=stack.pop();
            if(p!=null) p=p.right;
        }
        if(p!=null) System.out.println(p.key);
    }

    /**
     * 中序非递归遍历二叉树
     * @param root
     */
    public static void midOrderBitree(Btree root){
        Stack<Btree> stack=new Stack<Btree>();
        Btree p=root;

        while (p!=null||!stack.isEmpty()){
            while (p!=null) {
                stack.push(p);
                p=p.left;
            }
            p=stack.pop();
            if(p!=null){
                System.out.print(p.key+" ");
                p=p.right;
            }
        }
    }

    /**
     * 后序非递归遍历二叉树
     * @param root
     */
    public static void postOrderBitree(Btree root){
        Stack<Btree> stack=new Stack<>();
        Btree p=root,q=null;
        while (p!=null||!stack.isEmpty()){
            while (p!=null){
                stack.push(p);
                p=p.left;
            }

            p=stack.peek();
            if(p.right==null||p.right==q){
                p=stack.pop();
                System.out.print(p.key+" ");
                q=p;
                p=null;
            }else {
                p=p.right;
            }

        }
    }


    /**
     * 根据二叉树 前序 中序 构建出二叉树（注意二叉树中无重复元素，若有重复元素则选用其他容器）
     * @param pre
     * @param midin
     * @return
     */
    public static Btree createBtree(int []pre,int[] midin){
        if(pre==null||pre.length==0) return null;

        Map<Integer,Integer> mid =new HashMap();
        for(int i=0;i<pre.length;i++){
            mid.put(midin[i],i);
        }

        boolean tag[]=new boolean[midin.length];
        int currentStep=0;
        Btree root =new Btree(pre[currentStep++]);

        Btree p=root;
        Stack<Btree> stack=new Stack<>();
        stack.push(p);
        tag[mid.get(p.key)]=true;
        while (currentStep<pre.length&&!stack.isEmpty()){
            while (mid.get(p.key)>0&&!tag[mid.get(p.key)-1]){
                p=p.left=new Btree(pre[currentStep++]);
                stack.push(p);
                tag[mid.get(p.key)]=true;
            }
            p=stack.peek();

            if(mid.get(p.key)+1<pre.length&&tag[mid.get(p.key)+1]){
                p=stack.pop();
            }else {
                p=p.right=new Btree(pre[currentStep++]);
                tag[mid.get(p.key)]=true;
                stack.push(p);
            }
        }

        return root;
    }

    /**
     * 二叉树丛根到叶子路径打印
     */
    public static void printLeafRoute(Btree root){
        Btree p=root,q=null;
        Stack<Btree> stack=new Stack<>();

        while (p!=null||!stack.isEmpty()){
            while (p!=null){
                stack.push(p);
                p=p.left;
            }
            p=stack.peek();
            if(p.left==null&&p.right==null){

                Object arr[]=stack.toArray();
                for(Object obj:arr){
                    System.out.print(((Btree)obj).key+" ");
                }
                System.out.println("\n**************");
            }
            if(p.right==null||p.right==q){
                stack.pop();
                q=p;
                p=null;
            }else p=p.right;
        }
    }

    /**
     *          原二叉树
     *
     *              0
     *          |       |
     *          |       |
     *          1       3
     *        |       |
     *        |       |
     *        2       4
     *                   |
     *                   |
     *                   5
     *
     *
     *
     * @param args
     */

    public static void main(String []args){
        Btree root=new Btree();
        root.key=0;
        Btree ele1=new Btree();
        ele1.key=1;
        Btree ele2=new Btree();
        ele2.key=2;
        Btree ele3=new Btree();
        ele3.key=3;
        Btree ele4=new Btree();
        ele4.key=4;
        Btree ele5=new Btree();
        ele5.key=5;
        root.left=ele1;
        ele1.left=ele2;
        root.right=ele3;
        ele3.left=ele4;
        ele4.right=ele5;
        System.out.println("level:"+getBtreeLevel(root));
        levelOrderBtree(root);
        System.out.println("\n***********");
        root=reverseBtree(root);
        levelOrderBtree(root);
        System.out.println("\n***********");
        preOrderBitree(root);
        System.out.println("\n***********");
        preOrder(root);
        System.out.println("\n***********");
        midOrder(root);
        System.out.println("\n***********");
        midOrderBitree(root);
        System.out.println("\n***********");
        postOrder(root);
        System.out.println("\n***********");
        postOrderBitree(root);
        System.out.println("\n***********");

        int pre[]={0,3,4,5,1,2};
        int mid[]={3,5,4,0,1,2};
        Btree newtree=createBtree(pre,mid);

        postOrderBitree(newtree);
        System.out.println("\n***********");

        System.out.println(getNodesNum(root));

        System.out.println(getLeafNum(root));
        System.out.println("\n***********");
        printLeafRoute(root);
    }

}
