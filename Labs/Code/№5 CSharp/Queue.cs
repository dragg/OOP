using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_CSharp
{
    public class Queue: C_List
    {
        public override void push(int value)
        {
            if (head != null)
            {
                tail.next = new Container(value, null);
                tail = tail.next;
            }
            else
            {
                tail = head = new Container(value, null);
            }
        }

        public override int? pop()
        {
            int? response = null;
            if (!empty())
            {
                response = head.value;
                head = head.next;
            }
            return response;
        }

        public override bool empty()
        {
            return head == null ? true : false;
        }
    }
}