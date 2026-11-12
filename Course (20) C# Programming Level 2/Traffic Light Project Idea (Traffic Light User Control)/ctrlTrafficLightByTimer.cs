using System;
using System.Windows.Forms;
using Traffic_Light_Project_Idea__Traffic_Light_User_Control_.Properties;

namespace Traffic_Light_Project_Idea__Traffic_Light_User_Control_
{
    public partial class ctrlTrafficLight : UserControl
    {
        public enum TrafficLightColors { Red, Green, Orange }
        private TrafficLightColors _color = TrafficLightColors.Red;

        public TrafficLightColors Color
        {
            set
            {
                _color = value;

                SetPicture(value);

                if (_timer != null)
                    _timer.Interval = GetChangeColorTime() * 1000;
            }
            get { return _color; }
        }

        public short RedTime { set; get; } = 5;
        public short OrangeTime { set; get; } = 3;
        public short GreenTime { set; get; } = 5;

        public event Action OnColorIsSetToRed;
        public event Action OnColorIsSetToOrange;
        public event Action OnColorIsSetToGreen;

        private Timer _timer;

        public ctrlTrafficLight()
        {
            InitializeComponent();
            InitializeTimer();
            SetPicture(_color);
        }

        private void InitializeTimer()
        {
            _timer = new Timer();
            _timer.Tick += Timer_Tick;
        }

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

        private int GetChangeColorTime()
        {
            switch (_color)
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
            if (!_timer.Enabled)
            {
                _timer.Interval = GetChangeColorTime() * 1000;
                _timer.Start();
            }
        }

        public void Stop()
        {
            _timer.Stop();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            switch (_color)
            {
                case TrafficLightColors.Red:
                    Color = TrafficLightColors.Orange;
                    OnColorIsSetToOrange?.Invoke();
                    break;

                case TrafficLightColors.Orange:
                    Color = TrafficLightColors.Green;
                    OnColorIsSetToGreen?.Invoke();
                    break;

                case TrafficLightColors.Green:
                    Color = TrafficLightColors.Red;
                    OnColorIsSetToRed?.Invoke();
                    break;
            }
        }
    }
}