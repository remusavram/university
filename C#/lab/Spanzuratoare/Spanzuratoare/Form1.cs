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
                 }*/
            Close();

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //MessageBox.Show(UsersList.Items.IndexOf(UsersList));
            //MessageBox.Show(UsersList.SelectedIndex.ToString());
            
            if (UsersList.SelectedIndex > -1)
            {
                DeleteUser.Enabled = true;
                Play.Enabled = true;
            }
        }

        private void Cancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        public static void NewUserProc()
        {

            Application.Run(new NewUserForm());

        }

        public static void PlayProc()
        {

            Application.Run(new PlayForm());

        }


        private void NewUser_Click(object sender, EventArgs e)
        {
            
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(NewUserProc));

            t.Start();

        }

       private void DeleteUser_Click(object sender, EventArgs e)
        {
            
        }

        private void Play_Click(object sender, EventArgs e)
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(PlayProc));

            t.Start();
        }

        
        
    }
}
