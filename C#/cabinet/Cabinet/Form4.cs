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

namespace Cabinet
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
            dataGridView1.Visible = false;
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.pacienti' table. You can move, or remove it, as needed.
            this.pacientiTableAdapter2.Fill(this.cabinetDataSet3.pacienti);
            // TODO: This line of code loads data into the 'cabinetDataSet1.pacienti' table. You can move, or remove it, as needed.
            this.pacientiTableAdapter1.Fill(this.cabinetDataSet1.pacienti);
            // TODO: This line of code loads data into the 'cabinetDataSet.programari' table. You can move, or remove it, as needed.
            this.programariTableAdapter.Fill(this.cabinetDataSet.programari);
            // TODO: This line of code loads data into the 'cabinetDataSet.pacienti' table. You can move, or remove it, as needed.
            this.pacientiTableAdapter.Fill(this.cabinetDataSet.pacienti);

        }

        private void AfisInterventiiPacienti(object sender, EventArgs e)
        {
            // int i = Convert.ToInt32(((DataRowView)interventii.SelectedValue)["idInterventie"]); 
            //int idPacient = Convert.ToInt32(((DataRowView)comboBox1.SelectedValue)["cnp"]);
            long idPacient = Convert.ToInt64(comboBox1.SelectedValue);
            label2.Text = "CNP " + Convert.ToString(comboBox1.SelectedValue);
            //label3.Text=Convert.ToString(comboBox1.SelectedValue);
            //label1.Visible = true;
            //label1.Text = "Interventiile pentru pacient ";
            dataGridView1.Visible = true;
            
            interventiiPacient_BL interventiiBL = new interventiiPacient_BL();
            DataSet dsInterventii = interventiiBL.Afisare_interventii_pacient(idPacient);
            //dataGridView1.Visible = true;

            dataGridView1.DataSource = dsInterventii.Tables[0];
        }

    }
}
