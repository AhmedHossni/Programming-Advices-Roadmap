using System;
using System.ComponentModel.DataAnnotations;
using System.Windows.Forms;

namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    public partial class ctrlPoolTable : UserControl
    {
        private int _hours = 0;
        private int _minutes = 0;
        private int _seconds = 0;

        private short _tableNumber = 1;

        public string PlayerName 
        {
            get
            {
                return tboxPlayerName.Text;
            }
            set
            {
                tboxPlayerName.Text = value;
            }
        }

        public short TableNumber 
        {
            get
            {
                return _tableNumber;
            }
            set
            {
                groupBox1.Text = "Table " + value;
                _tableNumber = value;
            }
        }

        decimal _hourlyRate;
        public decimal HourlyRate 
        {
            get
            {
                return _hourlyRate;
            }
            set
            {
                lblHourRate.Text = value + "$";
                _hourlyRate = value;
            }
        }

        private bool _isTimerStarted = false;

        public bool IsTimerStarted { get { return _isTimerStarted; }  }

        public ctrlPoolTable()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            if (_isTimerStarted)
                return;

            tboxPlayerName.Enabled = false;

            timer1.Interval = 1000;
            timer1.Start();
            _isTimerStarted = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Interval = 1000;

            _seconds++;

            if (_seconds == 60)
            {
                _minutes++;
                _seconds = 0;
            }

            if (_minutes == 60)
            {
                _hours++;
                _minutes = 0;
            }

            lblTimer.Text 
                = $"{_hours.ToString("D2")}:{_minutes.ToString("D2")}:{_seconds.ToString("D2")}";
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            if (!_isTimerStarted)
                return;

            timer1.Stop();

            decimal totalHours = _hours + ((decimal)_minutes / 60) + ((decimal)_seconds / 3600);
            decimal totalFees = totalHours * HourlyRate;

            MessageBox.Show($"Time Consumed: {lblTimer.Text}\n" +
                $"Total Seconds: {(_seconds + (_minutes * 60) + (_hours * 3600))}\n" +
                $"Hourly Rate: {HourlyRate:F2}\n" +
                $"Total Fees: {totalFees:F2}");

            ResetValues();
        }

        private void ResetValues()
        {
            _hours = 0;
            _minutes = 0;
            _seconds = 0;

            _isTimerStarted = false;
            tboxPlayerName.Enabled = true;

            lblTimer.Text = "00:00:00";
        }

        private void cmsChangeTableSettings_Opening(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if(_isTimerStarted)
                changeTableHourRateToolStripMenuItem.Enabled = false;
            else
                changeTableHourRateToolStripMenuItem.Enabled = true;
        }

        private void changeTableHourRateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new frmChangePoolTableSettings(this, tboxPlayerName).ShowDialog();
        }
    }
}
