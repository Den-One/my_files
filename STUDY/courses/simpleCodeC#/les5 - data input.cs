using System;

namespace Lessons
{
    class Program
    {
        static void Main(string[] args)
		{
			Console.Title = "Inputing data into the console С#";

			string data = Console.ReadLine();
			Console.WriteLine("Hello, " + data + "!");
		}
	}
}
