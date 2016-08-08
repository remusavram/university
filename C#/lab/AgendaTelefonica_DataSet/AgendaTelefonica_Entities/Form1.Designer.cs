namespace AgendaTelefonica_Entities
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.vizualizareToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.persoaneCareNuAuTelefonToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.persoaneSiTelefoaneToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.adaugareToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.persoaneToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.telefoanePentruOPersoanaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stergereToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.persoaneToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.telefoanePentruOPersoanaToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.modificareToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.datePersoaneToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.telefoaneToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.vizualizareToolStripMenuItem,
            this.adaugareToolStripMenuItem,
            this.stergereToolStripMenuItem,
            this.modificareToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(531, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // vizualizareToolStripMenuItem
            // 
            this.vizualizareToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toateToolStripMenuItem,
            this.persoaneCareNuAuTelefonToolStripMenuItem,
            this.persoaneSiTelefoaneToolStripMenuItem});
            this.vizualizareToolStripMenuItem.Name = "vizualizareToolStripMenuItem";
            this.vizualizareToolStripMenuItem.Size = new System.Drawing.Size(74, 20);
            this.vizualizareToolStripMenuItem.Text = "Vizualizare";
            // 
            // toateToolStripMenuItem
            // 
            this.toateToolStripMenuItem.Name = "toateToolStripMenuItem";
            this.toateToolStripMenuItem.Size = new System.Drawing.Size(220, 22);
            this.toateToolStripMenuItem.Text = "Toate persoanele";
            this.toateToolStripMenuItem.Click += new System.EventHandler(this.toateToolStripMenuItem_Click);
            // 
            // persoaneCareNuAuTelefonToolStripMenuItem
            // 
            this.persoaneCareNuAuTelefonToolStripMenuItem.Name = "persoaneCareNuAuTelefonToolStripMenuItem";
            this.persoaneCareNuAuTelefonToolStripMenuItem.Size = new System.Drawing.Size(220, 22);
            this.persoaneCareNuAuTelefonToolStripMenuItem.Text = "Persoane care nu au telefon";
            this.persoaneCareNuAuTelefonToolStripMenuItem.Click += new System.EventHandler(this.persoaneCareNuAuTelefonToolStripMenuItem_Click);
            // 
            // persoaneSiTelefoaneToolStripMenuItem
            // 
            this.persoaneSiTelefoaneToolStripMenuItem.Name = "persoaneSiTelefoaneToolStripMenuItem";
            this.persoaneSiTelefoaneToolStripMenuItem.Size = new System.Drawing.Size(220, 22);
            this.persoaneSiTelefoaneToolStripMenuItem.Text = "Persoane si telefoane";
            this.persoaneSiTelefoaneToolStripMenuItem.Click += new System.EventHandler(this.persoaneSiTelefoaneToolStripMenuItem_Click);
            // 
            // adaugareToolStripMenuItem
            // 
            this.adaugareToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.persoaneToolStripMenuItem,
            this.telefoanePentruOPersoanaToolStripMenuItem});
            this.adaugareToolStripMenuItem.Name = "adaugareToolStripMenuItem";
            this.adaugareToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.adaugareToolStripMenuItem.Text = "Adaugare";
            // 
            // persoaneToolStripMenuItem
            // 
            this.persoaneToolStripMenuItem.Name = "persoaneToolStripMenuItem";
            this.persoaneToolStripMenuItem.Size = new System.Drawing.Size(225, 22);
            this.persoaneToolStripMenuItem.Text = "Persoane";
            this.persoaneToolStripMenuItem.Click += new System.EventHandler(this.persoaneToolStripMenuItem_Click);
            // 
            // telefoanePentruOPersoanaToolStripMenuItem
            // 
            this.telefoanePentruOPersoanaToolStripMenuItem.Name = "telefoanePentruOPersoanaToolStripMenuItem";
            this.telefoanePentruOPersoanaToolStripMenuItem.Size = new System.Drawing.Size(225, 22);
            this.telefoanePentruOPersoanaToolStripMenuItem.Text = "Telefoane pentru o persoana";
            this.telefoanePentruOPersoanaToolStripMenuItem.Click += new System.EventHandler(this.telefoanePentruOPersoanaToolStripMenuItem_Click);
            // 
            // stergereToolStripMenuItem
            // 
            this.stergereToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.persoaneToolStripMenuItem1,
            this.telefoanePentruOPersoanaToolStripMenuItem1});
            this.stergereToolStripMenuItem.Name = "stergereToolStripMenuItem";
            this.stergereToolStripMenuItem.Size = new System.Drawing.Size(62, 20);
            this.stergereToolStripMenuItem.Text = "Stergere";
            // 
            // persoaneToolStripMenuItem1
            // 
            this.persoaneToolStripMenuItem1.Name = "persoaneToolStripMenuItem1";
            this.persoaneToolStripMenuItem1.Size = new System.Drawing.Size(225, 22);
            this.persoaneToolStripMenuItem1.Text = "Persoane";
            this.persoaneToolStripMenuItem1.Click += new System.EventHandler(this.persoaneToolStripMenuItem1_Click);
            // 
            // telefoanePentruOPersoanaToolStripMenuItem1
            // 
            this.telefoanePentruOPersoanaToolStripMenuItem1.Name = "telefoanePentruOPersoanaToolStripMenuItem1";
            this.telefoanePentruOPersoanaToolStripMenuItem1.Size = new System.Drawing.Size(225, 22);
            this.telefoanePentruOPersoanaToolStripMenuItem1.Text = "Telefoane pentru o persoana";
            this.telefoanePentruOPersoanaToolStripMenuItem1.Click += new System.EventHandler(this.telefoanePentruOPersoanaToolStripMenuItem1_Click);
            // 
            // modificareToolStripMenuItem
            // 
            this.modificareToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.datePersoaneToolStripMenuItem,
            this.telefoaneToolStripMenuItem});
            this.modificareToolStripMenuItem.Name = "modificareToolStripMenuItem";
            this.modificareToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
            this.modificareToolStripMenuItem.Text = "Modificare";
            // 
            // datePersoaneToolStripMenuItem
            // 
            this.datePersoaneToolStripMenuItem.Name = "datePersoaneToolStripMenuItem";
            this.datePersoaneToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.datePersoaneToolStripMenuItem.Text = "Date persoane";
            this.datePersoaneToolStripMenuItem.Click += new System.EventHandler(this.datePersoaneToolStripMenuItem_Click);
            // 
            // telefoaneToolStripMenuItem
            // 
            this.telefoaneToolStripMenuItem.Name = "telefoaneToolStripMenuItem";
            this.telefoaneToolStripMenuItem.Size = new System.Drawing.Size(149, 22);
            this.telefoaneToolStripMenuItem.Text = "Telefoane";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(531, 262);
            this.Controls.Add(this.menuStrip1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem vizualizareToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem persoaneCareNuAuTelefonToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem persoaneSiTelefoaneToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem adaugareToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem persoaneToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem telefoanePentruOPersoanaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stergereToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem persoaneToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem telefoanePentruOPersoanaToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem modificareToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem datePersoaneToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem telefoaneToolStripMenuItem;
    }
}

