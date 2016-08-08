using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;



namespace Spanzuratoare
{
    public partial class SignIn : Form
    {
        private int imageindex = 0;
        public SignIn()
        {
            InitializeComponent();
        }

       
        private void Form1_Load(object sender, EventArgs e)
        {

            /*     DataSet xmlDataSet = new DataSet();
                 xmlDataSet.ReadXml("Users.xml");
                 UsersList.DataSource = xmlDataSet;
                 UsersList.DataBindings.Add(;
                 //String filename = dlgOpen.FileName;
                 //XmlReader user = XmlReader.Create(filename);
                 XmlReader user = XmlReader.Create("D:/Proiecte Remus/Spanzuratoare/Spanzuratoare/Users.xml");
                 MessageBox.Show(System.IO.File.Exists("D:/Proiecte Remus/Spanzuratoare/Spanzuratoare/Users.xml").ToString());
                 //exista fisierul!!! Nu face bine citirea din fisier!
                     //.LookupNamespace("D:/Proiecte Remus/Spanzuratoare/Spanzuratoare/Users.xml"));
                 while (user.Read())
                 {
                     if (user.NodeType == XmlNodeType.Element && Name == "name")
                     {
                        UsersList.Items.Add(user.ReadString());                    
                     }
                 }
            Close();

            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNode n = D.SelectSingleNode("users");
            MessageBox.Show(n.InnerXml);
            XmlNodeList l = D.SelectNodes("users/user");
            foreach (XmlNode n1 in l)
            {
                MessageBox.Show(n1.SelectSingleNode("name").InnerXml);
            }*/

            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNodeList users = D.SelectNodes("users/user");
            for (int i = 0; i < users.Count; i++)
            {
           //     MessageBox.Show(users[i].SelectSingleNode("name").InnerXml);
                UsersList.Items.Add(users[i].SelectSingleNode("name").InnerXml);
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //MessageBox.Show(UsersList.Items.IndexOf(UsersList));
            //MessageBox.Show(UsersList.SelectedIndex.ToString());
           // MessageBox.Show(UsersList.SelectedItem.ToString());
            if (UsersList.SelectedIndex > -1)
            {
                DeleteUser.Enabled = true;
                Play.Enabled = true;

                XmlDocument D = new XmlDocument();
                D.Load("Users.xml");
                XmlNode user_picture = D.SelectSingleNode("users/user[name='" + UsersList.SelectedItem.ToString() + "']");
                imageindex = int.Parse(user_picture.SelectSingleNode("image").InnerXml);
                poza.Image = ImageList.Images[imageindex];
            }

            
        }

        public void RefreshList()
        {
            UsersList.Items.Clear();

            //refreshing
          //  MessageBox.Show("Hello");
            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNodeList users = D.SelectNodes("users/user");
            for (int i = 0; i < users.Count; i++)
            {
                //     MessageBox.Show(users[i].SelectSingleNode("name").InnerXml);
                UsersList.Items.Add(users[i].SelectSingleNode("name").InnerXml);
            }
            if (UsersList.SelectedIndex > -1)
            {
                DeleteUser.Enabled = true;
                Play.Enabled = true;
            }
            else
            {
                DeleteUser.Enabled = false;
                Play.Enabled = false;
            }

        }

        private void Cancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        public void NewUserProc()
        {

            Application.Run(new NewUserForm(this));

        }

        public static void PlayProc()
        {

            Application.Run(new PlayForm());

        }


        private void NewUser_Click(object sender, EventArgs e)
        {
            
            //System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(NewUserProc));
            NewUserForm nw = new NewUserForm(this);
            nw.Show();

        }

       private void DeleteUser_Click(object sender, EventArgs e)
        {
            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNode user_delete = D.SelectSingleNode("users/user[name='" + UsersList.SelectedItem.ToString() + "']");
            user_delete.ParentNode.RemoveChild(user_delete);
            D.Save("Users.xml");
            RefreshList();

        }

        private void Play_Click(object sender, EventArgs e)
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(PlayProc));

            t.Start();
        }

        private void poza_Click(object sender, EventArgs e)
        {
            
        }

        private void next_Click(object sender, EventArgs e)
        {
            imageindex = (imageindex + 1) % ImageList.Images.Count;
            poza.Image = ImageList.Images[imageindex];

            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNode userNod = D.SelectSingleNode("users/user[name='" + UsersList.SelectedItem.ToString() + "']");
            userNod.SelectSingleNode("image").InnerXml = imageindex.ToString();
            D.Save("Users.xml");
        }

        private void prev_Click(object sender, EventArgs e)
        {
            imageindex = (4+imageindex - 1) % ImageList.Images.Count;
            poza.Image = ImageList.Images[imageindex];

            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNode userNod = D.SelectSingleNode("users/user[name='" + UsersList.SelectedItem.ToString() + "']");
            userNod.SelectSingleNode("image").InnerXml = imageindex.ToString();
            D.Save("Users.xml");
 
        
        }

        
        
    }
}
