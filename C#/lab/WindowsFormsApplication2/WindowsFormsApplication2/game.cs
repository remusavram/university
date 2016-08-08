using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.Linq;
using System.IO;


namespace WindowsFormsApplication2
{
    public partial class game : Form
    {

        
        int timp = 30, y = 0, k=1;
        
        // formul game, parametrul data = utilizatorul selectat pentru joc + detalii
        public game( string data)
        {  
            InitializeComponent();
            string[] texte = data.Split('|');
            label1.Text = texte[0];
            string imagePath = texte[1];
            if (imagePath != null)
            {

                Image avatar = Image.FromFile(imagePath);
                pictureBox8.Image = avatar;
                pictureBox8.Visible = true;
                pictureBox9.Visible = false;
            }
            else
            {
                pictureBox8.Visible = false;
                pictureBox9.Visible = true;
            }
        }

        //game load
        private void game_Load(object sender, EventArgs e)
        {
            loadGame();   
        }

        //butonul about
        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(" Andrei Bogdan Ciungulete \n Matematica - Informatica  \n Anul II ID ", "About", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
        }


        //afisez dinamic tastatura
        Button[] btnArray = new Button[26];
        private void addKeyboard()
        {
            int xPos = 55;
            int yPos = 5;
            for (int i = 0; i < 26; i++)
            {
                    btnArray[i] = new Button();
            }
            
            int n = 0;

            while (n < 26)
            {
                btnArray[n].Tag = n + 1;
                btnArray[n].Width = 25;  
                btnArray[n].Height = 25;
                btnArray[n].FlatStyle = FlatStyle.System;
                
                if (n == 9) 
                {
                    xPos = 55;
                    yPos = 30;
                }
                else if (n == 18)
                {
                    xPos = 65;
                    yPos = 55;
                }
 
                btnArray[n].Left = xPos;
                btnArray[n].Top = yPos;
              
                keyboardPanel.Controls.Add(btnArray[n]); 
                xPos = xPos + btnArray[n].Width;
                btnArray[n].Enabled = false;
   
                btnArray[n].Text = ((char)(n + 65)).ToString();
                btnArray[n].Click += new System.EventHandler(ClickLetter);
                n++;
            }
                        
        }

        //butonul new game
        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            startGame();               
            
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            progressBar1.Visible = true;
            progressBar1.Increment(1);
            label3.Text = "Time remaining: " + timp.ToString() + " s";
            timp--;
            if (progressBar1.Value == progressBar1.Maximum)
            {
                timer2.Stop();
                k = 1;
                label3.Text = "You lose";
                MessageBox.Show("Cuvantul era " + cuvant, "Solutia", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                resetGame();
            }
                
        } // timerul pentru joc

        private static words Cuvant = new words(Path.GetDirectoryName(Application.ExecutablePath) + "\\wordsXml.xml"); // apelez clasa words (constructorul apeleaza xmlul)

        string cuvant = ""; // cuvantul initial
        List<Label> labels = new List<Label>(); // array pentru _
        List<Button> greseli = new List<Button>(); // array pentru greselibox
        List<PictureBox> bodyParts = new List<PictureBox>(); // array pentru hangman
        List<CheckBox> levels = new List<CheckBox>(); // array pentru level
       
        // adaug dinamic greselibox
        public void makeGreseliBox()
        {
            for (int i = 0; i < 6; i++)
            {
                greseli.Add(new Button());
                greseli[i].Location = new Point((i * 45) + 20, 10);
                greseli[i].Text = "";
                greseli[i].Height = 44;
                greseli[i].Width = 44;

                greseli[i].Parent = groupBox2;
                greseli[i].BringToFront();
                greseli[i].CreateControl();
            }
        }

