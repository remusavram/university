using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Net;

namespace WindowsFormsApplication2
{
   
    public partial class form1 : Form
       
    {
        Users utilizatori = new Users(Path.GetDirectoryName(Application.ExecutablePath) + "\\usersData.xml");
        public form1()
        {
            InitializeComponent();
            populateUsersListbox();         
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
            if (listBox1.SelectedIndex != -1)
            {
                button3.Enabled = true;
                button2.Enabled = true;
                var username = listBox1.SelectedItem.ToString();
                string imagePath = utilizatori.getAvatar(username);
                if (imagePath != null)
                {
                    Stream fileStream = File.OpenRead(imagePath);
                    Image avatar = Image.FromStream(fileStream);
                    fileStream.Close();
                    pictureBox2.Image = avatar;
                    pictureBox2.Visible = true;
                    pictureBox1.Visible = false;
                }
                else
                {
                    pictureBox1.Visible = true;
                    pictureBox2.Visible = false;
                }
            }
           
         }

       public void populateUsersListbox()
        {
            listBox1.Hide();
            listBox1.Show();
           listBox1.Items.AddRange(utilizatori.getAllUsers().ToArray());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            add_user utilizator_nou = new add_user();
            utilizator_nou.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {

                
              //  Image defautImg = Image.FromFile(Path.GetDirectoryName(Application.ExecutablePath) + "\\userImg\\default.jpg");
              // /pictureBox2.Image = defaultImg;
                var username = listBox1.SelectedItem.ToString();
                utilizatori.deleteUser(username);
                Application.Restart();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var username = listBox1.SelectedItem.ToString();
            string imagePath = utilizatori.getAvatar(username);
            
            game hangman = new game(username+"|"+imagePath);
            
            hangman.Show();
            hangman.Activate();
            //this.Close();
            

        }
        
    }

}
