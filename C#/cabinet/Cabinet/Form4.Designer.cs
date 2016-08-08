namespace Cabinet
{
    partial class Form4
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
            this.label3 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.pacientiBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.cabinetDataSet3 = new Cabinet.cabinetDataSet3();
            this.pacientiBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.cabinetDataSet1 = new Cabinet.cabinetDataSet1();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.programariBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.cabinetDataSet = new Cabinet.cabinetDataSet();
            this.pacientiBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.pacientiTableAdapter = new Cabinet.cabinetDataSetTableAdapters.pacientiTableAdapter();
            this.programariTableAdapter = new Cabinet.cabinetDataSetTableAdapters.programariTableAdapter();
            this.pacientiTableAdapter1 = new Cabinet.cabinetDataSet1TableAdapters.pacientiTableAdapter();
            this.pacientiTableAdapter2 = new Cabinet.cabinetDataSet3TableAdapters.pacientiTableAdapter();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.programariBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Pacient";
            // 
            // comboBox1
            // 
            this.comboBox1.DataSource = this.pacientiBindingSource2;
            this.comboBox1.DisplayMember = "nume";
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(69, 45);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(205, 21);
            this.comboBox1.TabIndex = 8;
            this.comboBox1.ValueMember = "cnp";
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.AfisInterventiiPacienti);
            // 
            // pacientiBindingSource2
            // 
            this.pacientiBindingSource2.DataMember = "pacienti";
            this.pacientiBindingSource2.DataSource = this.cabinetDataSet3;
            // 
            // cabinetDataSet3
            // 
            this.cabinetDataSet3.DataSetName = "cabinetDataSet3";
            this.cabinetDataSet3.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // pacientiBindingSource1
            // 
            this.pacientiBindingSource1.DataMember = "pacienti";
            this.pacientiBindingSource1.DataSource = this.cabinetDataSet1;
            // 
            // cabinetDataSet1
            // 
            this.cabinetDataSet1.DataSetName = "cabinetDataSet1";
            this.cabinetDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 72);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(684, 290);
            this.dataGridView1.TabIndex = 7;
            // 
            // programariBindingSource
            // 
            this.programariBindingSource.DataMember = "programari";
            this.programariBindingSource.DataSource = this.cabinetDataSet;
            // 
            // cabinetDataSet
            // 
            this.cabinetDataSet.DataSetName = "cabinetDataSet";
            this.cabinetDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // pacientiBindingSource
            // 
            this.pacientiBindingSource.DataMember = "pacienti";
            this.pacientiBindingSource.DataSource = this.cabinetDataSet;
            // 
            // pacientiTableAdapter
            // 
            this.pacientiTableAdapter.ClearBeforeFill = true;
            // 
            // programariTableAdapter
            // 
            this.programariTableAdapter.ClearBeforeFill = true;
            // 
            // pacientiTableAdapter1
            // 
            this.pacientiTableAdapter1.ClearBeforeFill = true;
            // 
            // pacientiTableAdapter2
            // 
            this.pacientiTableAdapter2.ClearBeforeFill = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(325, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "CNP";
            // 
            // Form4
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(723, 374);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form4";
            this.Text = "Lista interventiilor unui pacient";
            this.Load += new System.EventHandler(this.Form4_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.programariBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pacientiBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private cabinetDataSet cabinetDataSet;
        private System.Windows.Forms.BindingSource pacientiBindingSource;
        private cabinetDataSetTableAdapters.pacientiTableAdapter pacientiTableAdapter;
        private System.Windows.Forms.BindingSource programariBindingSource;
        private cabinetDataSetTableAdapters.programariTableAdapter programariTableAdapter;
        private cabinetDataSet1 cabinetDataSet1;
        private System.Windows.Forms.BindingSource pacientiBindingSource1;
        private cabinetDataSet1TableAdapters.pacientiTableAdapter pacientiTableAdapter1;
        private cabinetDataSet3 cabinetDataSet3;
        private System.Windows.Forms.BindingSource pacientiBindingSource2;
        private cabinetDataSet3TableAdapters.pacientiTableAdapter pacientiTableAdapter2;
        private System.Windows.Forms.Label label2;
    }
}