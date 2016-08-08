using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;

namespace Spanzuratoare
{
    public partial class PlayForm : Form
    {
        public PlayForm( string data, int img)
        {
            InitializeComponent();
            labr4.Text = data;
            pictureBox1.Image = Image.FromFile("Wallpapers\\" + img + ".jpg");
        }

        private void button1_Click(object sender, EventArgs e)
        {
           // MessageBox.Show(((Button)sender).Text);
            ((Button)sender).Enabled = false;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

            //XmlDocument D = new XmlDocument();
            //D.Load("Users.xml");
            

        }


    }
}
