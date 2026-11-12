using System;
using System.Windows.Forms;

namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    public partial class frmChangePoolTableSettings : Form
    {
        ctrlPoolTable _poolTable;
        TextBox _tboxPlayerName;

        public frmChangePoolTableSettings(ctrlPoolTable poolTable, 
            TextBox txtboxPlayerName)
        {
            InitializeComponent();

            tboxTableName.Text = "Table " + poolTable.TableNumber;
            tboxHourlyRate.Text = poolTable.HourlyRate.ToString();
            tboxPlayerName.Text = poolTable.PlayerName;

            _poolTable = poolTable;
            _tboxPlayerName = txtboxPlayerName;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            _poolTable.HourlyRate = decimal.Parse(tboxHourlyRate.Text);
            _poolTable.PlayerName = tboxPlayerName.Text;
            _tboxPlayerName.Text = tboxPlayerName.Text;

            this.Close();
        }

        private void tboxHourlyRate_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (clsUtility.IsValidDecimalKeyPress(e.KeyChar, tboxHourlyRate.Text))
                return;

            e.Handled = true;
        }
    }
}
