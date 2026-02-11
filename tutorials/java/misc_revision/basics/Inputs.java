import java.util.Scanner;

public class Inputs{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Name: ");
        String name = scanner.next();

        System.out.print("Enter ID: ");
        String id = scanner.next();

        System.out.println("Added User | id: " + id + " name: " + name);

        scanner.close();
    }
}