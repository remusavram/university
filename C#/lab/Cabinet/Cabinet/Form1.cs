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
    public partial class Form1 : Form
    {
        private Form2 Form2 = null;
        private Form3 Form3 = null;
        private Form4 Form4 = null;
        private Form5 Form5 = null;
        private Form6 Form6 = null;
        private Form7 Form7 = null;
        private Form8 Form8 = null;
        private Form9 Form9 = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 = new Form3();
            //Form2.FormClosed += new FormClosedEventHandler(Form2_FormClosed); 
            Form3.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter1.Fill(this.cabinetDataSet3.medici);
            // TODO: This line of code loads data into the 'cabinetDataSet.pacienti' table. You can move, or remove it, as needed.
            this.pacientiTableAdapter.Fill(this.cabinetDataSet.pacienti);
            // TODO: This line of code loads data into the 'cabinetDataSet2.dictInterventii' table. You can move, or remove it, as needed.
            this.dictInterventiiTableAdapter.Fill(this.cabinetDataSet2.dictInterventii);
            // TODO: This line of code loads data into the 'cabinetDataSet.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter.Fill(this.cabinetDataSet.medici);
            // TODO: This line of code loads data into the 'cabinetDataSet.programari' table. You can move, or remove it, as needed.
            this.programariTableAdapter.Fill(this.cabinetDataSet.programari);

        }

        private void programariBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.programariBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.cabinetDataSet);

        }


        private void AfisProgramariAzi(object sender, EventArgs e)
        {
            int idMedic = Convert.ToInt32(comboMedici.SelectedValue);
            //System.Windows.Forms.MessageBox.Show(comboMedici.SelectedValue + "-" + comboMedici.ValueMember + "-" + comboMedici.DisplayMember);
            programari_Azi_BL programariBL = new programari_Azi_BL();
            DataSet dsProgramari = programariBL.Afisare_programari(idMedic);
            //dataGridView1.Visible = true;
            label1.Visible = true;
            label1.Text = "Lista cu programarile " + System.DateTime.Today.ToString("MM/dd/yy");
            dataGridView1.Visible = true;
            dataGridView1.DataSource = dsProgramari.Tables[0];   
        }

        private void exit(object sender, EventArgs e)
        {
            Close();
        }      

        private void listaCuInterventiileUnuiMedicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form5 = new Form5();            
            Form5.Show();
        }

        private void listaCuProgramarileDeAziAleUnuiMedicToolStripMenuItem_Click(object sender, EventArgs e)
        {

            label2.Visible = true;
            comboMedici.Visible = true;
            dataGridView1.Visible = false;
           
        }

        private void listaInterventiilorUnuiPacientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 = new Form4();
            //Form2.FormClosed += new FormClosedEventHandler(Form2_FormClosed); 
            Form4.Show();
        }

        private void listaDePreturiPentruOInterventieMaiVecheDecatODataSelectataToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 = new Form2();
            //Form2.FormClosed += new FormClosedEventHandler(Form2_FormClosed); 
            Form2.Show();
        }

        private void listaActualaDePreturiACabinetuluiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listaPret_BL listaBL = new listaPret_BL();
            DataSet dsLista = listaBL.DS_ListaPreturi();
            dataGridView1.Visible = true;
            comboMedici.Visible = false;
            label2.Visible = false;
            label1.Visible = true;
            label1.Text = "Lista de preturi valabila la data de " + System.DateTime.Today.ToString("MM/dd/yy");
            dataGridView1.DataSource = dsLista.Tables[0];       
        }

        private void gradulDeOcupareAlUnuiMedicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form6 = new Form6();            
            Form6.Show();     
        }

        private void newToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Form7 = new Form7();
            //Form2.FormClosed += new FormClosedEventHandler(Form2_FormClosed); 
            Form7.Show();
        }

        private void castigulUnuiMedicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form8 = new Form8();
            Form8.Show();
        }

        private void sumaIncasataDeMedicDeLaFiecarePacientToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form9 = new Form9();
            Form9.Show();
        }  
    }
}
