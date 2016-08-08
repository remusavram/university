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
    public partial class add_user : Form
    {
        Users add = new Users(Path.GetDirectoryName(Application.ExecutablePath) + "/usersData.xml");
        public add_user()
        {
            InitializeComponent();
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "[type username here]")
                textBox1.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            switch (textBox1.Text)
            {
                case "":
                    label1.Show();
                    label1.Text = "Type a username!";
                    break;
                case "[type username here]":
                    label1.Show();
                    label1.Text = "Type a username!";
                    break;
                default:
                    label1.Hide();
                    if (add.checkUser(textBox1.Text))
                    {
                        add.addUser(textBox1.Text, textBox1.Text + label2.Text);
                        Application.Restart();
                        

                       
                    }
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog alegeImg = new OpenFileDialog();
            alegeImg.Filter = "JPEG(*.jpg)|*.jpg|GIF(*.gif)|*.gif|Fisiere permise(*.jpg,*.gif)|(*.jpg,*.gif)";
            alegeImg.Title = "Alege avatar";
            alegeImg.InitialDirectory = @"C:\Users\Public\Pictures\Sample Pictures\";
            alegeImg.Filter = "All files (*.*)|*.*|All files (*.*)|*.*";
            alegeImg.FilterIndex = 2;
            alegeImg.RestoreDirectory = true;
            if (alegeImg.ShowDialog() == DialogResult.OK)
            {
                string extensie = alegeImg.FileName.Substring(alegeImg.FileName.LastIndexOf("."));
                label2.Text = extensie;
                string locatieImg = Path.GetDirectoryName(Application.ExecutablePath) + "\\userImg\\" + textBox1.Text + extensie;
               
                File.Copy(alegeImg.FileName, locatieImg, true);
                Image avatar = Image.FromFile(locatieImg);
                pictureBox1.Image = avatar;
                button2.Enabled = false;
          
               
            }

            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            button2.Enabled = true;
        }
    }
}
