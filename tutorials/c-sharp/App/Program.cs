using System;

class Program
{
    static void Main()
    {
        Greet();
        SumNumbers();
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
