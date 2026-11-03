using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Text;

namespace Hadhoad_Course__13__All_Projects__C__
{
    public class clsDbLinkedList<T>
    {
        public Node? Head { get; set; }
        public Node? Tail { get; set; }
        private int _size { get; set; }
        public class Node
        {
            public T Data { get; set; }
            public Node? Next { get; set; }
            public Node? Prev { get; set; }

            public Node(T data)
            {
                Data = data;
            }
        }

        public void Clear()
        {
            if(IsEmpty())
                return;

            Head!.Next = null;
            Tail!.Prev = null;

            Head = Tail = null;
            _size = 0;

        }

        public void Reverse()
        {
            if (IsEmpty() || Head == Tail)
                return;

            Node? current = Head;
            Node? temp = null;

            while (current != null)
            {
                temp = current.Next;

                current.Next = current.Prev;
                current.Prev = temp;

                current = temp;
            }

            temp = Head;
            Head = Tail;
            Tail = temp;
        }

        public void InsertAtBeginning(T value)
        {
            Node NewNode = new Node(value);

            if(IsEmpty())
            {
                Head = NewNode;
                Tail = NewNode;
                _size++;
                return;
            }
            
            Head!.Prev = NewNode;
            NewNode.Next = Head;
            Head = NewNode;
            _size++;

        }

        public Node? Find(T data)
        {
            if(IsEmpty())
                return null;

            Node? CurrentNode = Head;

            while (CurrentNode != null)
            {
                if(Comparer<T>.Equals(CurrentNode.Data, data))
                    return CurrentNode;
                CurrentNode = CurrentNode.Next;
            }
            return null;
        }

        public bool IsEmpty()
        {
            return _size == 0;
        }

        public void PrintList()
        {
            if (IsEmpty())
                return;

            Node? CurrentNode = Head;

            while (CurrentNode != null)
            {
                Console.Write(CurrentNode.Data + " ");

                CurrentNode = CurrentNode.Next;
            }
        }

        public void InsertAfterByNodeData(T searchedNodeData, T dataOfNewNode)
        {
            Node? SearchedNode = Find(searchedNodeData);

            if(SearchedNode == null)
                return;

            Node NewNode = new Node(dataOfNewNode);

            NewNode.Prev = SearchedNode;
            NewNode.Next = SearchedNode.Next;

            if(SearchedNode.Next != null)
                SearchedNode.Next.Prev = NewNode;

            SearchedNode.Next = NewNode;
            _size++;
        }

        public void InsertAtEnd (T newNodeData)
        {
            Node? NewNode;
            NewNode = new Node(newNodeData);


            if(IsEmpty())
            {
                Head = NewNode;
                Tail = NewNode;
                _size++;
                return;
            }


            Tail!.Next = NewNode;
            NewNode.Prev = Tail;
            Tail = NewNode;
            _size++;
        }

        public void DeleteNode (T deletedNodeData)
        {
            Node? SearchedNode = Find(deletedNodeData);

            if (SearchedNode == null)
                return;

            _size--;

            if (SearchedNode == Head)
            { 
                if(Head.Next != null)
                {
                    Head.Next.Prev = null;
                    Head = Head.Next;
                }
                else
                {
                    Head = null;
                    Tail = null;
                }
                return;
            }

            if (SearchedNode.Prev != null)
                SearchedNode.Prev.Next = SearchedNode.Next;

            if(SearchedNode.Next != null)
                SearchedNode.Next.Prev = SearchedNode.Prev;

            SearchedNode.Next = null;
            SearchedNode.Prev = null;
        }

        public void DeleteFirstNode()
        {
            if (IsEmpty())
                return;

            if(Head!.Next != null)
            {
                Head = Head.Next;
                Head.Prev = null;
            }
            else
            {
                Head = null;
                Tail = null;
            }
            _size--;
        }

        public void DeleteLastNode()
        {
            if (IsEmpty())
                return;

            _size--;
            if (Head == Tail)
            {
                Head = null;
                Tail = null;

                return;
            }

            var nodeToDelete = Tail;
            Tail = Tail!.Prev;       
            Tail!.Next = null;      

            nodeToDelete!.Prev = null;
        }

        public int Size()
        {
            return _size;
        }

        public Node? GetNode(int index)
        {
            if (IsEmpty())
                return null;

            if (index > Size() - 1 || index < 0)
                throw new IndexOutOfRangeException();

            Node? Current = Head;

            while(index >= 0 && Current != null)
            {
                if (index == 0)
                    return Current;

                Current = Current.Next;
                index--;
            }

            return null;
        }

        public int GetIndex(T targetNodeData)
        {
            Node? Current = Head;
            int TargetIndex = 0;

            while (Current != null)
            {
                if(Comparer<T>.Equals(targetNodeData, Current.Data))
                    return TargetIndex;

                Current = Current.Next;

                TargetIndex++;
            }

            return -1;
        }

        public T? GetItem(int index)
        {
            if (IsEmpty())
                return default(T);

            if (index > Size() - 1 || index < 0)
                throw new IndexOutOfRangeException();

            Node? TargetNode = GetNode(index);

            if (TargetNode != null)
                return TargetNode.Data;

            return default(T);
        }

        public bool UpdateBy(int index, T newValue)
        {
            if (IsEmpty())
                return false;

            if (index > (Size() - 1) || index < 0)
                throw new IndexOutOfRangeException();

            Node? TargetNode = GetNode(index);

            if (TargetNode != null)
            { 
                TargetNode.Data = newValue;
                return true;
            }

            return false;
        }

        public void InsertAfterByIndex(int index, T newNodeData)
        {
            if (IsEmpty())
                return;

            if (index >= Size() || index < 0)
                throw new IndexOutOfRangeException();

            Node? TargetNode = GetNode(index);

            if (TargetNode == null)
                return;

            Node NewNode = new Node(newNodeData);

            NewNode.Next = TargetNode.Next;
            NewNode.Prev = TargetNode;
            TargetNode.Next = NewNode;
        }

    }
}
