namespace Chess
{
    partial class frmDubug
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
            this.lblDir = new System.Windows.Forms.Label();
            this.btnJudge = new System.Windows.Forms.Button();
            this.lblY = new System.Windows.Forms.Label();
            this.lblX = new System.Windows.Forms.Label();
            this.numY = new System.Windows.Forms.NumericUpDown();
            this.numX = new System.Windows.Forms.NumericUpDown();
            this.CboDir = new System.Windows.Forms.ComboBox();
            this.CboColor = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numX)).BeginInit();
            this.SuspendLayout();
            // 
            // lblDir
            // 
            this.lblDir.AutoSize = true;
            this.lblDir.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblDir.Location = new System.Drawing.Point(303, 52);
            this.lblDir.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblDir.Name = "lblDir";
            this.lblDir.Size = new System.Drawing.Size(58, 24);
            this.lblDir.TabIndex = 18;
            this.lblDir.Text = "方向";
            // 
            // btnJudge
            // 
            this.btnJudge.Location = new System.Drawing.Point(216, 459);
            this.btnJudge.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnJudge.Name = "btnJudge";
            this.btnJudge.Size = new System.Drawing.Size(195, 51);
            this.btnJudge.TabIndex = 16;
            this.btnJudge.Text = "获取棋型";
            this.btnJudge.UseVisualStyleBackColor = true;
            this.btnJudge.Click += new System.EventHandler(this.btnJudge_Click);
            // 
            // lblY
            // 
            this.lblY.AutoSize = true;
            this.lblY.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblY.Location = new System.Drawing.Point(46, 226);
            this.lblY.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(82, 24);
            this.lblY.TabIndex = 15;
            this.lblY.Text = "纵坐标";
            // 
            // lblX
            // 
            this.lblX.AutoSize = true;
            this.lblX.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lblX.Location = new System.Drawing.Point(46, 52);
            this.lblX.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(82, 24);
            this.lblX.TabIndex = 14;
            this.lblX.Text = "横坐标";
            // 
            // numY
            // 
            this.numY.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.numY.Location = new System.Drawing.Point(51, 300);
            this.numY.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.numY.Name = "numY";
            this.numY.Size = new System.Drawing.Size(112, 35);
            this.numY.TabIndex = 13;
            // 
            // numX
            // 
            this.numX.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.numX.Location = new System.Drawing.Point(50, 125);
            this.numX.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.numX.Name = "numX";
            this.numX.Size = new System.Drawing.Size(112, 35);
            this.numX.TabIndex = 12;
            // 
            // CboDir
            // 
            this.CboDir.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CboDir.FormattingEnabled = true;
            this.CboDir.Items.AddRange(new object[] {
            "垂直方向",
            "水平方向",
            "左斜线方向",
            "右斜线方向"});
            this.CboDir.Location = new System.Drawing.Point(308, 128);
            this.CboDir.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.CboDir.Name = "CboDir";
            this.CboDir.Size = new System.Drawing.Size(168, 32);
            this.CboDir.TabIndex = 19;
            // 
            // CboColor
            // 
            this.CboColor.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.CboColor.FormattingEnabled = true;
            this.CboColor.Items.AddRange(new object[] {
            "黑色",
            "白色"});
            this.CboColor.Location = new System.Drawing.Point(308, 298);
            this.CboColor.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.CboColor.Name = "CboColor";
            this.CboColor.Size = new System.Drawing.Size(168, 32);
            this.CboColor.TabIndex = 20;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(303, 226);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(106, 24);
            this.label1.TabIndex = 21;
            this.label1.Text = "棋子颜色";
            // 
            // frmDubug
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(638, 628);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CboColor);
            this.Controls.Add(this.CboDir);
            this.Controls.Add(this.lblDir);
            this.Controls.Add(this.btnJudge);
            this.Controls.Add(this.lblY);
            this.Controls.Add(this.lblX);
            this.Controls.Add(this.numY);
            this.Controls.Add(this.numX);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "frmDubug";
            this.Text = "调试窗体";
            ((System.ComponentModel.ISupportInitialize)(this.numY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numX)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblDir;
        private System.Windows.Forms.Button btnJudge;
        private System.Windows.Forms.Label lblY;
        private System.Windows.Forms.Label lblX;
        private System.Windows.Forms.NumericUpDown numY;
        private System.Windows.Forms.NumericUpDown numX;
        private System.Windows.Forms.ComboBox CboDir;
        private System.Windows.Forms.ComboBox CboColor;
        private System.Windows.Forms.Label label1;
    }
}