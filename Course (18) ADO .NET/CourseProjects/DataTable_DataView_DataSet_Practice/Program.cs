using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTable_DataView_DataSet_Practice
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Test Data View Method
            //DataViewPractice(EmployeesDataTable.DefaultView);

            // Test Data Set Method
            DataSetPractice();

            // Test Data Adapter Method (Not Work)
            DataAdapterPractice();

            Console.ReadKey();
        }

        private static void DataViewPractice()
        {
            DataView dataView = new DataView();

            // Normal Iteration
            for (int i = 0; i < dataView.Count; i++)
            {
                Console.WriteLine(" ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                    dataView[i]["ID"],
                    dataView[i]["Name"],
                    dataView[i]["Country"],
                    dataView[i]["Salary"],
                    dataView[i]["Date"]);

            }

            // Sorting By Name
            dataView.Sort = "Name Asc";
            Console.WriteLine("\n(Sorting) Employees Sorted By Names Ascending");
            for (int i = 0; i < dataView.Count; i++)
            {
                Console.WriteLine(" ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                    dataView[i]["ID"],
                    dataView[i]["Name"],
                    dataView[i]["Country"],
                    dataView[i]["Salary"],
                    dataView[i]["Date"]);

            }

            // Filtering
            dataView.RowFilter = "Country = 'Egypt'";
            Console.WriteLine("\n(Filter) Employees From Egypt");
            for (int i = 0; i < dataView.Count; i++)
            {
                Console.WriteLine(" ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                    dataView[i]["ID"],
                    dataView[i]["Name"],
                    dataView[i]["Country"],
                    dataView[i]["Salary"],
                    dataView[i]["Date"]);

            }
        }

        private static void DataSetPractice()
        {
            DataTable dtEmployees = new DataTable("Employees");

            dtEmployees.Columns.Add("ID", typeof(int));
            dtEmployees.Columns.Add("Name", typeof(string));
            dtEmployees.Columns.Add("Country", typeof(string));
            dtEmployees.Columns.Add("Salary", typeof(Double));
            dtEmployees.Columns.Add("Date", typeof(DateTime));
            dtEmployees.Columns.Add("DeptID", typeof(int));

            dtEmployees.Rows.Add(1, "Mohammed Abu-Hadhoud", "Jordan", 5000, DateTime.Now, 1);
            dtEmployees.Rows.Add(2, "Ali Maher", "KSA", 525.5, DateTime.Now, 2);
            dtEmployees.Rows.Add(3, "Lina Kamal", "Jordan", 730.5, DateTime.Now, 2);
            dtEmployees.Rows.Add(4, "Fadi JAmeel", "Egypt", 800, DateTime.Now, 3);
            dtEmployees.Rows.Add(5, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now, 1);

            DataTable dtDepartements = new DataTable("Departements");

            dtDepartements.Columns.Add("Id", typeof(int));
            dtDepartements.Columns.Add("Name", typeof(string));

            dtDepartements.Rows.Add(1, "IT");
            dtDepartements.Rows.Add(2, "Marketing");
            dtDepartements.Rows.Add(3, "Sales");

            DataSet dsDataSet = new DataSet();

            dsDataSet.Tables.Add(dtEmployees);
            dsDataSet.Tables.Add(dtDepartements);

            foreach (DataRow row in dsDataSet.Tables["Employees"].Rows)
            {
                Console.WriteLine(" ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t Dept ID: {5}",
                    row["ID"],
                    row["Name"],
                    row["Country"],
                    row["Salary"],
                    row["Date"],
                    row["DeptID"]);
            }

        }

        private static void DataAdapterPractice()
        {
            string connectionString =
                "";

            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                string query = "SELECT * FROM Employees";

                using (SqlCommand command = new SqlCommand(query, sqlConnection))
                {
                    SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);

                    DataSet dataSet = new DataSet();

                    sqlConnection.Open();

                    sqlDataAdapter.Fill(dataSet, "Employees");

                    /*
                     * After you using DataAdapter offline you can update data that you use in database by
                     */

                    sqlDataAdapter.Update(dataSet); 
                    // OR
                    sqlDataAdapter.Update(dataSet, "TableName");
                }            
            }
            
        }
    }
}
