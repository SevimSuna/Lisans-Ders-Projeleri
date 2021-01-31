/*****************************************
 *          Sakarya Universitesi
 *  Bilgisayar ve Bilişim Bilimleri Fakültesi
 *      Bilgisayar Mühendisliği Bölümü
 * 
 * Öğrenci No        : B181210378
 * Öğrenci Adı Soyadı: Sevim Suna Kalaycı
 * Grup No           : 1A
 * 
 ****************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp6
{
    public partial class Form1 : Form
    {//Global kısımda değişkenlerimi tanımladım.
        int saniyeTavuk = 0, saniyeİnek = 0, saniyeOrdek = 0, saniyeKeci = 0, saniye = 0;
        int tavukYumurta = 0, ordekYumurta = 0, inekSut = 0, keciSut = 0;
        int kasa = 0;
        int[] can = new int[4];

        SoundPlayer tavukSes = new SoundPlayer();
        SoundPlayer ordekSes = new SoundPlayer();
        SoundPlayer inekSes = new SoundPlayer();
        SoundPlayer keciSes = new SoundPlayer();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {// Tavuk yumurtası için kasa hesaplaması yaptım. 
            kasa += tavukYumurta * 1;
            label20.Text = Convert.ToString(kasa) + " TL";
            tavukYumurta = 0;
            label15.Text = Convert.ToString(tavukYumurta) + " ADET";
        }

        private void timer2_Tick(object sender, EventArgs e)
        {//Ördek can barını saniyelik düşmesini ve ölmesi durumu
            saniyeOrdek++;
            if (saniyeOrdek % 5 == 0 && saniyeOrdek != 0)
            {
                ordekYumurta++;
                label16.Text = Convert.ToString(ordekYumurta) + " ADET";
            }
            if (can[1] > 0)
            {
                progressBar2.Value = can[1];
                can[1] = can[1] - 3;
                
            }
            if (can[1] <= 0)
            {
                progressBar2.Value = 0;
                label7.Text = "ÖLDÜ";
                ordekSes.Play();
                timer2.Stop();

            }
        }
        private void timer3_Tick(object sender, EventArgs e)
        {//İnek için saniyelik can azalması ve ölme durumu
            saniyeİnek++;
            if (saniyeİnek % 8 == 0 && saniyeİnek != 0)
            {
                inekSut++;
                label17.Text = Convert.ToString(inekSut) + " ADET";
            }
            if (can[2] > 0)
            {
                progressBar3.Value = can[2];
                can[2] = can[2] - 8;
                
            }
            if (can[2] <= 0)
            {
                progressBar3.Value = 0;
                label9.Text = "ÖLDÜ";
                inekSes.Play();
                timer3.Stop();

            }
        }

        private void timer4_Tick(object sender, EventArgs e)
        {// Keçi için saniyelik can azalması ve ölme durumu
            saniyeKeci++;
            if (saniyeKeci % 8 == 0 && saniyeKeci != 0)
            {
                keciSut++;
                label18.Text = Convert.ToString(keciSut) + " ADET";
            }
            if (can[3] > 0)
            {
                progressBar4.Value = can[3];
                can[3] = can[3] - 7;
                
            }
            if (can[3] <= 0)
            {
                progressBar4.Value = 0;
                label10.Text = "ÖLDÜ";
                keciSes.Play();
                timer4.Stop();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {//Tavuk için yem verme
            if(can[0] > 0)
            {
                can[0] = 100;
                progressBar1.Value = can[0];
            }
            else
            {
                progressBar1.Value = 0;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {//Ördek için yem verme
            if(can[1] > 0)
            {
                can[1] = 100;
                progressBar2.Value = can[1];
            }
            else
            {
                progressBar2.Value = 0;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {//İnek için yem verme
            if(can[2] > 0)
            {
                can[2] = 100;
                progressBar3.Value = can[2];
            }
            else
            {
                progressBar3.Value = 0;
            }
            
        }

        private void button8_Click(object sender, EventArgs e)
        {//Keci için yem verme
            if(can[3] > 0)
            {
                can[3] = 100;
                progressBar4.Value = can[3];
            }
            else
            {
                progressBar4.Value = 0;
            }
        }

        private void timer5_Tick(object sender, EventArgs e)
        {
            saniye++;
            label19.Text = Convert.ToString(saniye) + " SN";
        }

        private void button2_Click(object sender, EventArgs e)
        {//Kasaya ördek yumurtası satmasında gelecek para
            kasa += ordekYumurta * 3;
            label20.Text = Convert.ToString(kasa) + " TL";
            ordekYumurta = 0;
            label16.Text = Convert.ToString(ordekYumurta) + " ADET";
        }

        private void button3_Click(object sender, EventArgs e)
        {//Kasaya inek sütü satmasında gelecek para
            kasa += inekSut * 5;
            label20.Text = Convert.ToString(kasa) + " TL";
            inekSut = 0;
            label17.Text = Convert.ToString(inekSut) + " KG";
        }

        private void button4_Click(object sender, EventArgs e)
        {//Kasaya keci satmasında gelecek para
            kasa += keciSut * 8;
            label20.Text = Convert.ToString(kasa) + " TL";
            keciSut = 0;
            label18.Text = Convert.ToString(keciSut) + " KG";
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {//Sayfa yüklendiğinde başlangıç değerleri ve temel atamalar 
            timer1.Interval = 1000;
            timer1.Start();
            timer2.Interval = 1000;
            timer2.Start();
            timer3.Interval = 1000;
            timer3.Start();
            timer4.Interval = 1000;
            timer4.Start();
            timer5.Interval = 1000;
            timer5.Start();
            tavukSes.SoundLocation = @"C:\Users\pc\source\repos\WindowsFormsApp6\WindowsFormsApp6\tavuk.wav";
            ordekSes.SoundLocation = @"C:\Users\pc\source\repos\WindowsFormsApp6\WindowsFormsApp6\ordek.wav";
            inekSes.SoundLocation = @"C:\Users\pc\source\repos\WindowsFormsApp6\WindowsFormsApp6\inek.wav";
            keciSes.SoundLocation = @"C:\Users\pc\source\repos\WindowsFormsApp6\WindowsFormsApp6\keci.wav";
            for (int i=0; i<4; i++)
            {
                can[i] = 100;
            }
            progressBar1.Value = 100;
            progressBar2.Value = 100;
            progressBar3.Value = 100;
            progressBar4.Value = 100;

        }

        private void timer1_Tick(object sender, EventArgs e)
        {//Tavuk için saniyelik can azalması ve ölme durumu
            saniyeTavuk++;
            if (saniyeTavuk % 3 == 0 && saniyeTavuk != 0)
            {
                tavukYumurta++;
                label15.Text = Convert.ToString(tavukYumurta) + " ADET";

            }

            if (can[0] > 0)
            {
                progressBar1.Value = can[0];
                can[0] = can[0] - 2;
                
            }
            if(can[0] <= 0)
            {
                progressBar1.Value = 0;
                label6.Text = "ÖLDÜ";
                tavukSes.Play();
                timer1.Stop();
            }
              
            
            
            
        }
            
    }
}

