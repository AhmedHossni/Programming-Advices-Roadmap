namespace Traffic_Light_Project_Idea__Traffic_Light_User_Control_
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ctrlTrafficLight1 = new Traffic_Light_Project_Idea__Traffic_Light_User_Control_.ctrlTrafficLightByTasks();
            this.ctrlTrafficLight2 = new Traffic_Light_Project_Idea__Traffic_Light_User_Control_.ctrlTrafficLight();
            this.SuspendLayout();
            // 
            // ctrlTrafficLight1
            // 
            this.ctrlTrafficLight1.CurrentLight = Traffic_Light_Project_Idea__Traffic_Light_User_Control_.ctrlTrafficLightByTasks.TrafficLightColors.Red;
            this.ctrlTrafficLight1.GreenTime = ((short)(1));
            this.ctrlTrafficLight1.Location = new System.Drawing.Point(72, 11);
            this.ctrlTrafficLight1.Name = "ctrlTrafficLight1";
            this.ctrlTrafficLight1.OrangeTime = ((short)(1));
            this.ctrlTrafficLight1.RedTime = ((short)(1));
            this.ctrlTrafficLight1.Size = new System.Drawing.Size(191, 280);
            this.ctrlTrafficLight1.TabIndex = 0;
            // 
            // ctrlTrafficLight2
            // 
            this.ctrlTrafficLight2.Color = Traffic_Light_Project_Idea__Traffic_Light_User_Control_.ctrlTrafficLight.TrafficLightColors.Red;
            this.ctrlTrafficLight2.GreenTime = ((short)(1));
            this.ctrlTrafficLight2.Location = new System.Drawing.Point(378, 11);
            this.ctrlTrafficLight2.Name = "ctrlTrafficLight2";
            this.ctrlTrafficLight2.OrangeTime = ((short)(1));
            this.ctrlTrafficLight2.RedTime = ((short)(1));
            this.ctrlTrafficLight2.Size = new System.Drawing.Size(191, 280);
            this.ctrlTrafficLight2.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(667, 301);
            this.Controls.Add(this.ctrlTrafficLight2);
            this.Controls.Add(this.ctrlTrafficLight1);
            this.Name = "Form1";
            this.Text = "Traffic Light Demo";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private ctrlTrafficLightByTasks ctrlTrafficLight1;
        private ctrlTrafficLight ctrlTrafficLight2;
    }
}

