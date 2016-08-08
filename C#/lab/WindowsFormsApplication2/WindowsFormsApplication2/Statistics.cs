using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication2
{
    public partial class Statistics : Form
    {
        public Statistics()
        {
            InitializeComponent();
            populateUsers();
        }
        Users utilizatori = new Users(Path.GetDirectoryName(Application.ExecutablePath) + "\\usersData.xml");
        private void populateUsers()
        {
            listBox1.Items.AddRange(utilizatori.getAllUsers().ToArray());
        }


        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            getStats(listBox1.SelectedIndex.ToString(), comboBox1.Text.ToLower());
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            getStats(listBox1.SelectedIndex.ToString(), comboBox1.Text.ToLower());
        }

        private void getStats(string username, string cat)
        {
            string stat;
            string[] data;
            
            if (cat == "all categories" || cat == "")
            {
                cat = "all";
            }
            else
            {
                cat = comboBox1.Text.ToLower();
            }
            if (listBox1.SelectedIndex != -1)
            {
                username = listBox1.SelectedItem.ToString();

                stat = utilizatori.getStatistics(username, cat);
                data = stat.Split('|');
                label1.Text = "Games win: " + data[1];
                label2.Text = "Games play: " + data[0];
            }
        }

        private void Statistics_Load(object sender, EventArgs e)
        {
            comboBox1.Text = "All categories";
        }


    }
}
