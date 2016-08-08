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
    public partial class AddPerson : Form
    {
        public AddPerson()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                PersonsBL persoaneBL = new PersonsBL();
                persoaneBL.SavePerson(0, textBoxNume.Text, textBoxAdresa.Text);
            }
            catch (AgendaException exc)
            {
                MessageBox.Show(exc.Message, "Eroare");
            }
            labelIdPersoana.Text = "Persoana a fost adaugata cu succes!";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
