using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgendaTelefonica_Entities.BusinessLogicLayer;
using AgendaTelefonica_Entities.Exceptions;

namespace AgendaTelefonica_Entities
{
    public partial class ModifyPerson : Form
    {
        public ModifyPerson()
        {
            InitializeComponent();
        }

        private void DisplayCurrentPersonData()
        {
            int personID = int.Parse(comboBoxPersons.SelectedValue.ToString());
            PersonsBL personsBL = new PersonsBL();
            DataSet ds = personsBL.GetPersonByID(personID);
            textBoxName.Text = ds.Tables[0].Rows[0]["Name"].ToString();
            textBoxAddress.Text = ds.Tables[0].Rows[0]["Address"].ToString();
        }

        private void GetPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            comboBoxPersons.DisplayMember = "Name";
            comboBoxPersons.ValueMember = "PersonID";
            comboBoxPersons.DataSource = personsBL.GetAllPersons().Tables[0];
         }

        private void comboBoxPersoane_SelectedIndexChanged(object sender, EventArgs e)
        {
            DisplayCurrentPersonData();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PersonsBL personsBL = new PersonsBL();
            int personID = int.Parse(comboBoxPersons.SelectedValue.ToString());
            try
            {
                personsBL.SavePerson(personID, textBoxName.Text, textBoxAddress.Text);
                GetPersons();
                DisplayCurrentPersonData();
            }
            catch (AgendaException exc)
            {
                MessageBox.Show(exc.Message, "Eroare");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ModifyPerson_Load(object sender, EventArgs e)
        {
            GetPersons();
            DisplayCurrentPersonData();
        
        }
    }
}
