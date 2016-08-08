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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //proprietate pentru listBox1
        public ListBox MyListBox
        {
            get
            {
                return listBox1;
            }
            set
            {
                listBox1 = value;
            }
        }

        private void btnAddItem_Click(object sender, EventArgs e)
        {
            AddItemForm addItem = new AddItemForm(this);
            addItem.Show();
            this.Hide();
        }
    }
}
