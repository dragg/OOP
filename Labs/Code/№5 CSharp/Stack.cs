using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_CSharp
{
    public class Stack: C_List
    {
        public override void push(int value)
        {
            if (head != null)
            {
                Container tmp = new Container(value, tail);
                tail = tmp;
            }
            else 
            {
                head = new Container(value, null);
                tail = head;
            }
        }

        public override int? pop()
        {
            
            int? response = null;
            if (!empty())
            {
                response = tail.value;
                tail = tail.next;
            }
            return response;
        }

        public override bool empty()
        {
            return tail == null ? true : false;
        }
    }
}
