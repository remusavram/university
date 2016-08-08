using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Cabinet.BusinessLogicLayer;

namespace Cabinet
{
    public partial class Form8 : Form
    {
        public Form8()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form8_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter.Fill(this.cabinetDataSet3.medici);

        }

        private void comboMedici_SelectedIndexChanged(object sender, EventArgs e)
        {
            int idMedic = Convert.ToInt32(comboMedici.SelectedValue);
            //System.Windows.Forms.MessageBox.Show(comboMedici.SelectedValue + "-" + comboMedici.ValueMember + "-" + comboMedici.DisplayMember);
            castigMedic_BL listaPacienti_BL = new castigMedic_BL();
            DataSet dsProgramari = listaPacienti_BL.castig_Medic(idMedic);
            //dataGridView1.Visible = true;           
            dataGridView1.DataSource = dsProgramari.Tables[0];   
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void mediciBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }
    }
}
