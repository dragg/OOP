using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_CSharp
{
    public class Container
    {
        public int value { get; set; }
        public Container next { get; set; }

        public Container(int val, Container nxt)
        {
            value = val;
            next = nxt;
        }
    }
}
