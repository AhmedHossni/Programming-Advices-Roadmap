
namespace Hadhoad_Course__13__All_Projects__C__
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Test_LinkedList();

            //Test_Queue();

            //Test_clsStringWithUndoAndRedo();

            Test_QueueLineClass();


            Console.ReadKey();

        }


        // Project (1)
        static void Test_LinkedList()
        {
            clsDbLinkedList<int> MyLinkedList = new clsDbLinkedList<int>();

            MyLinkedList.InsertAtEnd(1);
            MyLinkedList.InsertAtEnd(2);
            MyLinkedList.InsertAtEnd(3);
            MyLinkedList.InsertAtEnd(4);

            MyLinkedList.InsertAfterByIndex(3, 500);

            MyLinkedList.PrintList();

            MyLinkedList.Reverse();
            Console.WriteLine();

            MyLinkedList.PrintList();

            clsDbLinkedList<int>.Node? TargetNode = MyLinkedList.GetNode(3);
            Console.WriteLine($"\nTarget Node value is : {TargetNode?.Data}");

            int TargetIndex = MyLinkedList.GetIndex(1);
            Console.WriteLine($"\nTarget index is : {TargetIndex}");

            int TargetData = MyLinkedList.GetItem(1);
            Console.WriteLine($"\nTarget item data is : {TargetData}");


            MyLinkedList.UpdateBy(2, 500);

            MyLinkedList.PrintList();

            Console.WriteLine("\nCount is : " + MyLinkedList.Size());  
        }

        // Project (2)
        static void Test_Queue()
        {
            clsQueue<int> queue = new clsQueue<int>();

            queue.Push(1);
            queue.Push(2);
            queue.Push(3);
            queue.Push(4);

            //queue.Reverse();

            queue.InsertAfterFront(500);
            queue.InsertAfterBack(500);
            //queue.Clear();


            queue.UpdateItem(5, 1000);
            queue.Print();
            //Console.WriteLine(queue.Pop());
            //queue.Print();
            //Console.WriteLine(queue);


            //Console.WriteLine(queue.Front());
            //Console.WriteLine(queue.Back());
        }

        // Project (7)
        public static void Test_clsStringWithUndoAndRedo()
        {
            Console.WriteLine("\n\n\t\t\t\t\t\t Undo/Redo Project\n\n");

            clsStringWithUndoAndRedo S1 = new clsStringWithUndoAndRedo();

            Console.WriteLine("\nS1  = " + S1.Value + "\n");

            S1.Value = "Mohammed";

            Console.WriteLine("S1  = " + S1.Value + "\n");

            S1.Value = "Mohammed2";

            Console.WriteLine("S1  = " + S1.Value + "\n");

            S1.Value = "Mohammed3";

            Console.WriteLine("S1  = " + S1.Value + "\n");

            Console.WriteLine("\n\nUndo: ");

            Console.WriteLine("\n__________\n");

            S1.Undo();
            Console.WriteLine("\nS1  after undo = " + S1.Value + "\n");

            S1.Undo();
            Console.WriteLine("S1  after undo = " + S1.Value + "\n");

            S1.Undo();
            Console.WriteLine("S1  after undo = " + S1.Value + "\n");

            Console.WriteLine("\n\nRedo: ");

            Console.WriteLine("\n__________\n");

            S1.Redo();

            Console.WriteLine("\nS1  after Redo = " + S1.Value + "\n");

            S1.Redo();

            Console.WriteLine("S1  after Redo = " + S1.Value + "\n");

            S1.Redo();

            Console.WriteLine("S1  after Redo = " + S1.Value + "\n");

            Console.WriteLine("\nPress any key to continue...");

            Console.ReadKey();
        }
        
        // Project (8)
        public static void Test_QueueLineClass()
        {
            clsQueueLine queueLine = new clsQueueLine("A0",10);

            queueLine.IssueTicket();
            queueLine.IssueTicket();
            queueLine.IssueTicket();
            queueLine.IssueTicket();
            queueLine.IssueTicket();

            Console.WriteLine("Queue Line Info: ");
            queueLine.PrintInfo();

            Console.WriteLine("\nQueue Line RTL: ");
            queueLine.PrintTicketsLineRTL();

            Console.WriteLine("\nQueue Line LTR: ");
            queueLine.PrintTicketsLineLTR();

            queueLine.PrintAllTickets();

            queueLine.ServeNextClient();
            queueLine.PrintInfo();
            queueLine.PrintAllTickets();

        }

    }
}
