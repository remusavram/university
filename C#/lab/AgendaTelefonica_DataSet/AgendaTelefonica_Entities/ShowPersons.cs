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
    public partial class ShowPersons : Form
    {
        public ShowPersons()
        {
            InitializeComponent();
            ShowListOfPersons();
        }
        private void ShowListOfPersons()
        {
            PersonsBL personsBL = new PersonsBL();
            DataSet ds = personsBL.GetAllPersons();
            for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
            {
                String personDetails = ds.Tables[0].Rows[i]["Name"].ToString() + " din " + ds.Tables[0].Rows[i]["Address"].ToString();
                personList.Items.Add(personDetails);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
