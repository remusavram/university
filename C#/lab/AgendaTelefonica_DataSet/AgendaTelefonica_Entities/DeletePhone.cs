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
    public partial class DeletePhone : Form
    {
        public DeletePhone()
        {
            InitializeComponent();
            ListPersons();
            ListPhones();
        }
        private void ListPhones()
        {
            int personID = int.Parse(comboBoxPersons.SelectedValue.ToString());
            PhonesBL phonesBL = new PhonesBL();
            listBoxTelefoane.DataSource = phonesBL.GetPhonesForPerson(personID);
            listBoxTelefoane.DisplayMember = "PhoneNumber";
            listBoxTelefoane.ValueMember = "PhoneID";
        }

        private void ListPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            comboBoxPersons.DataSource = personsBL.GetAllPersons();
            comboBoxPersons.DisplayMember = "Name";
            comboBoxPersons.ValueMember = "PersonID";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int phoneID = int.Parse(listBoxTelefoane.SelectedValue.ToString());
            PhonesBL phonesBL = new PhonesBL();
            try
            {
                if (listBoxTelefoane.Items.Count != 0)
                {
                    phonesBL.DeletePhone(phoneID);
                    ListPhones();
                }
                else MessageBox.Show("Persoana nu are nici un numar de telefon!");
            }
            catch (AgendaException exc)
            {
                MessageBox.Show(exc.Message);
            }
        }

        private void comboBoxPersoane_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListPhones();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
