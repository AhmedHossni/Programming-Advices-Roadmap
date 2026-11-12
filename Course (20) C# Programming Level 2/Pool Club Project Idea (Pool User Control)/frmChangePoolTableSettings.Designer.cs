namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    partial class frmChangePoolTableSettings
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmChangePoolTableSettings));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tboxPlayerName = new System.Windows.Forms.TextBox();
            this.btnSave = new System.Windows.Forms.Button();
            this.lblTablename = new System.Windows.Forms.Label();
            this.tboxTableName = new System.Windows.Forms.TextBox();
            this.lblHourRate = new System.Windows.Forms.Label();
            this.tboxHourlyRate = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Black;
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.tboxPlayerName);
            this.groupBox1.Controls.Add(this.btnSave);
            this.groupBox1.Controls.Add(this.lblTablename);
            this.groupBox1.Controls.Add(this.tboxTableName);
            this.groupBox1.Controls.Add(this.lblHourRate);
            this.groupBox1.Controls.Add(this.tboxHourlyRate);
            this.groupBox1.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(3, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(449, 270);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Table Settings";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 95);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(128, 21);
            this.label1.TabIndex = 6;
            this.label1.Text = "Player Name :";
            // 
            // tboxPlayerName
            // 
            this.tboxPlayerName.Location = new System.Drawing.Point(143, 88);
            this.tboxPlayerName.Name = "tboxPlayerName";
            this.tboxPlayerName.Size = new System.Drawing.Size(156, 28);
            this.tboxPlayerName.TabIndex = 5;
            // 
            // btnSave
            // 
            this.btnSave.BackColor = System.Drawing.Color.Black;
            this.btnSave.Font = new System.Drawing.Font("Unispace", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnSave.Location = new System.Drawing.Point(167, 200);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(121, 44);
            this.btnSave.TabIndex = 4;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = false;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // lblTablename
            // 
            this.lblTablename.AutoSize = true;
            this.lblTablename.Location = new System.Drawing.Point(9, 40);
            this.lblTablename.Name = "lblTablename";
            this.lblTablename.Size = new System.Drawing.Size(121, 21);
            this.lblTablename.TabIndex = 3;
            this.lblTablename.Text = "Table Name :";
            // 
            // tboxTableName
            // 
            this.tboxTableName.Enabled = false;
            this.tboxTableName.Location = new System.Drawing.Point(143, 33);
            this.tboxTableName.Name = "tboxTableName";
            this.tboxTableName.Size = new System.Drawing.Size(156, 28);
            this.tboxTableName.TabIndex = 2;
            // 
            // lblHourRate
            // 
            this.lblHourRate.AutoSize = true;
            this.lblHourRate.Location = new System.Drawing.Point(9, 148);
            this.lblHourRate.Name = "lblHourRate";
            this.lblHourRate.Size = new System.Drawing.Size(122, 21);
            this.lblHourRate.TabIndex = 1;
            this.lblHourRate.Text = "Hourly Rate :";
            // 
            // tboxHourlyRate
            // 
            this.tboxHourlyRate.Location = new System.Drawing.Point(143, 141);
            this.tboxHourlyRate.Name = "tboxHourlyRate";
            this.tboxHourlyRate.Size = new System.Drawing.Size(156, 28);
            this.tboxHourlyRate.TabIndex = 0;
            this.tboxHourlyRate.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.tboxHourlyRate_KeyPress);
            // 
            // frmChangePoolTableSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(456, 275);
            this.Controls.Add(this.groupBox1);
            this.ForeColor = System.Drawing.Color.White;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "frmChangePoolTableSettings";
            this.Text = "Change Pool Table Settings";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lblHourRate;
        private System.Windows.Forms.TextBox tboxHourlyRate;
        private System.Windows.Forms.Label lblTablename;
        private System.Windows.Forms.TextBox tboxTableName;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tboxPlayerName;
    }
}