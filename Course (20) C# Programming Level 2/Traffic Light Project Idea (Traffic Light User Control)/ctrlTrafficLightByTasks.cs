using System;
using System.Threading.Tasks;
using System.Windows.Forms;
using Traffic_Light_Project_Idea__Traffic_Light_User_Control_.Properties;

namespace Traffic_Light_Project_Idea__Traffic_Light_User_Control_
{
    public partial class ctrlTrafficLightByTasks : UserControl
    {
        public enum TrafficLightColors { Red,  Green, Orange }

        private TrafficLightColors _currentLight = TrafficLightColors.Red;

        public TrafficLightColors CurrentLight
        {
            set 
            { 
                _currentLight = value;
                SetPicture(value);
            } 
            get { return _currentLight; } 
        }

        public short RedTime { set; get; } = 5;
        public short OrangeTime { set; get; } = 3;
        public short GreenTime { set; get; } = 5;

        public event Action OnColorIsSetToRed;
        public event Action OnColorIsSetToOrange;
        public event Action OnColorIsSetToGreen;

        private bool _isStarted = false;
        private bool _start = false;

        private void SetPicture(TrafficLightColors trafficLightColors)
        {
            switch (trafficLightColors)
            {
                case TrafficLightColors.Red:
                    pictureBox1.Image = Resources.Red;
                    break;

                case TrafficLightColors.Green:
                    pictureBox1.Image = Resources.Green;
                    break;

                case TrafficLightColors.Orange:
                    pictureBox1.Image = Resources.Orange;
                    break;
            }
        }

        public ctrlTrafficLightByTasks()
        {
            InitializeComponent();
        }

        private int GetChangeColorTime()
        {
            switch (_currentLight)
            {
                case TrafficLightColors.Red:
                    return RedTime;

                case TrafficLightColors.Green:
                    return GreenTime;
                
                case TrafficLightColors.Orange:
                    return OrangeTime;
                
                default:
                    return 5;
            }
        }

        public void Start()
        {
            if(!_isStarted)
                Task.Run(StartProcessAsync);
        }

        public void Stop()
        {
            _start = false;
            _isStarted = false;
        }

        private async Task StartProcessAsync()
        {
            _isStarted = true;
            _start = true;

            while (_start)
            {
                int mileSeconds = GetChangeColorTime() * 1000;
                await Task.Run(() => Task.Delay(mileSeconds));

                switch (_currentLight)
                {
                    case TrafficLightColors.Red:
                        CurrentLight = TrafficLightColors.Orange;
                        OnColorIsSetToOrange?.Invoke();
                        break;

                    case TrafficLightColors.Orange:
                        CurrentLight = TrafficLightColors.Green;
                        OnColorIsSetToGreen?.Invoke();
                        break;

                    case TrafficLightColors.Green:
                        CurrentLight = TrafficLightColors.Red;
                        OnColorIsSetToRed?.Invoke();
                        break;
                }
            }
        }
    }
}
