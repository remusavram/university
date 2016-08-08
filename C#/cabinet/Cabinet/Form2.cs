using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Cabinet.BusinessLogicLayer;
using Cabinet.access;

namespace Cabinet
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
           

        public void Form2_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet2.dictInterventii' table. You can move, or remove it, as needed.
            this.dictInterventiiTableAdapter.Fill(this.cabinetDataSet2.dictInterventii);
            // TODO: This line of code loads data into the 'cabinetDataSet.interventii' table. You can move, or remove it, as needed.
            this.interventiiTableAdapter.Fill(this.cabinetDataSet.interventii);
            // TODO: This line of code loads data into the 'cabinetDataSet.medici' table. You can move, or remove it, as needed.
         
        }

        private void AfisareInterventiiVechi(object sender, EventArgs e)
        {
            int i = Convert.ToInt32(((DataRowView)interventii.SelectedValue)["idInterventie"]); 
           
      
           // int idInterventie = Convert.ToInt32(interventii.SelectedValue);
            DateTime data = Convert.ToDateTime(monthCalendar1.SelectionRange.Start);
           
            InterventiiVechi_BL interventiiBL = new InterventiiVechi_BL();
            DataSet dsInterventii = interventiiBL.Afisare_interventii(i, data);
            dataGridView1.Visible = true;
            //label1.Text = Convert.ToString(data);
            dataGridView1.DataSource = dsInterventii.Tables[0];   
        
        }
        
    }
}
