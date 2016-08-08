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
    public partial class PersonsAndPhones : Form
    {
        public PersonsAndPhones()
        {
            InitializeComponent();
        }

        private void ShowPhonesForCurrentPerson()
        {
            int personID = int.Parse(comboBoxPersons.SelectedValue.ToString());
            PhonesBL phonesBL = new PhonesBL();
            DataSet ds = phonesBL.GetPhonesForPerson(personID);
            listBoxPhones.Items.Clear();
            for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
            {
                String phoneDetails = ds.Tables[0].Rows[i]["PhoneNumber"].ToString() + " " + ds.Tables[0].Rows[i]["Description"].ToString();
                listBoxPhones.Items.Add(phoneDetails);
            }
            if (listBoxPhones.Items.Count == 0)
            {
                listBoxPhones.Items.Add("niciun numar de telefon cunoscut");
            }
            listBoxPhones.Refresh();
        }

        private void GetPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            comboBoxPersons.ValueMember = "PersonID";
            comboBoxPersons.DisplayMember = "Name";
            comboBoxPersons.DataSource = personsBL.GetAllPersons().Tables[0];
        }

        private void comboBoxPersoane_SelectedIndexChanged(object sender, EventArgs e)
        {
            ShowPhonesForCurrentPerson();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void PersonsAndPhones_Load(object sender, EventArgs e)
        {
            GetPersons();
            ShowPhonesForCurrentPerson();
        }
    }
}
