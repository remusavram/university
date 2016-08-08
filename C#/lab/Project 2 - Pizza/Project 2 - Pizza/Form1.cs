using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Project_2___Pizza.BusinessLogicLayer;

namespace Project_2___Pizza
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            ShowListOfPersons();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void ShowListOfPersons()
        {
            Tip_pizza_Bl pizzaBL = new Tip_pizza_Bl();
            DataSet ds = pizzaBL.Afisare_Pizza();
            for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
            {
                String personDetails = ds.Tables[0].Rows[i]["Nume"].ToString() + " - " + ds.Tables[0].Rows[i]["Procent_manopera"].ToString();
                textBox1.Text += personDetails + "\n\r";
            }

        }
    }
}
