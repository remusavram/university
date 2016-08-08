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
    public partial class ShowPersonsWOPhones : Form
    {
        public ShowPersonsWOPhones()
        {
            InitializeComponent();
            ListPersonsWoPhones();
        }
        private void ListPersonsWoPhones()
        {
            PersonsBL personsBL = new PersonsBL();
            List<Person> persons = personsBL.GetAllPersonsWithoutPhone();
            foreach (Person person in persons)
            {
                String personDetail = person.Name;
                if (person.Address != null)
                {
                    personDetail += " din " + person.Address;
                }
                listBoxPersons.Items.Add(personDetail);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
