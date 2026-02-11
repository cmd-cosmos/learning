// basic CLI based calculator
import java.util.Scanner;

public class Calculator
{
    @SuppressWarnings("unused")
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int op_id = 0;
        System.out.println("======== CALCULATOR ========");

        String[] operations_list = {"+", "-", "*", "/", "%", "^"};
        for (int i = 0; i < operations_list.length; i++)
        {
            System.out.println("OP ID: " + i + " --> " + operations_list[i]);
        }
        try
        {
            System.out.print("Choose Operation ID: ");
            op_id = scanner.nextInt();
            System.out.println("\nSelected OP ID | " + op_id + " | " + operations_list[op_id] + '\n');
        }
        catch (IndexOutOfBoundsException e)
        {
            System.err.println("IndexOutOfBoundsException: " + e.getMessage());
        }

        System.out.print("Enter num 1: ");
        double num1 = scanner.nextInt();
        System.out.print("Enter num 2: ");
        double num2 = scanner.nextInt();

        double result;
        switch (operations_list[op_id]) {
            case "+":
                result = num1 + num2;
                System.out.println("\nResult: " + result);
                break;
            case "-":
                result = num1 - num2;
                System.out.println("\nResult: " + result);
                break;
            case "*":
                result = num1 * num2;
                System.out.println("\nResult: " + result);
                break;
            case "/":
                result = num1 / num2;
                System.out.println("\nResult: " + result);
                break;
            case "%":
                result = num1 % num2;
                System.out.println("\nResult: " + result);
                break;
            case "^":
                result = Math.pow(num1, num2);
                System.out.println("\nResult: " + result);
                break;
            default:
                System.out.println("\nError");
                break;
        }
        
        scanner.close();
    }
}