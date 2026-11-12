using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    public partial class formMainApp : Form
    {
        public formMainApp()
        {
            InitializeComponent();
        }

        private void tboxHourlyRate_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (clsUtility.IsValidDecimalKeyPress(e.KeyChar, tboxHourlyRate.Text))
                return;

            e.Handled = true;
        }

        private void btnSave_Click(object sender, System.EventArgs e)
        {
            foreach (Control control in this.Controls)
            {
                if (control is ctrlPoolTable poolTable)
                {
                    if(!poolTable.IsTimerStarted)
                        poolTable.HourlyRate = decimal.Parse(tboxHourlyRate.Text);
                }
            }
        }
    }
}
