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
    public partial class ModifyPerson : Form
    {
        public ModifyPerson()
        {
            InitializeComponent();
            GetPersons();
            DisplayCurrentPersonData();
        }

        private void DisplayCurrentPersonData()
        {
            Person person = comboBoxPersons.SelectedItem as Person;
            textBoxName.Text = person.Name;
            textBoxAddress.Text = person.Address;
        }

        private void GetPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            comboBoxPersons.DataSource = personsBL.GetAllPersons();
            comboBoxPersons.DisplayMember = "Name";
        }

        private void comboBoxPersoane_SelectedIndexChanged(object sender, EventArgs e)
        {
            DisplayCurrentPersonData();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PersonsBL personsBL = new PersonsBL();
            Person persoana = comboBoxPersons.SelectedItem as Person;
            persoana.Name = textBoxName.Text;
            persoana.Address = textBoxAddress.Text;
            try
            {
                personsBL.ModifyPerson(persoana);
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
    }
}
