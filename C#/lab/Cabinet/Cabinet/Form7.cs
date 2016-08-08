using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Cabinet.access;
using Cabinet.BusinessLogicLayer;
using System.Data.SqlClient;
using System.Configuration;

namespace Cabinet
{
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }


        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if ((textBox1.Text == "") || (textBox2.Text == "") || (textBox3.Text == ""))
            {
                System.Windows.Forms.MessageBox.Show("Trebuie sa completati toate campurile. Id-ul unui medic trebuie sa fie un numar intreg!");

            }
            else
            {

                //cn.Open();
                //SqlCommand cmd = new SqlCommand();
                //cmd.Connection = cn;
                //("insert into medici (idMedic, nume) values (" + Convert.ToInt32(textBox1.Text) + ",'" + textBox2.Text + "')");
                //cmd.CommandText = "insert into medici (idMedic, nume) values (" + Convert.ToInt32(textBox1.Text) + ",'" + textBox2.Text + "')";
                //cmd.CommandText = "insert into medici (idMedic, nume) values (7,'Remus')";
                //cmd.ExecuteNonQuery();
                //cmd.Clone();
                //cn.Close();
                //dataGridView1.Refresh();


                //MessageBox.Show("Record inserted!");
                long cnp = Convert.ToInt64(textBox1.Text);
                string nume = textBox2.Text;
                string adresa = textBox3.Text;
                addPacient_BL adaugare = new addPacient_BL();
                System.Windows.Forms.MessageBox.Show(adaugare.AdaugarePacient(cnp, nume, adresa));
            }
            //dataGridView1.Visible = true;
        }

        private void Form7_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.pacienti' table. You can move, or remove it, as needed.
            this.pacientiTableAdapter.Fill(this.cabinetDataSet3.pacienti);

        }
        

    }
}
