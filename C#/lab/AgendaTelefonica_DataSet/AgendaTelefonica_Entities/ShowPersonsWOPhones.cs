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
            DataSet ds = personsBL.GetAllPersonsWithoutPhone();
            for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
            {
                String personDetail = ds.Tables[0].Rows[i]["Name"].ToString();
                if (ds.Tables[0].Rows[i]["Address"] != null)
                {
                    personDetail += " din " + ds.Tables[0].Rows[i]["Address"].ToString();
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
