using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int nr1 = int.Parse(Console.ReadLine());
            int nr2 = int.Parse(Console.ReadLine());
            Console.WriteLine("Suma numerelor {0} si {1} este {2}", nr1, nr2, nr1 + nr2);
            Console.WriteLine("Suma=" + (nr1 + nr2));
            Console.ReadLine();
        }
    }
}
