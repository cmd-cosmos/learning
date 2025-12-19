using System;

class Program
{
    static void Main()
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine(new string(' ', 30) + "Program List" + new string(' ', 30));
            Console.WriteLine("1. Greet Me");
            Console.WriteLine("2. Add Nums");
            Console.WriteLine("3. Exit");
            Console.WriteLine(new string('*', 70));
            Console.Write("What program do you want to run: ");
            int mode = Convert.ToInt32(Console.ReadLine());

            switch (mode)
            {
                case 1:
                    Console.WriteLine(new string('*', 70));
                    Greet();
                    break;
                case 2:
                    Console.WriteLine(new string('*', 70));
                    SumNumbers();
                    break;
                case 3:
                    Console.WriteLine(new string('*', 70));
                    Console.WriteLine("Exiting program");
                    return;
                default:
                    Console.WriteLine("Invalid Input.");
                    break;       
            }
            Console.WriteLine("\nPress Enter...");
            Console.ReadLine();
        }
    }

    static void Greet()
    {
        Console.WriteLine(new string(' ',30) + "Greetings" + new string(' ',30));
        Console.WriteLine(new string('*',70));
    }

    static void SumNumbers()
    {
        Console.Write("Enter Num 1: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.Write("Enter Num 2: ");
        int b = Convert.ToInt32(Console.ReadLine());
        int sum = a + b;
        Console.WriteLine("Sum: " + sum);
    }
}
