namespace Pool_Club_Project_Idea__Pool_User_Control_
{
    partial class ctrlPoolTable
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cmsChangeTableSettings = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.changeTableHourRateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lblHourRate = new System.Windows.Forms.Label();
            this.tboxPlayerName = new System.Windows.Forms.TextBox();
            this.lblTimer = new System.Windows.Forms.Label();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            this.cmsChangeTableSettings.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Black;
            this.groupBox1.ContextMenuStrip = this.cmsChangeTableSettings;
            this.groupBox1.Controls.Add(this.lblHourRate);
            this.groupBox1.Controls.Add(this.tboxPlayerName);
            this.groupBox1.Controls.Add(this.lblTimer);
            this.groupBox1.Controls.Add(this.btnStop);
            this.groupBox1.Controls.Add(this.btnStart);
            this.groupBox1.Controls.Add(this.pictureBox1);
            this.groupBox1.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(3, 4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(449, 270);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Table 1";
            // 
            // cmsChangeTableSettings
            // 
            this.cmsChangeTableSettings.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.cmsChangeTableSettings.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.changeTableHourRateToolStripMenuItem});
            this.cmsChangeTableSettings.Name = "cmsChangeTableSettings";
            this.cmsChangeTableSettings.Size = new System.Drawing.Size(239, 28);
            this.cmsChangeTableSettings.Opening += new System.ComponentModel.CancelEventHandler(this.cmsChangeTableSettings_Opening);
            // 
            // changeTableHourRateToolStripMenuItem
            // 
            this.changeTableHourRateToolStripMenuItem.Name = "changeTableHourRateToolStripMenuItem";
            this.changeTableHourRateToolStripMenuItem.Size = new System.Drawing.Size(238, 24);
            this.changeTableHourRateToolStripMenuItem.Text = "Change Table Hour Rate";
            this.changeTableHourRateToolStripMenuItem.Click += new System.EventHandler(this.changeTableHourRateToolStripMenuItem_Click);
            // 
            // lblHourRate
            // 
            this.lblHourRate.AutoSize = true;
            this.lblHourRate.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHourRate.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.lblHourRate.Location = new System.Drawing.Point(317, 223);
            this.lblHourRate.Name = "lblHourRate";
            this.lblHourRate.Size = new System.Drawing.Size(62, 28);
            this.lblHourRate.TabIndex = 5;
            this.lblHourRate.Text = "[$$]";
            // 
            // tboxPlayerName
            // 
            this.tboxPlayerName.BackColor = System.Drawing.Color.Black;
            this.tboxPlayerName.Font = new System.Drawing.Font("Unispace", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tboxPlayerName.ForeColor = System.Drawing.Color.White;
            this.tboxPlayerName.Location = new System.Drawing.Point(97, 24);
            this.tboxPlayerName.MaxLength = 18;
            this.tboxPlayerName.Name = "tboxPlayerName";
            this.tboxPlayerName.Size = new System.Drawing.Size(260, 35);
            this.tboxPlayerName.TabIndex = 0;
            this.tboxPlayerName.Text = "Player Name";
            this.tboxPlayerName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblTimer
            // 
            this.lblTimer.AutoSize = true;
            this.lblTimer.Font = new System.Drawing.Font("Tahoma", 16.2F, System.Drawing.FontStyle.Bold);
            this.lblTimer.Location = new System.Drawing.Point(75, 223);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(143, 34);
            this.lblTimer.TabIndex = 4;
            this.lblTimer.Text = "00:00:00";
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.Black;
            this.btnStop.Font = new System.Drawing.Font("Unispace", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnStop.Location = new System.Drawing.Point(290, 150);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(121, 44);
            this.btnStop.TabIndex = 2;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Black;
            this.btnStart.Font = new System.Drawing.Font("Unispace", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.Location = new System.Drawing.Point(290, 100);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(121, 44);
            this.btnStart.TabIndex = 1;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Pool_Club_Project_Idea__Pool_User_Control_.Properties.Resources.closeup_billiard_balls_sticks_table;
            this.pictureBox1.Location = new System.Drawing.Point(31, 70);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(230, 150);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // ctrlPoolTable
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.Controls.Add(this.groupBox1);
            this.Name = "ctrlPoolTable";
            this.Size = new System.Drawing.Size(457, 274);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.cmsChangeTableSettings.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.TextBox tboxPlayerName;
        private System.Windows.Forms.ContextMenuStrip cmsChangeTableSettings;
        private System.Windows.Forms.ToolStripMenuItem changeTableHourRateToolStripMenuItem;
        private System.Windows.Forms.Label lblHourRate;
    }
}
