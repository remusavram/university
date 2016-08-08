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
    public partial class NewUserForm : Form
    {
        private SignIn caller;
        public NewUserForm(SignIn f)
        {
            InitializeComponent();
            caller = f;
        }

        private void Cancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        public static void LoginProc()
        {

            Application.Run(new SignIn());

        }

        private void Ok_Click(object sender, EventArgs e)
        {
            SignIn.ActiveForm.Activate();
            XmlDocument D = new XmlDocument();
            D.Load("Users.xml");
            XmlNodeList users = D.SelectNodes("users/user");
            Boolean p = true;
 
            for (int i = 0; i < users.Count; i++)
            {
                if (users[i].SelectSingleNode("name").InnerXml == UserNameBox.Text)
                    p = false;
                //     MessageBox.Show(users[i].SelectSingleNode("name").InnerXml);
                //UsersList.Items.Add(users[i].SelectSingleNode("name").InnerXml);
            }
            if (p)
            {

                XmlNode userNode = D.CreateElement("user");
                userNode.InnerXml = "<name>" + UserNameBox.Text + "</name><image>0</image>";
                D.SelectSingleNode("users").AppendChild(userNode);
                D.Save("Users.xml");
                caller.RefreshList();
                Close();
            }
            else
                MessageBox.Show("Acest user exista deja!");
            //userNode.AppendChild(D.CreateElement("name"));
           

            
        }

        private void UserNameBox_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void NewUserForm_Load(object sender, EventArgs e)
        {
           // UserNameBox.Focus();
        }
    }
}
