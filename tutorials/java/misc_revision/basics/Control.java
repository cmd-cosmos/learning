public class Control{
    public static void main(String args[])
    {
        // control blocks

        int num = 7;
        if (num % 2 == 0)
        {
            System.out.println("even num");
        }
        else
        {
            System.out.println("odd num");
        }
        
        for (int i = 10; i >= 0; i--)
        {
            System.out.println("T minus: " + i);
        }
        while (num < 10)
        {
            System.out.println(num);
            num++;
        }
    }
}