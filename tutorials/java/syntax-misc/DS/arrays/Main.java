// c style arrays in java
// fixed size and contiguous mem layout

/*
time complexity:
- access => O(1)
- search => O(n)
- insertion => O(n)
- deletion => O(n)

*/

public class Main{
    public static void main(String[] argv){
        System.out.println("C style arrays\n");

        int[] arr = new int[5]; // arr of 5 ints

        for (int i = 0; i < 5; i++)
        {
            arr[i] = i+10;
        }

        for (int j = 0; j < 5; j++)
        {
            System.out.println(arr[j]);
        }

        System.out.println(arr[2]); // 12
    }
}

