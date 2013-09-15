namespace WindowsFormsApplication1
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
            this.components = new System.ComponentModel.Container();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label7 = new System.Windows.Forms.Label();
            this.btMonitoreo = new System.Windows.Forms.Button();
            this.lbCNT = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.lbREF = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.lbWRK = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.lbVCTR = new System.Windows.Forms.Label();
            this.lbISIG = new System.Windows.Forms.Label();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.etVCTR = new System.Windows.Forms.Label();
            this.btLectura = new System.Windows.Forms.Button();
            this.lbMsgRx = new System.Windows.Forms.ListBox();
            this.etREF = new System.Windows.Forms.Label();
            this.etISIG = new System.Windows.Forms.Label();
            this.etCNT = new System.Windows.Forms.Label();
            this.etWRK = new System.Windows.Forms.Label();
            this.btGuardar = new System.Windows.Forms.Button();
            this.btStop232 = new System.Windows.Forms.Button();
            this.btInit232 = new System.Windows.Forms.Button();
            this.pbComm = new System.Windows.Forms.ProgressBar();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.rbFemenino = new System.Windows.Forms.RadioButton();
            this.rbMasculino = new System.Windows.Forms.RadioButton();
            this.lbSexo = new System.Windows.Forms.Label();
            this.tbEdad = new System.Windows.Forms.TextBox();
            this.lbEdad = new System.Windows.Forms.Label();
            this.tbPaciente = new System.Windows.Forms.TextBox();
            this.lbPaciente = new System.Windows.Forms.Label();
            this.tmrRequest = new System.Windows.Forms.Timer(this.components);
            this.tmrLectura = new System.Windows.Forms.Timer(this.components);
            this.tabControl.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialPort
            // 
            this.serialPort.BaudRate = 19200;
            this.serialPort.PortName = "COM3";
            this.serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort_DataReceived);
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tabPage1);
            this.tabControl.Controls.Add(this.tabPage2);
            this.tabControl.Location = new System.Drawing.Point(12, 12);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(435, 343);
            this.tabControl.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.tabControl1);
            this.tabPage1.Controls.Add(this.btGuardar);
            this.tabPage1.Controls.Add(this.btStop232);
            this.tabPage1.Controls.Add(this.btInit232);
            this.tabPage1.Controls.Add(this.pbComm);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(427, 317);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Datos";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Location = new System.Drawing.Point(9, 74);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(412, 201);
            this.tabControl1.TabIndex = 15;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.label7);
            this.tabPage3.Controls.Add(this.btMonitoreo);
            this.tabPage3.Controls.Add(this.lbCNT);
            this.tabPage3.Controls.Add(this.label5);
            this.tabPage3.Controls.Add(this.lbREF);
            this.tabPage3.Controls.Add(this.label3);
            this.tabPage3.Controls.Add(this.lbWRK);
            this.tabPage3.Controls.Add(this.label2);
            this.tabPage3.Controls.Add(this.label1);
            this.tabPage3.Controls.Add(this.lbVCTR);
            this.tabPage3.Controls.Add(this.lbISIG);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(404, 175);
            this.tabPage3.TabIndex = 0;
            this.tabPage3.Text = "Monitoreo";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(288, 141);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 17);
            this.label7.TabIndex = 9;
            this.label7.Text = "CNT";
            // 
            // btMonitoreo
            // 
            this.btMonitoreo.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btMonitoreo.Location = new System.Drawing.Point(323, 15);
            this.btMonitoreo.Name = "btMonitoreo";
            this.btMonitoreo.Size = new System.Drawing.Size(75, 63);
            this.btMonitoreo.TabIndex = 15;
            this.btMonitoreo.Text = "Start";
            this.btMonitoreo.UseVisualStyleBackColor = true;
            this.btMonitoreo.Visible = false;
            this.btMonitoreo.Click += new System.EventHandler(this.btMonitoreo_Click);
            // 
            // lbCNT
            // 
            this.lbCNT.AutoSize = true;
            this.lbCNT.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbCNT.Location = new System.Drawing.Point(257, 102);
            this.lbCNT.Name = "lbCNT";
            this.lbCNT.Size = new System.Drawing.Size(87, 39);
            this.lbCNT.TabIndex = 8;
            this.lbCNT.Text = "0.00";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(155, 141);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(35, 17);
            this.label5.TabIndex = 7;
            this.label5.Text = "REF";
            // 
            // lbREF
            // 
            this.lbREF.AutoSize = true;
            this.lbREF.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbREF.Location = new System.Drawing.Point(126, 102);
            this.lbREF.Name = "lbREF";
            this.lbREF.Size = new System.Drawing.Size(87, 39);
            this.lbREF.TabIndex = 6;
            this.lbREF.Text = "0.00";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(33, 141);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 17);
            this.label3.TabIndex = 5;
            this.label3.Text = "VGND";
            // 
            // lbWRK
            // 
            this.lbWRK.AutoSize = true;
            this.lbWRK.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbWRK.Location = new System.Drawing.Point(6, 102);
            this.lbWRK.Name = "lbWRK";
            this.lbWRK.Size = new System.Drawing.Size(87, 39);
            this.lbWRK.TabIndex = 4;
            this.lbWRK.Text = "0.00";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(211, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Glucosa";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(48, 78);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "ISIG";
            // 
            // lbVCTR
            // 
            this.lbVCTR.AutoSize = true;
            this.lbVCTR.Font = new System.Drawing.Font("Microsoft Sans Serif", 40F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbVCTR.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lbVCTR.Location = new System.Drawing.Point(168, 15);
            this.lbVCTR.Name = "lbVCTR";
            this.lbVCTR.Size = new System.Drawing.Size(136, 63);
            this.lbVCTR.TabIndex = 1;
            this.lbVCTR.Text = "0.00";
            // 
            // lbISIG
            // 
            this.lbISIG.AutoSize = true;
            this.lbISIG.Font = new System.Drawing.Font("Microsoft Sans Serif", 40F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbISIG.Location = new System.Drawing.Point(6, 15);
            this.lbISIG.Name = "lbISIG";
            this.lbISIG.Size = new System.Drawing.Size(136, 63);
            this.lbISIG.TabIndex = 0;
            this.lbISIG.Text = "0.00";
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.etVCTR);
            this.tabPage4.Controls.Add(this.btLectura);
            this.tabPage4.Controls.Add(this.lbMsgRx);
            this.tabPage4.Controls.Add(this.etREF);
            this.tabPage4.Controls.Add(this.etISIG);
            this.tabPage4.Controls.Add(this.etCNT);
            this.tabPage4.Controls.Add(this.etWRK);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(404, 175);
            this.tabPage4.TabIndex = 1;
            this.tabPage4.Text = "Leer Datos";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // etVCTR
            // 
            this.etVCTR.AutoSize = true;
            this.etVCTR.Location = new System.Drawing.Point(175, 35);
            this.etVCTR.Name = "etVCTR";
            this.etVCTR.Size = new System.Drawing.Size(23, 13);
            this.etVCTR.TabIndex = 18;
            this.etVCTR.Text = "GO";
            // 
            // btLectura
            // 
            this.btLectura.Location = new System.Drawing.Point(128, 6);
            this.btLectura.Name = "btLectura";
            this.btLectura.Size = new System.Drawing.Size(75, 23);
            this.btLectura.TabIndex = 16;
            this.btLectura.Text = "Start";
            this.btLectura.UseVisualStyleBackColor = true;
            this.btLectura.Visible = false;
            this.btLectura.Click += new System.EventHandler(this.btLectura_Click);
            // 
            // lbMsgRx
            // 
            this.lbMsgRx.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.lbMsgRx.FormattingEnabled = true;
            this.lbMsgRx.IntegralHeight = false;
            this.lbMsgRx.Location = new System.Drawing.Point(15, 52);
            this.lbMsgRx.Name = "lbMsgRx";
            this.lbMsgRx.Size = new System.Drawing.Size(311, 96);
            this.lbMsgRx.TabIndex = 8;
            this.lbMsgRx.TabStop = false;
            this.lbMsgRx.UseTabStops = false;
            // 
            // etREF
            // 
            this.etREF.AutoSize = true;
            this.etREF.Location = new System.Drawing.Point(125, 36);
            this.etREF.Name = "etREF";
            this.etREF.Size = new System.Drawing.Size(28, 13);
            this.etREF.TabIndex = 13;
            this.etREF.Text = "REF";
            // 
            // etISIG
            // 
            this.etISIG.AutoSize = true;
            this.etISIG.Location = new System.Drawing.Point(238, 35);
            this.etISIG.Name = "etISIG";
            this.etISIG.Size = new System.Drawing.Size(28, 13);
            this.etISIG.TabIndex = 17;
            this.etISIG.Text = "ISIG";
            // 
            // etCNT
            // 
            this.etCNT.AutoSize = true;
            this.etCNT.Location = new System.Drawing.Point(73, 36);
            this.etCNT.Name = "etCNT";
            this.etCNT.Size = new System.Drawing.Size(29, 13);
            this.etCNT.TabIndex = 12;
            this.etCNT.Text = "CNT";
            // 
            // etWRK
            // 
            this.etWRK.AutoSize = true;
            this.etWRK.Location = new System.Drawing.Point(15, 36);
            this.etWRK.Name = "etWRK";
            this.etWRK.Size = new System.Drawing.Size(38, 13);
            this.etWRK.TabIndex = 11;
            this.etWRK.Text = "VGND";
            // 
            // btGuardar
            // 
            this.btGuardar.Location = new System.Drawing.Point(9, 7);
            this.btGuardar.Name = "btGuardar";
            this.btGuardar.Size = new System.Drawing.Size(111, 60);
            this.btGuardar.TabIndex = 14;
            this.btGuardar.Text = "Guardar Datos";
            this.btGuardar.UseVisualStyleBackColor = true;
            this.btGuardar.Click += new System.EventHandler(this.btGuardar_Click);
            // 
            // btStop232
            // 
            this.btStop232.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btStop232.Location = new System.Drawing.Point(223, 44);
            this.btStop232.Name = "btStop232";
            this.btStop232.Size = new System.Drawing.Size(91, 23);
            this.btStop232.TabIndex = 10;
            this.btStop232.Text = "Desconectar";
            this.btStop232.UseVisualStyleBackColor = true;
            this.btStop232.Click += new System.EventHandler(this.btStop232_Click);
            // 
            // btInit232
            // 
            this.btInit232.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btInit232.Location = new System.Drawing.Point(223, 7);
            this.btInit232.Name = "btInit232";
            this.btInit232.Size = new System.Drawing.Size(91, 23);
            this.btInit232.TabIndex = 7;
            this.btInit232.Text = "Conectar ";
            this.btInit232.UseVisualStyleBackColor = true;
            this.btInit232.Click += new System.EventHandler(this.btInit232_Click);
            // 
            // pbComm
            // 
            this.pbComm.Location = new System.Drawing.Point(13, 287);
            this.pbComm.Name = "pbComm";
            this.pbComm.Size = new System.Drawing.Size(408, 20);
            this.pbComm.Step = 1;
            this.pbComm.Style = System.Windows.Forms.ProgressBarStyle.Marquee;
            this.pbComm.TabIndex = 9;
            this.pbComm.Visible = false;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.rbFemenino);
            this.tabPage2.Controls.Add(this.rbMasculino);
            this.tabPage2.Controls.Add(this.lbSexo);
            this.tabPage2.Controls.Add(this.tbEdad);
            this.tabPage2.Controls.Add(this.lbEdad);
            this.tabPage2.Controls.Add(this.tbPaciente);
            this.tabPage2.Controls.Add(this.lbPaciente);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(427, 317);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Paciente";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // rbFemenino
            // 
            this.rbFemenino.AutoSize = true;
            this.rbFemenino.Location = new System.Drawing.Point(10, 135);
            this.rbFemenino.Name = "rbFemenino";
            this.rbFemenino.Size = new System.Drawing.Size(71, 17);
            this.rbFemenino.TabIndex = 6;
            this.rbFemenino.Text = "Femenino";
            this.rbFemenino.UseVisualStyleBackColor = true;
            this.rbFemenino.Click += new System.EventHandler(this.rbFemenino_Click);
            // 
            // rbMasculino
            // 
            this.rbMasculino.AutoSize = true;
            this.rbMasculino.Checked = true;
            this.rbMasculino.Location = new System.Drawing.Point(10, 112);
            this.rbMasculino.Name = "rbMasculino";
            this.rbMasculino.Size = new System.Drawing.Size(73, 17);
            this.rbMasculino.TabIndex = 5;
            this.rbMasculino.TabStop = true;
            this.rbMasculino.Text = "Masculino";
            this.rbMasculino.UseVisualStyleBackColor = true;
            this.rbMasculino.Click += new System.EventHandler(this.rbMasculino_Click);
            // 
            // lbSexo
            // 
            this.lbSexo.AutoSize = true;
            this.lbSexo.Location = new System.Drawing.Point(7, 96);
            this.lbSexo.Name = "lbSexo";
            this.lbSexo.Size = new System.Drawing.Size(34, 13);
            this.lbSexo.TabIndex = 4;
            this.lbSexo.Text = "Sexo:";
            // 
            // tbEdad
            // 
            this.tbEdad.Location = new System.Drawing.Point(10, 67);
            this.tbEdad.Name = "tbEdad";
            this.tbEdad.Size = new System.Drawing.Size(42, 20);
            this.tbEdad.TabIndex = 3;
            // 
            // lbEdad
            // 
            this.lbEdad.AutoSize = true;
            this.lbEdad.Location = new System.Drawing.Point(7, 51);
            this.lbEdad.Name = "lbEdad";
            this.lbEdad.Size = new System.Drawing.Size(35, 13);
            this.lbEdad.TabIndex = 2;
            this.lbEdad.Text = "Edad:";
            // 
            // tbPaciente
            // 
            this.tbPaciente.Location = new System.Drawing.Point(10, 24);
            this.tbPaciente.Name = "tbPaciente";
            this.tbPaciente.Size = new System.Drawing.Size(244, 20);
            this.tbPaciente.TabIndex = 1;
            // 
            // lbPaciente
            // 
            this.lbPaciente.AutoSize = true;
            this.lbPaciente.Location = new System.Drawing.Point(7, 7);
            this.lbPaciente.Name = "lbPaciente";
            this.lbPaciente.Size = new System.Drawing.Size(47, 13);
            this.lbPaciente.TabIndex = 0;
            this.lbPaciente.Text = "Nombre:";
            // 
            // tmrRequest
            // 
            this.tmrRequest.Interval = 1000;
            this.tmrRequest.Tick += new System.EventHandler(this.tmrRequest_Tick);
            // 
            // tmrLectura
            // 
            this.tmrLectura.Interval = 50;
            this.tmrLectura.Tick += new System.EventHandler(this.tmrLectura_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(459, 360);
            this.Controls.Add(this.tabControl);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1000, 1000);
            this.MinimumSize = new System.Drawing.Size(360, 320);
            this.Name = "Form1";
            this.Text = "GUI Glucommeter UDG";
            this.tabControl.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Label etREF;
        private System.Windows.Forms.Label etCNT;
        private System.Windows.Forms.Label etWRK;
        private System.Windows.Forms.Button btStop232;
        private System.Windows.Forms.ProgressBar pbComm;
        private System.Windows.Forms.Button btInit232;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TextBox tbPaciente;
        private System.Windows.Forms.Label lbPaciente;
        private System.Windows.Forms.RadioButton rbFemenino;
        private System.Windows.Forms.RadioButton rbMasculino;
        private System.Windows.Forms.Label lbSexo;
        private System.Windows.Forms.TextBox tbEdad;
        private System.Windows.Forms.Label lbEdad;
        private System.Windows.Forms.Button btGuardar;
        private System.Windows.Forms.Button btLectura;
        private System.Windows.Forms.Button btMonitoreo;
        private System.Windows.Forms.Label etVCTR;
        private System.Windows.Forms.Label etISIG;
        public System.Windows.Forms.ListBox lbMsgRx;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbVCTR;
        private System.Windows.Forms.Label lbISIG;
        private System.Windows.Forms.Timer tmrRequest;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label lbCNT;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lbREF;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lbWRK;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer tmrLectura;
    }
}

