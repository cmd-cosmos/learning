// basic CLI based calculator
import java.util.Scanner;

public class Calculator
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("======== CALCULATOR ========");

        String[] operations_list = {"+", "-", "*", "/", "%", "^"};
        for (int i = 0; i < operations_list.length; i++)
        {
            System.out.println("OP ID: " + i + " --> " + operations_list[i]);
        }
        System.out.print("Choose Operation ID: ");
        int op_id = scanner.nextInt();

    }
}