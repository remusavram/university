namespace Spanzuratoare
{
    partial class SignIn
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
            this.UsersList = new System.Windows.Forms.ListBox();
            this.poza = new System.Windows.Forms.PictureBox();
            this.prev = new System.Windows.Forms.Button();
            this.next = new System.Windows.Forms.Button();
            this.NewUser = new System.Windows.Forms.Button();
            this.DeleteUser = new System.Windows.Forms.Button();
            this.Play = new System.Windows.Forms.Button();
            this.Cancel = new System.Windows.Forms.Button();
            this.Title = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.poza)).BeginInit();
            this.SuspendLayout();
            // 
            // UsersList
            // 
            this.UsersList.FormattingEnabled = true;
            this.UsersList.Location = new System.Drawing.Point(33, 107);
            this.UsersList.Name = "UsersList";
            this.UsersList.Size = new System.Drawing.Size(190, 199);
            this.UsersList.TabIndex = 0;
            this.UsersList.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // poza
            // 
            this.poza.BackColor = System.Drawing.Color.White;
            this.poza.Location = new System.Drawing.Point(306, 107);
            this.poza.Name = "poza";
            this.poza.Size = new System.Drawing.Size(142, 117);
            this.poza.TabIndex = 1;
            this.poza.TabStop = false;
            // 
            // prev
            // 
            this.prev.BackColor = System.Drawing.Color.AntiqueWhite;
            this.prev.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.prev.Location = new System.Drawing.Point(317, 261);
            this.prev.Name = "prev";
            this.prev.Size = new System.Drawing.Size(35, 23);
            this.prev.TabIndex = 2;
            this.prev.Text = "<<";
            this.prev.UseVisualStyleBackColor = false;
            // 
            // next
            // 
            this.next.BackColor = System.Drawing.Color.AntiqueWhite;
            this.next.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.next.Location = new System.Drawing.Point(388, 261);
            this.next.Name = "next";
            this.next.Size = new System.Drawing.Size(32, 23);
            this.next.TabIndex = 3;
            this.next.Text = ">>";
            this.next.UseVisualStyleBackColor = false;
            // 
            // NewUser
            // 
            this.NewUser.Location = new System.Drawing.Point(33, 350);
            this.NewUser.Name = "NewUser";
            this.NewUser.Size = new System.Drawing.Size(75, 23);
            this.NewUser.TabIndex = 4;
            this.NewUser.Text = "New User";
            this.NewUser.UseVisualStyleBackColor = true;
            this.NewUser.Click += new System.EventHandler(this.NewUser_Click);
            // 
            // DeleteUser
            // 
            this.DeleteUser.Enabled = false;
            this.DeleteUser.Location = new System.Drawing.Point(148, 350);
            this.DeleteUser.Name = "DeleteUser";
            this.DeleteUser.Size = new System.Drawing.Size(75, 23);
            this.DeleteUser.TabIndex = 5;
            this.DeleteUser.Text = "Delete User";
            this.DeleteUser.UseVisualStyleBackColor = true;
            this.DeleteUser.Click += new System.EventHandler(this.DeleteUser_Click);
            // 
            // Play
            // 
            this.Play.Enabled = false;
            this.Play.Location = new System.Drawing.Point(259, 350);
            this.Play.Name = "Play";
            this.Play.Size = new System.Drawing.Size(75, 23);
            this.Play.TabIndex = 6;
            this.Play.Text = "Play";
            this.Play.UseVisualStyleBackColor = true;
            this.Play.Click += new System.EventHandler(this.Play_Click);
            // 
            // Cancel
            // 
            this.Cancel.Location = new System.Drawing.Point(372, 350);
            this.Cancel.Name = "Cancel";
            this.Cancel.Size = new System.Drawing.Size(75, 23);
            this.Cancel.TabIndex = 7;
            this.Cancel.Text = "Cancel";
            this.Cancel.UseVisualStyleBackColor = true;
            this.Cancel.Click += new System.EventHandler(this.Cancel_Click);
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Title.ForeColor = System.Drawing.Color.Navy;
            this.Title.Location = new System.Drawing.Point(141, 29);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(228, 16);
            this.Title.TabIndex = 8;
            this.Title.Text = "Welcome to Remus\'s Hangman!";
            // 
            // SignIn
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(497, 440);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.Cancel);
            this.Controls.Add(this.Play);
            this.Controls.Add(this.DeleteUser);
            this.Controls.Add(this.NewUser);
            this.Controls.Add(this.next);
            this.Controls.Add(this.prev);
            this.Controls.Add(this.poza);
            this.Controls.Add(this.UsersList);
            this.Name = "SignIn";
            this.Text = "Sign In";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.poza)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox UsersList;
        private System.Windows.Forms.PictureBox poza;
        private System.Windows.Forms.Button prev;
        private System.Windows.Forms.Button next;
        private System.Windows.Forms.Button NewUser;
        private System.Windows.Forms.Button DeleteUser;
        private System.Windows.Forms.Button Play;
        private System.Windows.Forms.Button Cancel;
        private System.Windows.Forms.Label Title;
    }
}

