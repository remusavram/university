using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;
using System.IO;

namespace Spanzuratoare
{
    public partial class PlayForm : Form
    {
        string guessWord;
        int nChar;
        Label[] lblArray = new Label[50];
        int nTry, nCorrect, nWin;
        private int imageindex = 0;
        string[] cuvinte ;

        public PlayForm(string data, int img)
        {
            InitializeComponent();
            label4.Text = data;
            pictureBox1.Image = Image.FromFile("Wallpapers\\" + img + ".jpg");
        }

        private void PlayForm_Load(object sender, EventArgs e)
        {
            nTry = 0;
            nCorrect = 0;
            nWin = 0;
            XmlDocument D = new XmlDocument();
            D.Load("Posings.xml");
            XmlNode user_picture = D.SelectSingleNode("posings/posing[name='1']");
            imageindex = int.Parse(user_picture.SelectSingleNode("image").InnerXml);
            pictureBox2.Image = imageList1.Images[imageindex - 1];
            cuvinte = new string[50];

        }

        public void writeLabel(int nChar)
        {

            //punem liniutele in functie de literele din cuvant
            int xPos = 20;
            int yPos = 448;
            for (int i = 0; i < nChar; i++)
            {
                lblArray[i] = new Label();
            }

           
            int n = 0;
            while (n < nChar)
            {
                lblArray[n].Tag = n + 1;
                lblArray[n].Width = 22;
                lblArray[n].Height = 23;
                //lblArray[n].FlatStyle = FlatStyle.System;

                lblArray[n].Left = xPos;
                lblArray[n].Top = yPos;

                Controls.Add(lblArray[n]);
                xPos = xPos + lblArray[n].Width;
                lblArray[n].Enabled = false;
                lblArray[n].Text = "_";

                n++;
            }
        }

        public void reset()
        {
            nTry = 0;
            nCorrect = 0;
            int n = 0;
            while (n < nChar)
            {
                lblArray[n].Tag = n + 1;
                lblArray[n].Dispose();
                //lblArray[n].Enabled = false;
                //lblArray[n].Text = " ";
                n++;
            }
            button1.Text = "";
            button2.Text = "";
            button3.Text = "";
            button4.Text = "";
            button5.Text = "";
            button6.Text = "";
            XmlDocument D = new XmlDocument();
            D.Load("Posings.xml");
            XmlNode user_picture = D.SelectSingleNode("posings/posing[name='1']");
            imageindex = int.Parse(user_picture.SelectSingleNode("image").InnerXml);
            pictureBox2.Image = imageList1.Images[imageindex - 1];
        }

        public void loose()
        {
            MessageBox.Show("You lost all 6 lives!");
            foreach (Button button in this.Controls.OfType<Button>())
                button.Enabled = false;
            nWin = 0;
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox4.Checked = false;
            checkBox5.Checked = false;

        }

        public void win()
        {
            foreach (Button button in this.Controls.OfType<Button>())
                button.Enabled = true;
            nWin++;
            switch (nWin)
            {
                case 1:
                    checkBox1.Checked = true;
                    break;
                case 2:
                    checkBox2.Checked = true;
                    break;
                case 3:
                    checkBox3.Checked = true;
                    break;
                case 4:
                    checkBox4.Checked = true;
                    break;
                case 5:
                    checkBox5.Checked = true;
                    break;
            }
            MessageBox.Show("You wan!");
            XmlDocument D = new XmlDocument();
            D.Load("Posings.xml");
            XmlNode user_picture = D.SelectSingleNode("posings/posing[name='1']");
            imageindex = int.Parse(user_picture.SelectSingleNode("image").InnerXml);
            pictureBox2.Image = imageList1.Images[imageindex - 1];
            int imax = cuvinte.Count();
            Random random = new Random();
            int idisplay = random.Next(0, imax);            
            guessWord = cuvinte[idisplay].Trim();
            int n = guessWord.Count();
            writeLabel(n);
            MessageBox.Show("You wan!");
        }


        private void button1_Click(object sender, EventArgs e)
        {
            // MessageBox.Show(((Button)sender).Text);

            Boolean exista = false;
            for (int i = 0; i < nChar; i++)
            {

                if (guessWord[i] == ((Button)sender).Text[0])
                {
                    lblArray[i].Text = ((Button)sender).Text;
                    nCorrect++;
                    exista = true;
                }
            }
            if (nCorrect == nChar)
            {
                //am gasit solutia
                win();
                reset();
                //opreste timpul
            }
            if (!exista)
            {
                nTry++;
                //incarca imaginea noua
                XmlDocument D = new XmlDocument();
                D.Load("Posings.xml");
                XmlNode user_picture = D.SelectSingleNode("posings/posing[name='" + nTry.ToString() + "']");
                imageindex = int.Parse(user_picture.SelectSingleNode("image").InnerXml);
                pictureBox2.Image = imageList1.Images[imageindex];

                switch (nTry)
                {
                    case 1:
                        button1.Text = "X";
                        break;
                    case 2:
                        button2.Text = "X";
                        break;
                    case 3:
                        button3.Text = "X";
                        break;
                    case 4:
                        button4.Text = "X";
                        break;
                    case 5:
                        button5.Text = "X";
                        break;
                    case 6:
                        button6.Text = "X";
                        loose();
                        reset();
                        //opreste timpul
                        break;

                }
            }

            ((Button)sender).Enabled = false;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

            //XmlDocument D = new XmlDocument();
            //D.Load("Users.xml");


        }

        private void categoryToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void newGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Button button in this.Controls.OfType<Button>())
                button.Enabled = true;
            reset();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult result;
            result = MessageBox.Show("Are you sure you want to exit?", "Name Entry Error", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                // Closes the parent form.
                this.Close();
            }
        }

        private void movieToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //MessageBox.Show(((ToolStripMenuItem)sender).Text);         -- afiseaza selectia facuta
            //creat vectorul de cuvinte din fisierul xml       
            
            XmlDocument w = new XmlDocument();
            w.Load("Words.xml");

            XmlNodeList words;

            if (((ToolStripMenuItem)sender).Text == "all categories")
            {
                words = w.SelectNodes("words/word");
            }
            else
            {
                words = w.SelectNodes("/words/word[@category='" + ((ToolStripMenuItem)sender).Text + "']");
                // words = w.SelectNodes("/words/word[@category='Movies']");
            }

            int imax = words.Count;

            if (imax == 0)
            {
                MessageBox.Show("There are no words in this category!Chose another one!");
            }
            else
            {

                //generam aleatoriu un numar in intervalul dat de indicii vectorului
                // si luam cuvantul care are ca indice nr generat
                cuvinte = new string[50];
                Random random = new Random();
                int idisplay = random.Next(0, imax);
                for (int i = 0; i < imax; i++)
                {
                    cuvinte[i] = words[i].SelectSingleNode("name").InnerXml.ToUpper();
                }
                    guessWord = cuvinte[idisplay];                
                nChar = guessWord.Trim().Count();
                //label1.Text = guessWord;
                //MessageBox.Show(nChar.ToString()); 
                writeLabel(nChar);
                


            }

        }

       



    }
}
