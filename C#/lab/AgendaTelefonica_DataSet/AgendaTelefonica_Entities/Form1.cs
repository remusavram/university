using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using AgendaTelefonica_Entities.BusinessLogicLayer;

namespace AgendaTelefonica_Entities
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void toateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ShowPersons formaVizualizarePersoane = new ShowPersons();
            formaVizualizarePersoane.ShowDialog();
            formaVizualizarePersoane.Dispose();
        }

        private void persoaneCareNuAuTelefonToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ShowPersonsWOPhones formaPersoaneCareNuAuTelefon = new ShowPersonsWOPhones();
            formaPersoaneCareNuAuTelefon.ShowDialog();
            formaPersoaneCareNuAuTelefon.Dispose();
        }

        private void persoaneSiTelefoaneToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PersonsAndPhones formaPersoaneSiTelefoane = new PersonsAndPhones();
            formaPersoaneSiTelefoane.ShowDialog();
            formaPersoaneSiTelefoane.Dispose();
        }

        private void persoaneToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddPerson formaAdaugarePersoane = new AddPerson();
            formaAdaugarePersoane.ShowDialog();
            formaAdaugarePersoane.Dispose();
        }

        private void telefoanePentruOPersoanaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddPhone formaAdaugareTelefoane = new AddPhone();
            formaAdaugareTelefoane.ShowDialog();
            formaAdaugareTelefoane.Dispose();
        }

        private void persoaneToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            DeletePerson formaStergerePersoana = new DeletePerson();
            formaStergerePersoana.ShowDialog();
            formaStergerePersoana.Dispose();
        }

        private void telefoanePentruOPersoanaToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            DeletePhone formaStergereTelefoane = new DeletePhone();
            formaStergereTelefoane.ShowDialog();
            formaStergereTelefoane.Dispose();
        }

        private void datePersoaneToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ModifyPerson formaModificarePersoane = new ModifyPerson();
            formaModificarePersoane.ShowDialog();
            formaModificarePersoane.Dispose();
        }
    }
}
