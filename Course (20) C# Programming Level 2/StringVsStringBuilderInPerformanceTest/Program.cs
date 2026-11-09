using System;
using System.Diagnostics;
using System.Text;

namespace StringVsStringBuilderInPerformanceTest
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int iterations = 200000;

            Stopwatch sw1 = new Stopwatch();
            sw1.Start();
            ConcatinationUsingStringBuilder(iterations);
            sw1.Stop();

            Stopwatch sw2 = new Stopwatch();
            sw2.Start();
            ConcatinationUsingString(iterations);
            sw2.Stop();

            Console.WriteLine
                ($"Time form concatination using string builder : {sw1.ElapsedMilliseconds} ms");
            Console.WriteLine
                ($"Time form concatination using string : {sw2.ElapsedMilliseconds} ms");

            Console.ReadKey();
        }

        private static void ConcatinationUsingStringBuilder(int iterations)
        {
            StringBuilder text = new StringBuilder("");

            for (int i = 0; i < iterations; i++)
                text.Append("a");
        }

        private static void ConcatinationUsingString(int iterations)
        {
            string text = "";

            for (int i = 0; i < iterations; i++)
                text += "a";
        }
    }
}
