using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    public static class clsUtility
    {
        public static bool IsValidDecimalKeyPress(char c, string tboxHourlyRateText)
        {
            if (c == (char)Keys.Back)
                return true;

            if (char.IsDigit(c))
                return true;

            if (c == '.' && !tboxHourlyRateText.Contains("."))
                return true;

            return false;
        }
    }
}
