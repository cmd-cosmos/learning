// basic CLI based calculator
import java.util.Scanner;

public class Calculator
{
    @SuppressWarnings("unused")
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("======== CALCULATOR ========");

        String[] operations_list = {"+", "-", "*", "/", "%", "^"};
        for (int i = 0; i < operations_list.length; i++)
        {
            System.out.println("OP ID: " + i + " --> " + operations_list[i]);
        }
        try
        {
            System.out.print("Choose Operation ID: ");
            int op_id = scanner.nextInt();
            System.out.println("\nSelected OP ID | " + op_id + " | " + operations_list[op_id] + '\n');
        }
        catch (IndexOutOfBoundsException e)
        {
            System.err.println("IndexOutOfBoundsException: " + e.getMessage());
        }
        
        scanner.close();
    }
}