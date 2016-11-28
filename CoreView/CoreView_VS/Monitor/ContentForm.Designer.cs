namespace Monitor
{
    partial class ContentForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ContentForm));
            this.cpuBar = new System.Windows.Forms.ProgressBar();
            this.cpuUsageLabel = new System.Windows.Forms.Label();
            this.memoryBar = new System.Windows.Forms.ProgressBar();
            this.memoryUsageLabel = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.menuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cpuLabel = new System.Windows.Forms.Label();
            this.memoryLabel = new System.Windows.Forms.Label();
            this.cpuTextBox = new System.Windows.Forms.TextBox();
            this.cpuWarningLabel = new System.Windows.Forms.Label();
            this.cpuWarningLabel2 = new System.Windows.Forms.Label();
            this.warningToolTip = new System.Windows.Forms.ToolTip(this.components);
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cpuBar
            // 
            this.cpuBar.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.cpuBar.Location = new System.Drawing.Point(12, 65);
            this.cpuBar.Name = "cpuBar";
            this.cpuBar.Size = new System.Drawing.Size(131, 14);
            this.cpuBar.TabIndex = 0;
            // 
            // cpuUsageLabel
            // 
            this.cpuUsageLabel.AutoSize = true;
            this.cpuUsageLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.cpuUsageLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cpuUsageLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.cpuUsageLabel.Location = new System.Drawing.Point(32, 49);
            this.cpuUsageLabel.Name = "cpuUsageLabel";
            this.cpuUsageLabel.Size = new System.Drawing.Size(63, 13);
            this.cpuUsageLabel.TabIndex = 1;
            this.cpuUsageLabel.Text = "CPU Usage";
            // 
            // memoryBar
            // 
            this.memoryBar.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.memoryBar.Location = new System.Drawing.Point(12, 109);
            this.memoryBar.Name = "memoryBar";
            this.memoryBar.Size = new System.Drawing.Size(131, 14);
            this.memoryBar.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.memoryBar.TabIndex = 2;
            // 
            // memoryUsageLabel
            // 
            this.memoryUsageLabel.AutoSize = true;
            this.memoryUsageLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.memoryUsageLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.memoryUsageLabel.Location = new System.Drawing.Point(32, 93);
            this.memoryUsageLabel.Name = "memoryUsageLabel";
            this.memoryUsageLabel.Size = new System.Drawing.Size(78, 13);
            this.memoryUsageLabel.TabIndex = 3;
            this.memoryUsageLabel.Text = "Memory Usage";
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.Gray;
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(6, 1, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(200, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // menuToolStripMenuItem
            // 
            this.menuToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.menuToolStripMenuItem.Name = "menuToolStripMenuItem";
            this.menuToolStripMenuItem.Size = new System.Drawing.Size(50, 21);
            this.menuToolStripMenuItem.Text = "Menu";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(92, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(52, 21);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // cpuLabel
            // 
            this.cpuLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.cpuLabel.AutoSize = true;
            this.cpuLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.cpuLabel.Location = new System.Drawing.Point(149, 65);
            this.cpuLabel.Name = "cpuLabel";
            this.cpuLabel.Size = new System.Drawing.Size(51, 13);
            this.cpuLabel.TabIndex = 6;
            this.cpuLabel.Text = "cpuLabel";
            // 
            // memoryLabel
            // 
            this.memoryLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.memoryLabel.AutoSize = true;
            this.memoryLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.memoryLabel.Location = new System.Drawing.Point(149, 109);
            this.memoryLabel.Name = "memoryLabel";
            this.memoryLabel.Size = new System.Drawing.Size(69, 13);
            this.memoryLabel.TabIndex = 7;
            this.memoryLabel.Text = "memoryLabel";
            // 
            // cpuTextBox
            // 
            this.cpuTextBox.BackColor = System.Drawing.Color.Gray;
            this.cpuTextBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cpuTextBox.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.cpuTextBox.Location = new System.Drawing.Point(113, 154);
            this.cpuTextBox.MaxLength = 3;
            this.cpuTextBox.Name = "cpuTextBox";
            this.cpuTextBox.Size = new System.Drawing.Size(24, 20);
            this.cpuTextBox.TabIndex = 8;
            this.cpuTextBox.Text = "90";
            this.cpuTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // cpuWarningLabel
            // 
            this.cpuWarningLabel.AutoSize = true;
            this.cpuWarningLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.cpuWarningLabel.Location = new System.Drawing.Point(32, 156);
            this.cpuWarningLabel.Name = "cpuWarningLabel";
            this.cpuWarningLabel.Size = new System.Drawing.Size(75, 13);
            this.cpuWarningLabel.TabIndex = 9;
            this.cpuWarningLabel.Text = "CPU Warning:";
            this.warningToolTip.SetToolTip(this.cpuWarningLabel, "Warns when CPU over given percentage. Remove numbers to disable.");
            // 
            // cpuWarningLabel2
            // 
            this.cpuWarningLabel2.AutoSize = true;
            this.cpuWarningLabel2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.cpuWarningLabel2.Location = new System.Drawing.Point(143, 156);
            this.cpuWarningLabel2.Name = "cpuWarningLabel2";
            this.cpuWarningLabel2.Size = new System.Drawing.Size(15, 13);
            this.cpuWarningLabel2.TabIndex = 10;
            this.cpuWarningLabel2.Text = "%";
            // 
            // ContentForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(200, 195);
            this.Controls.Add(this.cpuWarningLabel2);
            this.Controls.Add(this.cpuWarningLabel);
            this.Controls.Add(this.cpuTextBox);
            this.Controls.Add(this.memoryLabel);
            this.Controls.Add(this.cpuLabel);
            this.Controls.Add(this.memoryUsageLabel);
            this.Controls.Add(this.memoryBar);
            this.Controls.Add(this.cpuUsageLabel);
            this.Controls.Add(this.cpuBar);
            this.Controls.Add(this.menuStrip1);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ContentForm";
            this.Text = "CoreView (Beta 0.0.1)";
            this.TransparencyKey = System.Drawing.Color.White;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar cpuBar;
        private System.Windows.Forms.Label cpuUsageLabel;
        private System.Windows.Forms.ProgressBar memoryBar;
        private System.Windows.Forms.Label memoryUsageLabel;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem menuToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Label cpuLabel;
        private System.Windows.Forms.Label memoryLabel;
        private System.Windows.Forms.TextBox cpuTextBox;
        private System.Windows.Forms.Label cpuWarningLabel;
        private System.Windows.Forms.Label cpuWarningLabel2;
        private System.Windows.Forms.ToolTip warningToolTip;
    }
}

