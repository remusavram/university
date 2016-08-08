using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgendaTelefonica_Entities.BusinessLogicLayer;
using AgendaTelefonica_Entities.Entities;
using AgendaTelefonica_Entities.Exceptions;

namespace AgendaTelefonica_Entities
{
    public partial class AddPhone : Form
    {
        public AddPhone()
        {
            InitializeComponent();
            PopulatePersonList();
        }
        private void PopulatePersonList()
        {
            PersonsBL personsBL = new PersonsBL();
            comboBoxPersons.DataSource = personsBL.GetAllPersons();
            comboBoxPersons.DisplayMember = "Name";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                Person person = comboBoxPersons.SelectedItem as Person;
                Phone phone = new Phone() { PhoneNumber = textBoxNumber.Text, Description = textBoxDescription.Text, PersonID = person.PersonID };
                PhonesBL phoneBL = new PhonesBL();
                phoneBL.AddPhone(phone);
                labelIDPhone.Text = "Telefon adaugat cu id-ul: " + phone.PhoneID.ToString();
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
    }
}
