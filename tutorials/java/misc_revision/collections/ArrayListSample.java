import java.util.ArrayList;

public class ArrayListSample {
    public static void main(String[] args)
    {
        ArrayList<Integer> list = new ArrayList<>();

        list.add(1);
        list.add(3);
        list.add(5);
        list.add(7);
        printList(list);

        list.remove(1);
        list.remove(2);
        printList(list);
    }

    public static void printList(ArrayList<Integer> list)
    {
        for (int i : list)
        {
            System.out.println(i);
        }
    }
}
