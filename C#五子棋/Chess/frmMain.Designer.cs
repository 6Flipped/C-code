namespace Chess
{
    partial class frmMain
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
            this.menu = new System.Windows.Forms.MenuStrip();
            this.新游戏ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemNewGame = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemDebug = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemExit = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.menu.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.GripStyle = System.Windows.Forms.ToolStripGripStyle.Visible;
            this.menu.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.新游戏ToolStripMenuItem,
            this.menuItemAbout});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.menu.Size = new System.Drawing.Size(779, 28);
            this.menu.TabIndex = 12;
            this.menu.Text = "menuStrip1";
            // 
            // 新游戏ToolStripMenuItem
            // 
            this.新游戏ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItemNewGame,
            this.menuItemDebug,
            this.menuItemExit});
            this.新游戏ToolStripMenuItem.Name = "新游戏ToolStripMenuItem";
            this.新游戏ToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.新游戏ToolStripMenuItem.Text = "游戏";
            // 
            // menuItemNewGame
            // 
            this.menuItemNewGame.Name = "menuItemNewGame";
            this.menuItemNewGame.Size = new System.Drawing.Size(152, 26);
            this.menuItemNewGame.Text = "新游戏";
            this.menuItemNewGame.Click += new System.EventHandler(this.menuItemNewGame_Click);
            // 
            // menuItemDebug
            // 
            this.menuItemDebug.Name = "menuItemDebug";
            this.menuItemDebug.Size = new System.Drawing.Size(152, 26);
            this.menuItemDebug.Text = "测试窗体";
            this.menuItemDebug.Click += new System.EventHandler(this.menuItemDebug_Click);
            // 
            // menuItemExit
            // 
            this.menuItemExit.Name = "menuItemExit";
            this.menuItemExit.Size = new System.Drawing.Size(152, 26);
            this.menuItemExit.Text = "退出";
            this.menuItemExit.Click += new System.EventHandler(this.menuItemExit_Click);
            // 
            // menuItemAbout
            // 
            this.menuItemAbout.Name = "menuItemAbout";
            this.menuItemAbout.Size = new System.Drawing.Size(53, 24);
            this.menuItemAbout.Text = "关于";
            this.menuItemAbout.Click += new System.EventHandler(this.menuItemAbout_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(779, 702);
            this.Controls.Add(this.menu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MainMenuStrip = this.menu;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "五子棋小游戏";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu;
        private System.Windows.Forms.ToolStripMenuItem 新游戏ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem menuItemNewGame;
        private System.Windows.Forms.ToolStripMenuItem menuItemExit;
        private System.Windows.Forms.ToolStripMenuItem menuItemDebug;
        private System.Windows.Forms.ToolStripMenuItem menuItemAbout;







    }
}