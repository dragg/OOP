using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5_CSharp
{
    public class C_List
    {
        protected Container head { get; set; }
        protected Container tail { get; set; }

        public C_List()
        {
            head = null;
            tail = null;
        }

        public virtual void push(int value) { }
        public virtual int? pop() { return null; }
        public virtual bool empty() { return true; }
    }
}
