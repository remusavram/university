namespace Cabinet
{
    partial class Form8
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
            this.components = new System.ComponentModel.Container();
            this.label2 = new System.Windows.Forms.Label();
            this.comboMedici = new System.Windows.Forms.ComboBox();
            this.mediciBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.cabinetDataSet3 = new Cabinet.cabinetDataSet3();
            this.label1 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.mediciTableAdapter = new Cabinet.cabinetDataSet3TableAdapters.mediciTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.mediciBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(35, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(36, 13);
            this.label2.TabIndex = 12;
            this.label2.Text = "Medic";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // comboMedici
            // 
            this.comboMedici.DataSource = this.mediciBindingSource;
            this.comboMedici.DisplayMember = "nume";
            this.comboMedici.FormattingEnabled = true;
            this.comboMedici.Location = new System.Drawing.Point(95, 48);
            this.comboMedici.Name = "comboMedici";
            this.comboMedici.Size = new System.Drawing.Size(205, 21);
            this.comboMedici.TabIndex = 11;
            this.comboMedici.ValueMember = "idMedic";
            this.comboMedici.SelectedIndexChanged += new System.EventHandler(this.comboMedici_SelectedIndexChanged);
            // 
            // mediciBindingSource
            // 
            this.mediciBindingSource.DataMember = "medici";
            this.mediciBindingSource.DataSource = this.cabinetDataSet3;
            this.mediciBindingSource.CurrentChanged += new System.EventHandler(this.mediciBindingSource_CurrentChanged);
            // 
            // cabinetDataSet3
            // 
            this.cabinetDataSet3.DataSetName = "cabinetDataSet3";
            this.cabinetDataSet3.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.DarkRed;
            this.label1.Location = new System.Drawing.Point(35, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(209, 17);
            this.label1.TabIndex = 10;
            this.label1.Text = "Castigul lunar al unui medic";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(38, 84);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(458, 290);
            this.dataGridView1.TabIndex = 9;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // mediciTableAdapter
            // 
            this.mediciTableAdapter.ClearBeforeFill = true;
            // 
            // Form8
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(588, 386);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboMedici);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form8";
            this.Text = "Castigul unui medic";
            this.Load += new System.EventHandler(this.Form8_Load);
            ((System.ComponentModel.ISupportInitialize)(this.mediciBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboMedici;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private cabinetDataSet3 cabinetDataSet3;
        private System.Windows.Forms.BindingSource mediciBindingSource;
        private cabinetDataSet3TableAdapters.mediciTableAdapter mediciTableAdapter;
    }
}