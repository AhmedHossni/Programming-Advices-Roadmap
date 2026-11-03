using System;
using System.Collections.Generic;
using System.Text;

namespace Hadhoad_Course__13__All_Projects__C__
{
    public class clsQueue<T>
    {
        // Using Composition
        private List<T> values { set; get; }

        public int Length => values.Count;

        public clsQueue()
        {
            values = new List<T>();
        }

        public void Push(T item)
        {
            values.Add(item);
        }

        public bool IsEmpty()
        {
            return values.Count == 0;
        }

        public T? Pop()
        {
            if (IsEmpty())
                throw new InvalidOperationException();

            int lastIndex = values.Count - 1;

            T LastItem = values[lastIndex];

            values.RemoveAt(lastIndex);

            return LastItem;
        }

        public T? Front()
        {
            if (IsEmpty())
                return default(T);

            return values[0];
        }

        public T? Back()
        {
            if (IsEmpty())
                return default(T);

            return values[values.Count - 1];
        }

        public override string ToString()
        {
            if (IsEmpty())
                return "";

            StringBuilder ToStringValue = new StringBuilder();

            for (int i = 0; i < values.Count; i++)
            {
                ToStringValue.AppendLine(values[i]!.ToString());
            }

            return ToStringValue.ToString();
        }

        public void Print()
        {
            for (int i = 0; i < values.Count; i++)
            {
                Console.WriteLine(values[i]);
            }
        }

        public void UpdateItem(int index, T newValue)
        {
            values[index] = newValue;
        }

        public T? GetItem(int index)
        {
            if (IsEmpty())
                throw new InvalidOperationException();

            if(index < 0 || index >= Length)
                throw new ArgumentOutOfRangeException();

            return values[index];

        }

        public void Reverse()
        {
            values.Reverse();
        }

        public void InsertAfter(T valueToSearch, T newValue)
        {
            int index = values.IndexOf(valueToSearch);
            values.Insert(index + 1, newValue);
        }

        public void InsertAfterFront(T newValue)
        {
            values.Insert(0, newValue);
        }

        public void InsertAfterBack(T newValue)
        {
            Push(newValue);
        }

        public void Clear()
        {
            values.Clear();
        }
    }
}