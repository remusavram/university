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
    public partial class Form3 : Form
    {
        SqlConnection cn = new SqlConnection(ConfigurationManager.ConnectionStrings["Cabinet.Properties.Settings.cabinetConnectionString"].ConnectionString);
        //SqlCommand cmd = new SqlCommand();
        //SqlDataReader dr;
                 

        public Form3()
        {
            InitializeComponent();
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if ((textBox1.Text == "") || (textBox2.Text == ""))
            {
                System.Windows.Forms.MessageBox.Show("Trebuie sa completati toate campurile. Id-ul unui medic trebuie sa fie un numar intreg!");
             
            }
            else
            {
                
       
                SqlCommand cmd = new SqlCommand("select * from medici where idMedic = '" + textBox1.Text + "'");
                cmd.Connection = cn;

                //cmd.CommandText = "select * from medici where idMedic = '" + textBox1.Text+"'";
                //cmd.CommandText = "insert into medici (idMedic, nume) values (7,'Remus')";
                SqlDataReader rdr = cmd.ExecuteReader();
                if (!(rdr.HasRows))
                {

                    //cmd.Clone();
                    //cn.Close();
                    //dataGridView1.Refresh();


                    //MessageBox.Show("Record inserted!");
                    int idMedic = Convert.ToInt32(textBox1.Text);
                    string nume = textBox2.Text;
                    addMedic_BL adaugare = new addMedic_BL();
                    System.Windows.Forms.MessageBox.Show(adaugare.AdaugareMedic(idMedic, nume));
                }
                else 
                    MessageBox.Show("Exista deja!");
            }
            //dataGridView1.Visible = true;
            
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter.Fill(this.cabinetDataSet3.medici);
             cn.Open();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }     
    }
}
