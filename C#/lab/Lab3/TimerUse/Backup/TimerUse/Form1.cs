using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TimerUse
{
    public partial class Form1 : Form
    {
        private int delay = 10;
        private DateTime deadline;
        public Form1()
        {
            InitializeComponent();
        }
        private void StartTimer()
        {
            deadline = DateTime.Now.AddSeconds(delay);
            timer1.Start();
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            int secondsRemaining = (deadline - DateTime.Now).Seconds;
            if (secondsRemaining == 0)
            {
                timer1.Stop();
                timer1.Enabled = false;
                MessageBox.Show("Time has expired!");
                delay = 10;
            }
            else
            {
                label1.Text = secondsRemaining.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StartTimer();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            delay = (deadline - DateTime.Now).Seconds;
            deadline = DateTime.Now.AddSeconds(delay);
        }

    }
}
