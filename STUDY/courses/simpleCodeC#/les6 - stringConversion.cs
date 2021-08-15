using System;
using System.Globalization;

namespace Lessons
{
    class Program
    {
        static void Main(string[] args)
		{
			Console.Title = "String conversion";

			string str = "5";
			string str2 = "2";

			Console.WriteLine(str + str2);

			int result = SimpleAdd();
			Console.WriteLine("Sum of numbers = " + result);

			string doubleNumber = "1.9";
			double doubleResult = ifUseDotConvert(doubleNumber) + 1.4;
			Console.WriteLine(doubleResult);
		}

		static int SimpleAdd()
		{
			string str;

			Console.WriteLine("Input first number: ");
			str = Console.ReadLine();
			int a = Convert.ToInt32(str);

			Console.WriteLine("Input second number: ");
			str = Console.ReadLine();
			int b = Convert.ToInt32(str);

			return a + b;
		}

		static double ifUseDotConvert(string doubleNumber)
		{
			double result;
			NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
			{
				NumberDecimalSeparator = ".",
			};

			return result = Convert.ToDouble(doubleNumber, numberFormatInfo);
		}
	}
}
