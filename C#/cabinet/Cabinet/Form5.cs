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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void Form5_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter.Fill(this.cabinetDataSet3.medici);

        }

        private void AfisarelistaPacienti(object sender, EventArgs e)
        {
            int idMedic = Convert.ToInt32(comboMedici.SelectedValue);
            //System.Windows.Forms.MessageBox.Show(comboMedici.SelectedValue + "-" + comboMedici.ValueMember + "-" + comboMedici.DisplayMember);
            listaPacientiSortataDupaNrInterventii_BL listaPacienti_BL = new listaPacientiSortataDupaNrInterventii_BL();
            DataSet dsProgramari = listaPacienti_BL.listaPacienti_SortataDupaNrInterventii(idMedic);
            //dataGridView1.Visible = true;           
            dataGridView1.DataSource = dsProgramari.Tables[0];   
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
