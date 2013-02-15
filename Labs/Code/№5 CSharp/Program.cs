using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack stack = new Stack();
            Queue queue = new Queue();
            for (int i = 0; i < 10; i++)
            {
                queue.push(i);
                stack.push(i);
            }

            Console.WriteLine("Work of the Stack:");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(stack.pop());
            }

            Console.WriteLine("Work of the Queue:");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(queue.pop());
            }
        }
    }
}
