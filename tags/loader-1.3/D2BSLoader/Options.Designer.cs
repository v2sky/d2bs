﻿namespace D2BSLoader
{
	partial class Options
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
			if(disposing && (components != null))
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
			System.Windows.Forms.Button OK;
			System.Windows.Forms.Button Cancel;
			System.Windows.Forms.Label label1;
			System.Windows.Forms.Label label2;
			System.Windows.Forms.Label label3;
			System.Windows.Forms.Button FindPath;
			System.Windows.Forms.Button FindExe;
			System.Windows.Forms.Label label4;
			System.Windows.Forms.Button FindDll;
			this.Exe = new System.Windows.Forms.TextBox();
			this.Args = new System.Windows.Forms.TextBox();
			this.Path = new System.Windows.Forms.TextBox();
			this.DLL = new System.Windows.Forms.TextBox();
			OK = new System.Windows.Forms.Button();
			Cancel = new System.Windows.Forms.Button();
			label1 = new System.Windows.Forms.Label();
			label2 = new System.Windows.Forms.Label();
			label3 = new System.Windows.Forms.Label();
			FindPath = new System.Windows.Forms.Button();
			FindExe = new System.Windows.Forms.Button();
			label4 = new System.Windows.Forms.Label();
			FindDll = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// OK
			// 
			OK.Location = new System.Drawing.Point(12, 168);
			OK.Name = "OK";
			OK.Size = new System.Drawing.Size(75, 23);
			OK.TabIndex = 7;
			OK.Text = "OK";
			OK.UseVisualStyleBackColor = true;
			OK.Click += new System.EventHandler(this.OK_Click);
			// 
			// Cancel
			// 
			Cancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			Cancel.Location = new System.Drawing.Point(146, 168);
			Cancel.Name = "Cancel";
			Cancel.Size = new System.Drawing.Size(75, 23);
			Cancel.TabIndex = 8;
			Cancel.Text = "Cancel";
			Cancel.UseVisualStyleBackColor = true;
			Cancel.Click += new System.EventHandler(this.Cancel_Click);
			// 
			// label1
			// 
			label1.AutoSize = true;
			label1.Location = new System.Drawing.Point(12, 9);
			label1.Name = "label1";
			label1.Size = new System.Drawing.Size(71, 13);
			label1.TabIndex = 9;
			label1.Text = "Diablo II Path";
			// 
			// label2
			// 
			label2.AutoSize = true;
			label2.Location = new System.Drawing.Point(12, 48);
			label2.Name = "label2";
			label2.Size = new System.Drawing.Size(102, 13);
			label2.TabIndex = 10;
			label2.Text = "Diablo II Executable";
			// 
			// label3
			// 
			label3.AutoSize = true;
			label3.Location = new System.Drawing.Point(12, 126);
			label3.Name = "label3";
			label3.Size = new System.Drawing.Size(57, 13);
			label3.TabIndex = 12;
			label3.Text = "Arguments";
			// 
			// FindPath
			// 
			FindPath.Location = new System.Drawing.Point(197, 24);
			FindPath.Name = "FindPath";
			FindPath.Size = new System.Drawing.Size(24, 21);
			FindPath.TabIndex = 1;
			FindPath.Text = "...";
			FindPath.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			FindPath.UseVisualStyleBackColor = true;
			FindPath.Click += new System.EventHandler(this.FindPath_Click);
			// 
			// FindExe
			// 
			FindExe.Location = new System.Drawing.Point(197, 63);
			FindExe.Name = "FindExe";
			FindExe.Size = new System.Drawing.Size(24, 20);
			FindExe.TabIndex = 3;
			FindExe.Text = "...";
			FindExe.UseVisualStyleBackColor = true;
			FindExe.Click += new System.EventHandler(this.FindExe_Click);
			// 
			// label4
			// 
			label4.AutoSize = true;
			label4.Location = new System.Drawing.Point(12, 87);
			label4.Name = "label4";
			label4.Size = new System.Drawing.Size(58, 13);
			label4.TabIndex = 11;
			label4.Text = "D2BS DLL";
			// 
			// FindDll
			// 
			FindDll.Location = new System.Drawing.Point(197, 102);
			FindDll.Name = "FindDll";
			FindDll.Size = new System.Drawing.Size(24, 20);
			FindDll.TabIndex = 5;
			FindDll.Text = "...";
			FindDll.UseVisualStyleBackColor = true;
			FindDll.Click += new System.EventHandler(this.FindDll_Click);
			// 
			// Exe
			// 
			this.Exe.Location = new System.Drawing.Point(12, 64);
			this.Exe.Name = "Exe";
			this.Exe.ReadOnly = true;
			this.Exe.Size = new System.Drawing.Size(179, 20);
			this.Exe.TabIndex = 2;
			// 
			// Args
			// 
			this.Args.Location = new System.Drawing.Point(12, 142);
			this.Args.Name = "Args";
			this.Args.Size = new System.Drawing.Size(206, 20);
			this.Args.TabIndex = 6;
			// 
			// Path
			// 
			this.Path.Location = new System.Drawing.Point(12, 25);
			this.Path.Name = "Path";
			this.Path.ReadOnly = true;
			this.Path.Size = new System.Drawing.Size(179, 20);
			this.Path.TabIndex = 0;
			// 
			// DLL
			// 
			this.DLL.Location = new System.Drawing.Point(12, 103);
			this.DLL.Name = "DLL";
			this.DLL.ReadOnly = true;
			this.DLL.Size = new System.Drawing.Size(179, 20);
			this.DLL.TabIndex = 4;
			// 
			// Options
			// 
			this.AcceptButton = OK;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.CancelButton = Cancel;
			this.ClientSize = new System.Drawing.Size(230, 202);
			this.ControlBox = false;
			this.Controls.Add(FindDll);
			this.Controls.Add(this.DLL);
			this.Controls.Add(label4);
			this.Controls.Add(FindExe);
			this.Controls.Add(this.Path);
			this.Controls.Add(FindPath);
			this.Controls.Add(this.Args);
			this.Controls.Add(this.Exe);
			this.Controls.Add(label3);
			this.Controls.Add(label2);
			this.Controls.Add(label1);
			this.Controls.Add(Cancel);
			this.Controls.Add(OK);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Name = "Options";
			this.ShowIcon = false;
			this.ShowInTaskbar = false;
			this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Options";
			this.TopMost = true;
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox Exe;
		private System.Windows.Forms.TextBox Args;
		private System.Windows.Forms.TextBox Path;
		private System.Windows.Forms.TextBox DLL;
	}
}