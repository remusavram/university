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
    public partial class DeletePerson : Form
    {
        public DeletePerson()
        {
            InitializeComponent();
            ListPersons();
        }
        private void ListPersons()
        {
            PersonsBL persoaneBL = new PersonsBL();
            comboBoxPersons.DataSource = persoaneBL.GetAllPersons();
            comboBoxPersons.DisplayMember = "Name";
            comboBoxPersons.ValueMember = "PersonID";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int personID = int.Parse(comboBoxPersons.SelectedValue.ToString());
            if (MessageBox.Show("Sigur vreti sa stergeti persoana?", "Intrebare", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                try
                {
                    PersonsBL personsBL = new PersonsBL();
                    personsBL.DeletePerson(personID);
                }
                catch (AgendaException exc)
                {
                    MessageBox.Show(exc.Message, "Eroare");
                }
            }
            ListPersons();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
