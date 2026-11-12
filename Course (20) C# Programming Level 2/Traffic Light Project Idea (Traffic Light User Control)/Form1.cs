using System.Threading.Tasks;
using System.Windows.Forms;

namespace Traffic_Light_Project_Idea__Traffic_Light_User_Control_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();     
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            ctrlTrafficLight1.Start();
            ctrlTrafficLight2.Start();

            int timeToStop = 20 * 1000;

            Task.Run(() => 
            {
                Task.Delay(timeToStop).Wait();
                ctrlTrafficLight1.Stop();
                ctrlTrafficLight2.Stop();
            });
        }
    }
}
