using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace RunTimeControls
{
    public partial class Form1 : Form
    {
        List<Button> btnList = new List<Button>();
        public Form1()
        {
            InitializeComponent();
            IncarcareButoane();
            btnList.ElementAt(2).Text = "X";
        }
        private void IncarcareButoane()
        {
            for (int i = 0; i < 8; i++)
            {
                Button btn = new Button();
                btn.Name = "b" + i;
                btn.Size = new Size(27, 27);
                btn.Location = new Point(25 + 26 * i, 40);
                if (i % 2 == 0)
                    btn.BackColor = Color.White;
                else btn.BackColor = Color.Black;
                btn.Click += new System.EventHandler(btn_Click);
                btnList.Add(btn);
                this.Controls.Add(btn);
            }
        }
        private void btn_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ati dat click pe butonul de pe pozitia " + ((Button)sender).Name[1]);
            btnList.ElementAt(2).Text = "";
        }
    }
}
