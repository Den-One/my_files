using System;
using System.Globalization;

namespace Lessons
{
	class Program
	{
		static void Main(string[] args)
		{
			string str1 = "5";
			int a = int.Parse(str1);

			string str2 = "4.2";
			// str2 = "4,2ffb"; isException!
			// Pass and Convert don't work here

			NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
			{
				NumberDecimalSeparator = ".",
			};

			double b = double.Parse(str2);

			string str3 = "1gffgngfn";
			int c = betterIntConvert(str3);
			Console.WriteLine(c);

			string str4 = "1";
			int d = convertTryParse(str4);
			Console.WriteLine(d);
		}

		static int betterIntConvert(string str)
		{
			try
			{
				int a = Convert.ToInt32(str);
				// int a = int.Parse(str);
				Console.WriteLine("Convertion is succesful");
				return a;
			}
			catch (Exception)
			{
				Console.WriteLine("Error of convertion!");
				return 0;
			}
		}

		static int convertTryParse(string str)
		{
			int a;
			bool result = int.TryParse(str, out a);

			if (result)
			{
				Console.WriteLine("Operation run succcessfuly!");
			}
			else
			{
				Console.WriteLine("There is no success to convert");
			}

			return a;
		}
	}
}
