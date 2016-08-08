using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SendingDatasBetweenForms
{
    public partial class AddItemForm : Form
    {
        Form1 f1;
        public AddItemForm(Form1 f1)
        {
            InitializeComponent();
            this.f1 = f1;
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            f1.MyListBox.Items.Add(txtNewItem.Text);
            this.Close();
            f1.Show();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
            f1.Show();
        }
    }
}
