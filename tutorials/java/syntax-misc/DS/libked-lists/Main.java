// linked lists

import java.util.LinkedList;

public class Main{
    public static void main(String[] args)
    {
        LinkedList<Integer> nums = new LinkedList<Integer>();

        nums.add(1);
        nums.add(2);
        nums.add(3);

        System.out.println("Nums: " + nums);

        nums.addFirst(0);
        System.out.println("Nums: " + nums);

        nums.addLast(100);
        System.out.println("Nums: " + nums);
    }
}

