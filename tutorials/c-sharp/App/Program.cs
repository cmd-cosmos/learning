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
            Console.WriteLine("3. Text Analyzer");
            Console.WriteLine("4. Exit");
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
                    TextAnalyzer();
                    break;
                case 4:
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

    static void TextAnalyzer()
    {
        Console.Write("Enter Text: ");
#pragma warning disable CS8600 // Converting null literal or possible null value to non-nullable type.
        string inp;

        while (true)
        {
            inp = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(inp))
            {
                break;
            }
            Console.WriteLine("Text cannot be empty.");
        }
#pragma warning restore CS8600 // Converting null literal or possible null value to non-nullable type.
        int letters = 0;
        int digits  = 0;
        int spaces  = 0;

#pragma warning disable CS8602 // Dereference of a possibly null reference.
        foreach (char c in inp)
        {
            if (char.IsLetter(c))
            {
                letters++;
            }
            else if (char.IsDigit(c))
            {
                digits++;
            }
            else if (char.IsWhiteSpace(c))
            {
                spaces++;
            }
        }
        Console.WriteLine("\nResult:");
        Console.WriteLine("Total Chars: " + inp.Length);
        Console.WriteLine("Letters :" + letters);
        Console.WriteLine("Digits  :" + digits);
        Console.WriteLine("Spaces  :" + spaces);
#pragma warning restore CS8602 // Dereference of a possibly null reference.

    } 
}
