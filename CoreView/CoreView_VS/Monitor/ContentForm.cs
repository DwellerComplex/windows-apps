using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.Threading;
using System.IO;

namespace Monitor
{
    public partial class ContentForm : Form
    {
        #region Global Variables 
        Thread monitorInfoWorkerThread;
        System.Media.SoundPlayer warningSound;
        #endregion

        #region Main Form (Entry Point)
        public ContentForm()
        {
            InitializeComponent();

            // Load sound into object
            warningSound = new System.Media.SoundPlayer("warningSound.wav");

            // Start worker thread that pulls MEMORY and CPU 
            monitorInfoWorkerThread = new Thread(new ThreadStart(PercMonitorThread));
            monitorInfoWorkerThread.Start();
        }

        private void ContentForm_Load(object sender, EventArgs e)
        {
            if (File.Exists("Settings.txt") == true)
            {
                // Assign startup settings from file
                cpuTextBox.Text = File.ReadAllText("Settings.txt"); ;
            }
        }
        #endregion

        #region Context Menu Event Handlers
        /// <summary>
        /// This function is called when the Exit menu item is pressed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Abort thread, close program and dispose sound
            monitorInfoWorkerThread.Abort();
            warningSound.Dispose();
            this.Close();
        }

        /// <summary>
        /// This function is called when the X button in the form controlbox is pressed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            // Abort thread and dispose sound
            monitorInfoWorkerThread.Abort();
            warningSound.Dispose();
        }

        /// <summary>
        /// This function is called when About item is pressed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Release: 2016-11-27 \r\nVersion: Beta 0.0.1 \r\n\r\nMade by: Crumblebit \r\nWebsite: www.crumblebit.com");
        }
        #endregion

        #region Monitoring Thread
        /// <summary>
        /// This function is called from start and pulls CPU and MEMORY information
        /// </summary>
        private void PercMonitorThread()
        {
            // Pull information from PERFMON in windows 
            PerformanceCounter perfCpuCount = new PerformanceCounter("Processor Information", "% Processor Time", "_Total");
            perfCpuCount.NextValue();

            PerformanceCounter perfMemCount = new PerformanceCounter("Memory", "% Committed Bytes In Use");
            perfMemCount.NextValue();

            // Loop Endlessly
            while (true) 
            {
                // Show CPU and MEMORY percentages in progress bars 
                // Invoke makes sure that the information pulled stays on the controls thread to prevent exceptions
                this.Invoke(new Action(() => this.cpuBar.Value = (int)perfCpuCount.NextValue()));
                this.Invoke(new Action(() => this.memoryBar.Value = (int)perfMemCount.NextValue()));

                // Display percentages to the user in form of strings
                this.Invoke(new Action(() => this.cpuLabel.Text = "" + this.cpuBar.Value + "%"));
                this.Invoke(new Action(() => this.memoryLabel.Text = "" + this.memoryBar.Value + "%"));

                // Play sound when value in textbox is reached
                if (this.cpuTextBox.Text != "" && this.cpuBar.Value >= Int32.Parse(this.cpuTextBox.Text))
                {
                    warningSound.Play();
                }

                // Prevent "over-looping" by updating thread every second 
                Thread.Sleep(1000);
            } 
        }
        #endregion
    }
}