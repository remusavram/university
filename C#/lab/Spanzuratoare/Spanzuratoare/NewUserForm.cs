using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;


namespace Spanzuratoare
{
    public partial class NewUserForm : Form
    {
        public NewUserForm()
        {
            InitializeComponent();
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
            
            Close();
        }
    }
}
