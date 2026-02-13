import java.util.LinkedList;

public class LinkedListDemo {
    public static void main(String[] args)
    {
        LinkedList<Integer> ll  = new LinkedList<>();

        ll.add(10);
        ll.addFirst(90);
        ll.addLast(100);

        System.out.println(ll);

        ll.removeFirst();
        System.out.println(ll);
    }
}