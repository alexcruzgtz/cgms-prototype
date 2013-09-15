using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        /*
         * Declaration of vars.
         */
        public int pbStop;
        public int MonitorLectura;
        public int CantidadDatos;
        public string Sexo="Masculino";
        public string DataRx;
        public string Modo;
        public string DatoTxt;
        public float DatoNum;

        public string DatosCompletos;


        public Form1()
        {
            InitializeComponent();
        }

        private void btInit232_Click(object sender, EventArgs e)
        {
            //pbComm.PerformStep();
            if (!(serialPort.IsOpen))
            {
                serialPort.Open();
                pbComm.Visible = true;
                pbComm.Value = 0;
                btMonitoreo.Visible = true;
                btLectura.Visible = true;
            } 

        }

        private void btStop232_Click(object sender, EventArgs e)
        {
            if (serialPort.IsOpen)
              {
                serialPort.Close();
                pbComm.Visible = false;
              }             
        }

        private void btGuardar_Click(object sender, EventArgs e)
        {
            StreamWriter Write;
            SaveFileDialog Open = new SaveFileDialog();
            if (ValidateName(tbPaciente) && ValidateEdad(tbEdad))
            {
                try
                {
                    Open.Filter = ("Text Document|*.txt|All Files|*.*");
                    Open.ShowDialog();
                    Write = new StreamWriter(Open.FileName);


                    //////////////////////////////////////////////////////////////////////////////////////////////////////
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("          UU     UU         DDDDDD             GGGGG");
                    Write.WriteLine("          UU     UU         DD   DD           G     G");
                    Write.WriteLine("          UU     UU         DD    DD         GG       ");
                    Write.WriteLine("          UU     UU         DD    DD         GG       ");
                    Write.WriteLine("          UU     UU         DD    DD         GG   GGG");
                    Write.WriteLine("          UU     UU         DD    DD         GG     GG");
                    Write.WriteLine("          UUU   UUU         DD   DD           G     GG");
                    Write.WriteLine("            UUUUU           DDDDDD             GGGGGG");
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("////////////////////////////////////////////////////////////////");
                    Write.WriteLine("                 Universidad de Guadalajara");
                    Write.WriteLine(" ");
                    Write.WriteLine("    Centro Universitario de Ciencias Exactas e Ingenierías");
                    Write.WriteLine(" ");
                    Write.WriteLine("	       Sistema de Medición de insulina");
                    Write.WriteLine(" ");
                    Write.WriteLine("----------------------------------------------------------------");
                    Write.WriteLine("                      Datos del Paciente");
                    Write.WriteLine(" ");
                    Write.WriteLine("Nombre: " + Convert.ToString(tbPaciente.Text));
                    Write.WriteLine("Edad: " + Convert.ToString(tbEdad.Text) + " Años");
                    Write.WriteLine("Sexo: "+Convert.ToString(Sexo));
                    Write.WriteLine(" ");
                    Write.WriteLine("----------------------------------------------------------------");
                    Write.WriteLine("                   Datos de las mediciones");
                    Write.WriteLine(" ");
                    Write.WriteLine("VGND           CNT           REF          VCTR          ISIG");
                    Write.WriteLine("----------------------------------------------------------------");
                    //////////////////////////////////////////////////////////////////////////////////////////////////////

                    /*Escribir la función para Guardar los datos de las mediciones*/

                    for (int I = 0; I < lbMsgRx.Items.Count; I++)
                    {
                        Write.WriteLine(Convert.ToString(lbMsgRx.Items[I]));
                    }
                    Write.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(Convert.ToString(ex.Message));
                    return;
                }
            }
            else
            {
                MessageBox.Show("Para guadar los datos favor de llenar los campos del Paciente");
            }
        }

        private bool ValidateName(System.Windows.Forms.TextBox txBox)
        {
            if (txBox.Text != string.Empty)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private bool ValidateEdad(System.Windows.Forms.TextBox txBox)
        {
            if (txBox.Text != string.Empty && (txBox.Text.Last() >= '0' && txBox.Text.Last() <= '9'))
            {
                return true;
            }
            else
            {
                MessageBox.Show("En el campo de Edad solo se permiten números.");
                return false;
            }
        }

        private void rbMasculino_Click(object sender, EventArgs e)
        {
            Sexo = "Masculino";
        }

        private void rbFemenino_Click(object sender, EventArgs e)
        {
            Sexo = "Femenino";
        }

        private void serialPort_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            
            DataRx = serialPort.ReadTo("\r");
            if (DataRx.Length >= 9)
            {

                Modo = DataRx.Substring(0, 3);
                DatoTxt = DataRx.Substring(4, 5);
                //DatoNum = float.Parse(DatoTxt, System.Globalization.NumberStyles.Number);
                this.Invoke(new EventHandler(EscribeTexto));
            }
        }
        
        private void EscribeTexto(object sender, EventArgs e)
        {
            //this.Invoke(new EventHandler(Show_Monitor));
            if (MonitorLectura == 1)
            {
                Show_Monitor();
            }
            else
            {
                Show_Lectura();
            }
            
        }

        private void btLectura_Click(object sender, EventArgs e)
        {
            serialPort.Write("Lectura:");
            tmrRequest.Enabled = false;
            tmrLectura.Enabled = true;
            MonitorLectura = 0;
            serialPort.Write("LeerCnt:");
        }

        private void btMonitoreo_Click(object sender, EventArgs e)
        {
            serialPort.Write("Monitor:");
            tmrRequest.Enabled = true;
            tmrLectura.Enabled = false;
            MonitorLectura = 1;
        }

        private void tmrRequest_Tick(object sender, EventArgs e)
        {
            serialPort.Write("Request:");
        }

        void Show_Lectura( )
        {
            switch (Modo)
            {
                case "Cnt":
                    CantidadDatos = int.Parse( DatoTxt,System.Globalization.NumberStyles.Number);
                    //float.Parse(DatoTxt, System.Globalization.NumberStyles.Number);
                    lbMsgRx.Items.Add(DatoTxt);
                    lbMsgRx.SelectedIndex = lbMsgRx.Items.Count - 1;
                    break;
                case "Vct":

                    DatosCompletos = DatoTxt + "         ";
                    break;
                case "Isg":
                    DatosCompletos = DatosCompletos + DatoTxt;
                    lbMsgRx.Items.Add(DatosCompletos);
                    lbMsgRx.SelectedIndex = lbMsgRx.Items.Count - 1;
                    break;
            }
        }

        void Show_Monitor()
        {
            switch (Modo)
            {
                case "WRK":
                    lbWRK.Text = DatoTxt;
                    break;
                case "CNT":
                    lbCNT.Text = DatoTxt;
                    break;
                case "REF":
                    lbREF.Text = DatoTxt;
                    break;
                case "vct":
                    if (DatoTxt == "0.001")
                    {
                        lbVCTR.ForeColor = Color.FromArgb(255, 0, 0); 
                    }
                    else
                    {
                        lbVCTR.ForeColor = Color.FromArgb(0, 255, 0);
                    }
                    break;
                case "VCT":
                    lbVCTR.Text = DatoTxt;
                    break;
                case "isg":
                    if (DatoTxt == "0.001")
                    {
                        lbISIG.ForeColor = Color.FromArgb(255, 0, 0);
                    }
                    else
                    {
                        lbISIG.ForeColor = Color.FromArgb(0, 255, 0);
                    }
                    break;
                case "ISG":
                    lbISIG.Text = DatoTxt;

                    break;
            }
        }

        private void tmrLectura_Tick(object sender, EventArgs e)
        {
            serialPort.Write("LeerDat:");
        }

        
    }
}
