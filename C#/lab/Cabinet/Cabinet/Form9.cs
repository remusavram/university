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
    public partial class Form9 : Form
    {
        public Form9()
        {
            InitializeComponent();
        }

        private void comboMedici_SelectedIndexChanged(object sender, EventArgs e)
        {
            int idMedic = Convert.ToInt32(comboMedici.SelectedValue);
            //System.Windows.Forms.MessageBox.Show(comboMedici.SelectedValue + "-" + comboMedici.ValueMember + "-" + comboMedici.DisplayMember);
            sumaIncasata_BL listaPacienti_BL = new sumaIncasata_BL();
            DataSet dsProgramari = listaPacienti_BL.suma_incasata(idMedic);
            //dataGridView1.Visible = true;           
            dataGridView1.DataSource = dsProgramari.Tables[0];   
        }

        private void Form9_Load(object sender, EventArgs e)
        {
            this.mediciTableAdapter.Fill(this.cabinetDataSet3.medici);
        }
    }
}
