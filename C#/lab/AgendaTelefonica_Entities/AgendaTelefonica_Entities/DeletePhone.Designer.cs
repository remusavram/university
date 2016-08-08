namespace AgendaTelefonica_Entities
{
    partial class DeletePhone
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
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.listBoxTelefoane = new System.Windows.Forms.ListBox();
            this.comboBoxPersons = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // button2
            // 
            this.button2.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.button2.Location = new System.Drawing.Point(300, 180);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(60, 23);
            this.button2.TabIndex = 7;
            this.button2.Text = "Gata";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(90, 181);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(61, 23);
            this.button1.TabIndex = 6;
            this.button1.Text = "Sterge";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // listBoxTelefoane
            // 
            this.listBoxTelefoane.FormattingEnabled = true;
            this.listBoxTelefoane.Location = new System.Drawing.Point(12, 57);
            this.listBoxTelefoane.Name = "listBoxTelefoane";
            this.listBoxTelefoane.Size = new System.Drawing.Size(379, 95);
            this.listBoxTelefoane.TabIndex = 5;
            // 
            // comboBoxPersons
            // 
            this.comboBoxPersons.FormattingEnabled = true;
            this.comboBoxPersons.Location = new System.Drawing.Point(12, 12);
            this.comboBoxPersons.Name = "comboBoxPersons";
            this.comboBoxPersons.Size = new System.Drawing.Size(379, 21);
            this.comboBoxPersons.TabIndex = 4;
            this.comboBoxPersons.Click += new System.EventHandler(this.comboBoxPersoane_SelectedIndexChanged);
            // 
            // DeletePhone
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(424, 262);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.listBoxTelefoane);
            this.Controls.Add(this.comboBoxPersons);
            this.Name = "DeletePhone";
            this.Text = "DeletePhone";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ListBox listBoxTelefoane;
        private System.Windows.Forms.ComboBox comboBoxPersons;
    }
}