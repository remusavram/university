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
    public partial class PersonsAndPhones : Form
    {
        public PersonsAndPhones()
        {
            InitializeComponent();
            GetPersons();
            ShowPhonesForCurrentPerson();
        }
        private void ShowPhonesForCurrentPerson()
        {
            Person selectedPerson = comboBoxPersons.SelectedItem as Person;
            PhonesBL phonesBL = new PhonesBL();
            listBoxPhones.Items.Clear();
            foreach (Phone phone in phonesBL.GetPhonesForPerson(selectedPerson))
            {
                String phoneLine = String.Format("{0}, {1}", phone.PhoneNumber.Trim(), phone.Description);
                listBoxPhones.Items.Add(phoneLine);
            }
            if (listBoxPhones.Items.Count == 0)
            {
                listBoxPhones.Items.Add("niciun numar de telefon cunoscut");
            }
        }

        private void GetPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            List<Person> persons = personsBL.GetAllPersons();
            comboBoxPersons.DataSource = persons;
            comboBoxPersons.DisplayMember = "Name";
        }

        private void comboBoxPersoane_SelectedIndexChanged(object sender, EventArgs e)
        {
            ShowPhonesForCurrentPerson();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