        //afisez _ pentru fiecare litera din cuvant
        public void makeLabels()
        {
            
            char[] litere = cuvant.ToCharArray();
            int intre = 330 / litere.Length;
            for (var i = 0; i < litere.Length; i++)
            {
                labels.Add(new Label());
                labels[i].Location = new Point((i * intre) + 10, 30);
                if(litere[i]==" ".ToCharArray()[0])
                    labels[i].Text = " ";
                else
                    labels[i].Text = "_";
                labels[i].Parent = panel1;
                labels[i].BringToFront();
                labels[i].CreateControl();
            }
        }
        string literefolosite = "|";
        //Submit pentru fiecare litera din tastatura de pe ecran
        public void ClickLetter(Object sender, System.EventArgs e)
        {
            Button btn = (Button)sender;
            btn.Enabled = false;
            literefolosite = literefolosite + btn.Text + "|";
            char litera = btn.Text.ToCharArray()[0];
            if (cuvant.Contains(litera))
            {
                char[] litere = cuvant.ToCharArray();

                for (int i = 0; i < litere.Length; i++)
                {
                    if (litere[i] == litera)
                    {
                        labels[i].Text = litera.ToString();
                    }
                }
            }
            else
            {
                greseli[y].Text = "X";
                bodyParts[y + 1].BringToFront();
                bodyParts[y + 1].Visible = true;
                y++;
                if (y == 6)
                {
                   
                    MessageBox.Show("Cuvantul era " + cuvant, "Solutia", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    resetGame();
                }
            }
            if (checkWinLevel())
            {

                
                if (k % 5 == 0)
                {
                    gameWin();
                }
                else
                {
                    levels[k-1].Checked = true;
                    k++;
                    MessageBox.Show("You win a level");
                    
                    resetGame();
                    literefolosite = "";
                }
                
            }
           

        }

        //afiseaza spanzuratoarea(imaginea)
        public void showHangman()
        {
            bodyParts.Add(pictureBox1); // cadrul de lemn
            bodyParts.Add(pictureBox2); // capul
            bodyParts.Add(pictureBox7); // corpul
            bodyParts.Add(pictureBox4); // mana dreapta
            bodyParts.Add(pictureBox3); // mana stanga
            bodyParts.Add(pictureBox5); // piciorul stang
            bodyParts.Add(pictureBox6); // piciorul drept
            bodyParts[0].BringToFront(); 
            bodyParts[0].Visible = true; // se afiseaza doar cardul de lemn;
            bodyParts[1].Visible = false;
            bodyParts[2].Visible = false;
            bodyParts[3].Visible = false;
            bodyParts[4].Visible = false;
            bodyParts[5].Visible = false;
            bodyParts[6].Visible = false;
        }
        
        //afiseaza nivelul
        public void showLevel()
        {
            for (int i = 0; i < 5; i++)
            {
                levels.Add(new CheckBox());
                levels[i].Location = new Point((i *30) + 10, 2);
                levels[i].Height = 25;
                levels[i].Width = 25;
                levels[i].Enabled = false;
                levels[i].Parent = panel2;
                levels[i].CreateControl();
            }
        }

        private bool checkWinLevel()
        {
            foreach (Label l in labels)
            {
                if (l.Text == "_")
                {
                    return false;
                }
                
            }
            return true;
        }

        private void gameWin()
        {
            
            MessageBox.Show("You win a game");
            foreach (CheckBox x in levels)
                x.Checked = false;
            Users win = new Users(Path.GetDirectoryName(Application.ExecutablePath) + "\\usersData.xml");
            win.addstatistics(getCurentCategory(), label1.Text, "win");
            resetGame();
        }

        private void startGame()
        {
            resetGame();
            if (cuvant == "")
            {
                cuvant = Cuvant.getRandomWord();
            }
            else
            {
                foreach (ToolStripMenuItem c in categMenu)
                {
                    if (c.Checked == true)
                    {

                        if (c.Text.ToLower() == "all categories")
                        {
                            cuvant = Cuvant.getRandomWord();
                        } 
                        else
                        {
                            cuvant = Cuvant.getRandomWordCat(c.Text.ToLower());
                        }
                    }
                }
            }
            resetKeyboard("enabled");
            
            timer2.Start();
            makeLabels();
        }

        private void resetGame()
        {
            
            y = 0; timp = 30;
            progressBar1.Value = 0;
            progressBar1.Visible = false;
            timer2.Stop();
            label3.Text = "";
            showHangman();
            showLevel();
            makeGreseliBox();
            resetKeyboard("disabled");
            
            
            
        }
    
        private void loadGame()
        {
            makeGreseliBox();
            makeCategoriesButtons();
            addKeyboard();
            showLevel();
            
        }


        //butonul exit
        private void toolStripMenuItem8_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        
        //afisez formul pt statistica
        private void toolStripMenuItem7_Click(object sender, EventArgs e)
        {
            Form statistics = new Statistics();
            statistics.Show();
        }

        
        
        
        private static string[] cat = Cuvant.getCategories(); // toate categoriile distincte din xml
        private static int nrcat = cat.Length + 1;// numarul categoriilor + 1 (all categories)
        ToolStripMenuItem[] categMenu = new ToolStripMenuItem[nrcat]; //array de meniu pt categorii
        List<string> contorLevels = new List<string>();
        //aici creez categoriile dinamic, in functie de categoriile din xml
        private void makeCategoriesButtons()
        {
              
           
            for (int i = 0; i <nrcat; i++)
            {
                categMenu[i] = new ToolStripMenuItem();
            }

            int n = 1;
            categMenu[0].Text = "All categories";
            categMenu[0].Click += new System.EventHandler(clickCateg);
            categMenu[0].Checked = true;
            contorLevels.Add("all");
            toolStripMenuItem2.DropDownItems.Add(categMenu[0]);
            while (n < nrcat)
            {
                categMenu[n].Text = UppercaseFirst(cat[(n-1)]);
                toolStripMenuItem2.DropDownItems.Add(categMenu[n]);
                contorLevels.Add(cat[(n - 1)].ToLower());
                categMenu[n].Click += new System.EventHandler(clickCateg);
                n++;
                     
            }
        }

        // event pentru click pe categorie (resetarea jocului, preluarea noului cuvant);
        private void clickCateg(Object sender, EventArgs e)
        {
            ToolStripMenuItem category = (ToolStripMenuItem)sender;
            
            resetCheckedCategory();
            category.Checked = true;
            groupBox4.Text = "Category: "+category.Text.ToUpper();
            if (category.Text.ToLower() == "all categories")
            {
                cuvant = Cuvant.getRandomWord();
                resetGame();
                makeLabels();
            }
            else
            {
                cuvant = Cuvant.getRandomWordCat(category.Text.ToLower());
                resetGame();
                makeLabels();
            }
        }

        //reseteaza categoria bifata
        private void resetCheckedCategory()
        {
            for (int i = 0; i < nrcat; i++)
            {
                categMenu[i].Checked = false;
            }

        }

        // primul caracter din string uppercase
        private string UppercaseFirst(string s)
        {
            s = s.ToLower();
            if (string.IsNullOrEmpty(s))
            {
                return string.Empty;
            }
            return char.ToUpper(s[0]) + s.Substring(1);
        }

        private void resetKeyboard(string x)
        {
            if (x == "enabled")
            {
                foreach (Button b in btnArray)
                    b.Enabled = true;
            }
            else if (x == "disabled")
            {
                foreach (Button b in btnArray)
                    b.Enabled = false;
            }
        }

        private string getCurentCategory()
        {
            string ca = "";
            foreach (ToolStripMenuItem c in categMenu)
            {
                if (c.Checked == true)
                {
                    ca = c.Text.ToLower();
                }
            }
            if (ca == "all categories")
                ca = "all";
            return ca;
        }

        private void toolStripMenuItem6_Click(object sender, EventArgs e)
        {
           string cuvantSalvat = cuvant;
           string cuvantGhicit = "";
           int  timpSalvat = timp, greseliSalvate = k;

           foreach (Label l in labels)
           {
               cuvantGhicit = cuvantGhicit + l.Text;
           }
           Users save = new Users(Path.GetDirectoryName(Application.ExecutablePath) + "\\usersData.xml");
           int lvl = k - 1;
           save.saveGame(label1.Text, timpSalvat, cuvantGhicit, cuvant, greseliSalvate, literefolosite, lvl);
           MessageBox.Show("save succesfuly");
        }

        public void resetLabesl()
        {
            foreach (Label l in labels)
                l.Dispose();
        }

    }
}
