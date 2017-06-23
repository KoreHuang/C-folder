package qunar;

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
public class BinaryTreeOut {
    static class BNode{
        BNode left,right;
        char key;
    }

//    void BFS(Graph& g, Vertex& s)
// {
//  queue<vertex> q;
//  for each vertex v in g
//  {
//   v.distance = INFINITY;
//  }
//  s.distance = 0;
//  
//  q.enqueue(s);
//  while (!q.Empty())
//  {
//   v = dequeue(q);
//   for each w adjenct to v
//   if (v.distance == INFINITY)
//   {
//    w.distance = v. distance + 1;       
//    w.path = v;
//    q.enqueue(w);
//   }    
//  }    
// }
// 对于外面的while循环，会执行|V|次，因为每个顶点入队出队一次，而里面的for循环会看到一共会执行|E|次，即变长， 所以该算法时间复杂度为O(|V|+|E|)。
//             打印最短路径：
//             void PrintPath(Graph& g, Vertex& target)
// {
//  if (target.path is a vertex)
//  {
//   PrintPath(g, target.path);
//  }
//  cout << target;
// }









    public static BNode createBTree(char []preOrder,char [] postOrder){
        BNode root=null;




        return root;
    }


    public static void main(){

    }

}
