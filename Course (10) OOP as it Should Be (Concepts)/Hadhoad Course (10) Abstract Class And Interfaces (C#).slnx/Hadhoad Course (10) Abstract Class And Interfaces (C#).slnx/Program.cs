namespace Hadhoad_Course__10__Abstract_Class_And_Interfaces__C__.slnx
{
    public abstract class Mobile
    {
        public abstract void TakePicture(); 
    }

    public interface ISendSMS
    {
        public abstract void SendSMS(string number);
    }

    public class IPhone : Mobile, ISendSMS
    {
        public void SendSMS(string number)
        {
            Console.WriteLine("Send an SMS to this number " + number);
        }

        public override void TakePicture()
        {
            Console.WriteLine("Take a picture");
        }
    }



    internal class Program
    {
        static void Main(string[] args)
        {
            IPhone iphone = new IPhone();
            iphone.TakePicture();
            iphone.SendSMS("01012131401");
        }
    }
}
