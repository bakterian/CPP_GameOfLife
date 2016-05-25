using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameOfLifeWpfBoard.Utils
{
    public class ComboboxItem
    {
        private string Text;
        private object Value;

        public override string ToString()
        {
            return Text;
        }

        public ComboboxItem(string text, int value)
        {
            Text = text;
            Value = value;
        }

        public object getValue()
        {
            return Value;
        }
    }
}
