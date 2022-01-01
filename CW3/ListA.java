import java.util.Iterator;

/**
 * Created by stefstef on 20/5/2017.
 */
@FunctionalInterface
abstract interface DoSomething_Able<E>{
    public void doit(E elem);
}
public class ListA<E> implements Iterable<E> {
    class Node {
        public E Data = null;
        public String AM;
        private Node Next = null;
        private Node Prev = null;

        Node(E elem,String AM) {
            this.Data = elem;
            this.AM = AM;
        }
    }
    class ListsIterator implements Iterator<E>{
        public ListA.Node Head;
        ListsIterator(ListA.Node _Head){
            this.Head=_Head;
        }
        @Override
        public boolean hasNext(){
            return Head!=null;
        }
        public E next(){
            Node returnValue = this.Head;
            this.Head=this.Head.Next;
            return returnValue.Data;
        }
    }

    @Override
    public Iterator iterator(){
        return new ListsIterator(this.Head);
    }
    public Node Head = null;

    public void Add(E elem,String AM) {
        if (Head == null) {
            Head = new Node(elem,AM);
        }
        else{
            Node tmp=Head;
            Node Next,Prev,New;
            while(tmp.Next!=null && tmp.AM.compareTo(AM)<0){
                tmp=tmp.Next;
            }
            if(tmp.Next==null  && tmp.AM.compareTo(AM)<0){
                tmp.Next=new Node(elem,AM);
                tmp.Next.Prev=tmp;
            }
            else if(tmp.Prev==null){
                tmp.Prev=new Node(elem,AM);
                tmp.Prev.Next=tmp;
                Head=tmp.Prev;
            }
            else{
                Next=tmp;
                Prev=tmp.Prev;
                New=new Node(elem,AM);
                New.Next=tmp;
                New.Prev=tmp.Prev;
                tmp.Prev.Next=New;
                tmp.Prev=New;

            }
        }
    }
    public void Delete(String AM){
        Node tmp=Head;
        Node newHead;
        if(Head.AM.equals(AM)){
            newHead=Head.Next;
            newHead.Prev=null;
            Head=newHead;
            return;
        }
        while(tmp!=null){
            if(tmp.AM.equals(AM)){
                tmp.Prev.Next=tmp.Next;
                if(tmp.Next!=null){
                    tmp.Next.Prev=tmp.Prev;
                }
                tmp=null;
                return;
            }
            tmp=tmp.Next;
        }

    }
    public Node Search(String AM){
        Node tmp=Head;
        while(tmp!=null){
            if(tmp.AM.equals(AM)){
                return tmp;
            }
            tmp=tmp.Next;
        }
        return null;
    }
    public void Traverse(DoSomething_Able e){
        Node tmp=Head;
        while(tmp!=null){
            e.doit(tmp.Data);
            tmp=tmp.Next;
        }
    }

}
