using System;

namespace Lessons
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.Title = "Arithmetic operators";

			int a = 2;
			int b = 5;
			int result = a + b;
			Console.WriteLine(result);
			
			result = a - b;
			Console.WriteLine(result);
			
			result = a * b;
			Console.WriteLine(result);

			result = a % b;
			Console.WriteLine(result);

			double res = (double) a / b;
			Console.WriteLine(res);
		}
	}
}
