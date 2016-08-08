using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Laborator_1_project_2___NotepadProject
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            CreateButton();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            MessageBox.Show("Hello");   //nu merge
        }

        private void CreateButton()
        {
            Button b = new Button();
            b.Size = new Size(35, 35);
            b.Text = "Click";
            b.Location = new Point(100, 30);
            this.Controls.Add(b);
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog.Fillter = "Text File(*.txt|All Files";
            if (SaveFileDialog() == DialogResult.OK)
            {
                StringWriter SW = new StringWriter(SaveFileDialog.file);
                SW.WriteLine(textBox1.Text);
            }
        }
    }
}
