namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    partial class formMainApp
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(formMainApp));
            this.btnSave = new System.Windows.Forms.Button();
            this.lblHourRate = new System.Windows.Forms.Label();
            this.tboxHourlyRate = new System.Windows.Forms.TextBox();
            this.ctrlPoolTable6 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.ctrlPoolTable5 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.ctrlPoolTable4 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.ctrlPoolTable3 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.ctrlPoolTable2 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.ctrlPoolTable1 = new Pool_Club_Project_Idea__Pool_User_Control_.ctrlPoolTable();
            this.SuspendLayout();
            // 
            // btnSave
            // 
            this.btnSave.BackColor = System.Drawing.Color.Black;
            this.btnSave.Font = new System.Drawing.Font("Unispace", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnSave.ForeColor = System.Drawing.Color.White;
            this.btnSave.Location = new System.Drawing.Point(630, 629);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(121, 44);
            this.btnSave.TabIndex = 8;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = false;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // lblHourRate
            // 
            this.lblHourRate.AutoSize = true;
            this.lblHourRate.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHourRate.ForeColor = System.Drawing.Color.White;
            this.lblHourRate.Location = new System.Drawing.Point(499, 592);
            this.lblHourRate.Name = "lblHourRate";
            this.lblHourRate.Size = new System.Drawing.Size(232, 24);
            this.lblHourRate.TabIndex = 7;
            this.lblHourRate.Text = "Change All Hours Rates :";
            // 
            // tboxHourlyRate
            // 
            this.tboxHourlyRate.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.tboxHourlyRate.Location = new System.Drawing.Point(737, 588);
            this.tboxHourlyRate.Name = "tboxHourlyRate";
            this.tboxHourlyRate.Size = new System.Drawing.Size(156, 28);
            this.tboxHourlyRate.TabIndex = 6;
            this.tboxHourlyRate.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tboxHourlyRate_KeyPress);
            // 
            // ctrlPoolTable6
            // 
            this.ctrlPoolTable6.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable6.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable6.Location = new System.Drawing.Point(924, 285);
            this.ctrlPoolTable6.Name = "ctrlPoolTable6";
            this.ctrlPoolTable6.PlayerName = "Player Name";
            this.ctrlPoolTable6.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable6.TabIndex = 5;
            this.ctrlPoolTable6.TableNumber = ((short)(6));
            // 
            // ctrlPoolTable5
            // 
            this.ctrlPoolTable5.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable5.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable5.Location = new System.Drawing.Point(462, 285);
            this.ctrlPoolTable5.Name = "ctrlPoolTable5";
            this.ctrlPoolTable5.PlayerName = "Player Name";
            this.ctrlPoolTable5.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable5.TabIndex = 4;
            this.ctrlPoolTable5.TableNumber = ((short)(5));
            // 
            // ctrlPoolTable4
            // 
            this.ctrlPoolTable4.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable4.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable4.Location = new System.Drawing.Point(0, 285);
            this.ctrlPoolTable4.Name = "ctrlPoolTable4";
            this.ctrlPoolTable4.PlayerName = "Player Name";
            this.ctrlPoolTable4.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable4.TabIndex = 3;
            this.ctrlPoolTable4.TableNumber = ((short)(4));
            // 
            // ctrlPoolTable3
            // 
            this.ctrlPoolTable3.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable3.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable3.Location = new System.Drawing.Point(924, 1);
            this.ctrlPoolTable3.Name = "ctrlPoolTable3";
            this.ctrlPoolTable3.PlayerName = "Player Name";
            this.ctrlPoolTable3.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable3.TabIndex = 2;
            this.ctrlPoolTable3.TableNumber = ((short)(3));
            // 
            // ctrlPoolTable2
            // 
            this.ctrlPoolTable2.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable2.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable2.Location = new System.Drawing.Point(462, 1);
            this.ctrlPoolTable2.Name = "ctrlPoolTable2";
            this.ctrlPoolTable2.PlayerName = "Player Name";
            this.ctrlPoolTable2.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable2.TabIndex = 1;
            this.ctrlPoolTable2.TableNumber = ((short)(2));
            // 
            // ctrlPoolTable1
            // 
            this.ctrlPoolTable1.BackColor = System.Drawing.Color.Black;
            this.ctrlPoolTable1.HourlyRate = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.ctrlPoolTable1.Location = new System.Drawing.Point(0, 1);
            this.ctrlPoolTable1.Name = "ctrlPoolTable1";
            this.ctrlPoolTable1.PlayerName = "Ahmed 1";
            this.ctrlPoolTable1.Size = new System.Drawing.Size(456, 278);
            this.ctrlPoolTable1.TabIndex = 0;
            this.ctrlPoolTable1.TableNumber = ((short)(1));
            // 
            // formMainApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1379, 685);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.lblHourRate);
            this.Controls.Add(this.tboxHourlyRate);
            this.Controls.Add(this.ctrlPoolTable6);
            this.Controls.Add(this.ctrlPoolTable5);
            this.Controls.Add(this.ctrlPoolTable4);
            this.Controls.Add(this.ctrlPoolTable3);
            this.Controls.Add(this.ctrlPoolTable2);
            this.Controls.Add(this.ctrlPoolTable1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "formMainApp";
            this.Text = "Pool Club";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private ctrlPoolTable ctrlPoolTable1;
        private ctrlPoolTable ctrlPoolTable2;
        private ctrlPoolTable ctrlPoolTable3;
        private ctrlPoolTable ctrlPoolTable4;
        private ctrlPoolTable ctrlPoolTable5;
        private ctrlPoolTable ctrlPoolTable6;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label lblHourRate;
        private System.Windows.Forms.TextBox tboxHourlyRate;
    }
}

