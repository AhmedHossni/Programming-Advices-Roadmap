using System;
using System.Collections.Generic;
using System.Text;
using System.Timers;

namespace Hadhoad_Course__13__All_Projects__C__
{
    public class clsQueueLine
    {
        private class ClientTicket
        {
            public ClientTicket(string clientTicketName, int waitingClients, int timeToServe)
            {
                ClientTicketName = clientTicketName;
                WaitingClients = waitingClients;
                TimeToServe = timeToServe;
            }

            public string ClientTicketName { get; set; }
            public int WaitingClients { get; set; }
            public int TimeToServe { get; set; }
        }

        public clsQueueLine(string queueLineName, int averageTimeToServeACustomer)
        {
            Prefix = queueLineName;
            AverageTimeToServeAClient = averageTimeToServeACustomer;
            Tickets = new Queue<ClientTicket>();
        }

        private string Prefix { get; set; }
        private int AverageTimeToServeAClient { get; set; }
        Queue<ClientTicket> Tickets { get; set; }
        public int TotalTickets { get; private set; } = 0;
        public int ServedClients { get; private set; } = 0;
        public int WaitingClients => Tickets.Count;

        public void IssueTicket()
        {
            TotalTickets++;

            Tickets.Enqueue(new ClientTicket($"{Prefix}{TotalTickets}",
                WaitingClients,
                WaitingClients * AverageTimeToServeAClient));
        }

        public void PrintInfo()
        {
            Console.WriteLine("\t\t\t----------------------------");
            Console.WriteLine("\t\t\t          Queue Info        ");
            Console.WriteLine("\t\t\t----------------------------");
            Console.WriteLine($"\t\t\t  Prefix = {Prefix}  ");
            Console.WriteLine($"\t\t\t  Total Tickets = {TotalTickets}  ");
            Console.WriteLine($"\t\t\t  Served Clients = {ServedClients}  ");
            Console.WriteLine($"\t\t\t  Waiting Clients = {Tickets.Count}  ");
            Console.WriteLine("\t\t\t----------------------------");
        }

        public void PrintTicketsLineRTL()
        {
            Console.Write("Tickets : ");
            var ticketArray = Tickets.ToArray();

            for (int i = 0; i < ticketArray.Length; i++)
            {
                Console.Write(ticketArray[i].ClientTicketName);
                if (i != ticketArray.Length - 1)
                    Console.Write(" <-- ");
            }
            Console.WriteLine();
        }

        public void PrintTicketsLineLTR()
        {
            Console.Write("Tickets : ");
            var ticketArray = Tickets.ToArray();

            for (int i = ticketArray.Length - 1; i >= 0; i--)
            {
                Console.Write(ticketArray[i].ClientTicketName);
                if (i != 0)
                    Console.Write(" --> ");
            }
            Console.WriteLine();
        }

        private void PrintTicketInfo(ClientTicket clientTicket)
        {
            string DateTimeInfo =
                $"\t\t\t     {DateTime.Now.ToString("yyyy/MM/dd")} - {DateTime.Now.TimeOfDay.ToString(@"hh\:mm\:ss")} ";

            Console.WriteLine("\t\t\t----------------------------");
            Console.WriteLine($"\t\t\t           {clientTicket.ClientTicketName}    ");
            Console.WriteLine(DateTimeInfo);
            Console.WriteLine($"\t\t\t     Waiting Clients = {clientTicket.WaitingClients} ");
            Console.WriteLine($"\t\t\t     Serve Time In ");
            Console.WriteLine($"\t\t\t     {clientTicket.TimeToServe} Minutes. ");
            Console.WriteLine("\t\t\t----------------------------");

        }

        public void PrintAllTickets()
        {
            Console.WriteLine("\n\t\t\t     ---Tickets---          \n");
            foreach (var ticket in Tickets)
                PrintTicketInfo(ticket);
        }

        public void ServeNextClient()
        {
            if (Tickets.Count > 0)
            {
                Tickets.Dequeue();
                ServedClients++;
            }
        }
        public string WhoIsNext()
        {
            if (Tickets.Count > 0)
                return "No Client!!";

            return Tickets.Peek().ClientTicketName;

        }
    }
}
