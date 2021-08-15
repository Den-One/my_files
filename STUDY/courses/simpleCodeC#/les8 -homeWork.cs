using System;

namespace Lessons
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.Title = "Home Work - Lesson 8";

			showHomeWork1();
			Console.WriteLine();
			showHomeWork2();
		}

		static void showHomeWork1()
		{
			// program that calculates the arithmetic mean of two numbers
			Console.WriteLine("\tСреднее значение двух чисел\n");
			Console.WriteLine("Input number_1");
			string number_1 = Console.ReadLine();
			double number1 = Convert.ToDouble(number_1);

			Console.WriteLine("Input number_2");
			number_1 = Console.ReadLine();
			double number2 = Convert.ToDouble(number_1);

			double result = (number1 + number2) / 2;
			Console.WriteLine("Result: " + result);
		}

		static void showHomeWork2()
		{
			// Value of the sum and product of these numbers
			Console.WriteLine("\tSum and Product of 2 numbers\n");
			Console.WriteLine("Input number_1");
			string input = Console.ReadLine();
			double number1 = Convert.ToDouble(input);

			Console.WriteLine("Input number_2");
			input = Console.ReadLine();
			double number2 = Convert.ToDouble(input);

			Console.WriteLine("Input number_3");
			input = Console.ReadLine();
			double number3 = Convert.ToDouble(input);

			double sum = number1 + number2 + number3;
			Console.WriteLine("Sum: " + sum);

			double product = number1 * number2 * number3;
			Console.WriteLine("Product: " + product);
		}
	}
}
