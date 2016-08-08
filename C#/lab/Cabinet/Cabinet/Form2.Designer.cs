namespace Cabinet
{
    partial class Form2
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
            this.cabinetDataSet = new Cabinet.cabinetDataSet();
            this.mediciBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.mediciTableAdapter = new Cabinet.cabinetDataSetTableAdapters.mediciTableAdapter();
            this.tableAdapterManager = new Cabinet.cabinetDataSetTableAdapters.TableAdapterManager();
            this.cabinetDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.interventii = new System.Windows.Forms.ComboBox();
            this.dictInterventiiBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.cabinetDataSet2 = new Cabinet.cabinetDataSet2();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.interventiiBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.interventiiTableAdapter = new Cabinet.cabinetDataSetTableAdapters.interventiiTableAdapter();
            this.dictInterventiiTableAdapter = new Cabinet.cabinetDataSet2TableAdapters.dictInterventiiTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.mediciBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dictInterventiiBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.interventiiBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // cabinetDataSet
            // 
            this.cabinetDataSet.DataSetName = "cabinetDataSet";
            this.cabinetDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // mediciBindingSource
            // 
            this.mediciBindingSource.DataMember = "medici";
            this.mediciBindingSource.DataSource = this.cabinetDataSet;
            // 
            // mediciTableAdapter
            // 
            this.mediciTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.interventiiTableAdapter = null;
            this.tableAdapterManager.listaPreturiTableAdapter = null;
            this.tableAdapterManager.mediciTableAdapter = this.mediciTableAdapter;
            this.tableAdapterManager.pacientiTableAdapter = null;
            this.tableAdapterManager.programariTableAdapter = null;
            this.tableAdapterManager.UpdateOrder = Cabinet.cabinetDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // cabinetDataSetBindingSource
            // 
            this.cabinetDataSetBindingSource.DataSource = this.cabinetDataSet;
            this.cabinetDataSetBindingSource.Position = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(37, 44);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(200, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Selecteaza denumirea interventiei si data";
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.Location = new System.Drawing.Point(278, 85);
            this.monthCalendar1.MaxSelectionCount = 1;
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.TabIndex = 8;
            // 
            // interventii
            // 
            this.interventii.DataSource = this.dictInterventiiBindingSource;
            this.interventii.DisplayMember = "denumire";
            this.interventii.FormattingEnabled = true;
            this.interventii.Location = new System.Drawing.Point(40, 85);
            this.interventii.Name = "interventii";
            this.interventii.Size = new System.Drawing.Size(205, 21);
            this.interventii.TabIndex = 7;
            // 
            // dictInterventiiBindingSource
            // 
            this.dictInterventiiBindingSource.DataMember = "dictInterventii";
            this.dictInterventiiBindingSource.DataSource = this.cabinetDataSet2;
            // 
            // cabinetDataSet2
            // 
            this.cabinetDataSet2.DataSetName = "cabinetDataSet2";
            this.cabinetDataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(40, 259);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(465, 112);
            this.dataGridView1.TabIndex = 9;
            this.dataGridView1.Visible = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(40, 154);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 10;
            this.button1.Text = "Afiseaza";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.AfisareInterventiiVechi);
            // 
            // interventiiBindingSource
            // 
            this.interventiiBindingSource.DataMember = "interventii";
            this.interventiiBindingSource.DataSource = this.cabinetDataSetBindingSource;
            // 
            // interventiiTableAdapter
            // 
            this.interventiiTableAdapter.ClearBeforeFill = true;
            // 
            // dictInterventiiTableAdapter
            // 
            this.dictInterventiiTableAdapter.ClearBeforeFill = true;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(561, 383);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.monthCalendar1);
            this.Controls.Add(this.interventii);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.Text = "Interventii";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.mediciBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dictInterventiiBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cabinetDataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.interventiiBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private cabinetDataSet cabinetDataSet;
        private System.Windows.Forms.BindingSource mediciBindingSource;
        private cabinetDataSetTableAdapters.mediciTableAdapter mediciTableAdapter;
        private cabinetDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.BindingSource cabinetDataSetBindingSource;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MonthCalendar monthCalendar1;
        private System.Windows.Forms.ComboBox interventii;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.BindingSource interventiiBindingSource;
        private cabinetDataSetTableAdapters.interventiiTableAdapter interventiiTableAdapter;
        private cabinetDataSet2 cabinetDataSet2;
        private System.Windows.Forms.BindingSource dictInterventiiBindingSource;
        private cabinetDataSet2TableAdapters.dictInterventiiTableAdapter dictInterventiiTableAdapter;
    }
}