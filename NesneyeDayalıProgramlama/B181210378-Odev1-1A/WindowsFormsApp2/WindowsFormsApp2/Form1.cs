/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2014-2015 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:1. Odev
**				ÖĞRENCİ ADI............:Sevim Suna Kalaycı
**				ÖĞRENCİ NUMARASI.......:B181210378
**                         DERSİN ALINDIĞI GRUP...:1A
****************************************************************************/

using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {//Globalde bilgi için gerekli dizileri tanımladım.
        string[] TCdizi = new string[100];
        string[] Addizi = new string[100];
        string[] SoyAddizi = new string[100];
        string[] yasdizi = new string[100];
        string[] CalismaSuresi = new string[100];
        string[] EvliDurum = new string[100];
        string[] EsCalisma = new string[100];
        string[] CocukSayi = new string[100];
        string[] TabanMaas = new string[100];
        string[] MakamTazminat = new string[100];
        string[] IdGrTaz = new string[100];
        string[] FazlaMesaiS = new string[100];
        string[] FazlaMesaiU = new string[100];
        string[] VergiMatrahı = new string[100];
        string[] PersonelResim = new string[100];
        string[] satirlar = new string[100];
        int sayi = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string yedek;
            int yedeksayi;
            OpenFileDialog file = new OpenFileDialog();//Bilgilerin kayıtlı oldugu text dosyasını arattım ve uygun bilgiler bulunuyorsa okuyup dizilere atadım.
            file.Filter = "Text Dosyası |*.txt";
            file.Title = "Text Dosyası Seçiniz..";
            if(richTextBox1.Text != "")
            {
                richTextBox1.Text = "";
            }
            if (file.ShowDialog() == DialogResult.OK)
            {
                string DosyaYolu = file.FileName;
                string DosyaAdi = file.SafeFileName;
                StreamReader dosyaOku;
                string yazi;

                dosyaOku = File.OpenText(DosyaYolu);
                yazi = dosyaOku.ReadLine();
                while (yazi != null)
                {
                    satirlar[sayi] = yazi;
                    yazi = dosyaOku.ReadLine();
                    richTextBox1.AppendText(satirlar[sayi] + "\n");
                    sayi++;
                }

                dosyaOku.Close();
                for (int x = 0; x < sayi; x++)
                {
                    yedek = satirlar[x];
                    yedeksayi = yedek.IndexOf(" ");
                    TCdizi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    Addizi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    SoyAddizi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    yasdizi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    CalismaSuresi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    EvliDurum[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    EsCalisma[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    CocukSayi[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    TabanMaas[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    MakamTazminat[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    IdGrTaz[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    FazlaMesaiS[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    FazlaMesaiU[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    VergiMatrahı[x] = yedek.Substring(0, yedeksayi);
                    yedek = yedek.Remove(0, yedeksayi + 1);
                    yedeksayi = yedek.IndexOf(" ");
                    PersonelResim[x] = yedek;


                }

            }




        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }
        private void button2_Click(object sender, EventArgs e)
        { //Hesapla butonunun üstediki TextBox'a yazılan Tc yi kontorol edip, gerekli hesaplamaları yapıp yadırdım.
            int deger = -1;
            int BrutMaas, DamgaVergisi, GelirMatrahı;
            double EmekliKesintisi, GelirVergisi = 0, NetMaas;
            if (textBox1.TextLength < 11)
            {
                MessageBox.Show("Eksik giriş yaptınız.");
            }
            else if (TCdizi[0] == null)
            {
                MessageBox.Show("Lütfen önce kayit işlemini yapınız.");
            }
            else
            {
                for (int sayac = 0; sayac < sayi; sayac++)
                {
                    if (textBox1.Text == TCdizi[sayac])
                    {
                        deger = sayac;
                    }
                }
                if (deger < 0)
                {
                    MessageBox.Show("Bu TC numarasında bir çalışan bulunmamaktadır");

                }
                else
                {
                    if (EvliDurum[deger] == "E" && EsCalisma[deger] == "H")
                    {
                        BrutMaas = Convert.ToInt32(TabanMaas[deger]) + Convert.ToInt32(MakamTazminat[deger]) + Convert.ToInt32(IdGrTaz[deger]) + (Convert.ToInt32(CocukSayi[deger]) * 30) + (Convert.ToInt32(FazlaMesaiS[deger]) * Convert.ToInt32(FazlaMesaiU[deger])) + 200;
                    }
                    else
                    {
                        BrutMaas = Convert.ToInt32(TabanMaas[deger]) + Convert.ToInt32(MakamTazminat[deger]) + Convert.ToInt32(IdGrTaz[deger]) + (Convert.ToInt32(CocukSayi[deger]) * 30) + (Convert.ToInt32(FazlaMesaiS[deger]) * Convert.ToInt32(FazlaMesaiU[deger]));
                    }
                    GelirMatrahı = Convert.ToInt32(TabanMaas[deger]) ;
                    if(GelirMatrahı <10000)
                    {
                        GelirVergisi = BrutMaas * 15 / 100;
                    }
                    else if(GelirMatrahı <20000)
                    {
                        GelirVergisi = BrutMaas * 20 / 100;
                    }
                    else if(GelirMatrahı <30000)
                    {
                        GelirVergisi = BrutMaas * 25 / 100;
                    }
                    else if(GelirMatrahı >=30000)
                    {
                        GelirVergisi = BrutMaas * 30 / 100;
                    }
                    DamgaVergisi = BrutMaas * 10 / 100;
                    EmekliKesintisi = BrutMaas * 15 / 100;
                    NetMaas = BrutMaas - (EmekliKesintisi + GelirVergisi + DamgaVergisi);

                    label1.Text = ("Brüt Maaş: " + BrutMaas.ToString() + "\nDamga Vergisi: " + DamgaVergisi.ToString() + "\nEmeklilik Kesintisi: " + EmekliKesintisi.ToString() + "\nGelir Vergisi: " + GelirVergisi.ToString() + "\nNet maaş: " + NetMaas.ToString());
                }

            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //RichBox içindeki bilgileri satır satır okuyup text dosyasına aktardım.
            int sayac = 0, baslangic = 0, son = 0, dogrulama = 0;
            string metin = richTextBox1.Text;
            string yedek;
            int yedeksayi;
            if (richTextBox1.Text == "")
            {
                MessageBox.Show("Kayıt için bilgi girmeniz gerekmektedir.");
            }
            else
            {
                son = metin.IndexOf("\n", baslangic);
                if (metin != null)
                {
                    while (son >= 0)
                    {
                        string kalan = metin.Substring(baslangic, son - baslangic);
                        baslangic = son + 1;
                        son = metin.IndexOf("\n", baslangic);
                        sayac++;
                    }
                }
                sayi = sayac;
                for (int x = 0; x < sayac; x++)
                {
                    yedek = richTextBox1.Lines[x];
                    yedeksayi = yedek.IndexOf(" ");
                    if (yedeksayi != 11)
                    {
                        MessageBox.Show("Hatalı bilgi girdiniz. Lütfen TC bilgisini kontorl ediniz.");
                        dogrulama = x;
                    }
                    else
                    {
                        TCdizi[x] = yedek.Substring(0, yedeksayi);
                        yedek = yedek.Remove(0, yedeksayi + 1);
                        yedeksayi = yedek.IndexOf(" ");
                        Addizi[x] = yedek.Substring(0, yedeksayi);
                        yedek = yedek.Remove(0, yedeksayi + 1);
                        yedeksayi = yedek.IndexOf(" ");
                        SoyAddizi[x] = yedek.Substring(0, yedeksayi);
                        yedek = yedek.Remove(0, yedeksayi + 1);
                        yedeksayi = yedek.IndexOf(" ");
                        yasdizi[x] = yedek.Substring(0, yedeksayi);
                        yedek = yedek.Remove(0, yedeksayi + 1);
                        yedeksayi = yedek.IndexOf(" ");
                        CalismaSuresi[x] = yedek.Substring(0, yedeksayi);
                        yedek = yedek.Remove(0, yedeksayi + 1);
                        yedeksayi = yedek.IndexOf(" ");
                        if (yedeksayi > 1 || yedeksayi < 1)
                        {
                            MessageBox.Show("Hatalı bilgi girdiniz. Lütfen kontrol ediniz");
                        }
                        else
                        {
                            EvliDurum[x] = yedek.Substring(0, yedeksayi);
                            if (EvliDurum[x] != "E" && EvliDurum[x] != "B")
                            {
                                MessageBox.Show("Hatalı bilgi girdiniz. Lütfen kontrol ediniz.");
                                richTextBox1.Lines[x].Remove(0, richTextBox1.Lines[x].Length);
                                
                            }
                            else if(EvliDurum[x] == "E" || EvliDurum[x] == "B")
                            {
                                yedek = yedek.Remove(0, yedeksayi + 1);
                                yedeksayi = yedek.IndexOf(" ");
                                if (yedeksayi > 1 || yedeksayi < 1)
                                {
                                    MessageBox.Show("Hatalı bilgi girdiniz. Lütfen kontrol ediniz.");
                                }
                                else
                                {
                                    EsCalisma[x] = yedek.Substring(0, yedeksayi);
                                    if (EsCalisma[x] != "E" && EsCalisma[x] != "H")
                                    {
                                        MessageBox.Show("Hatalı bilgi girdiniz. Lütfen kontorl ediniz.4");
                                    }
                                    else if(EsCalisma[x] == "E" || EsCalisma[x] == "H")
                                    {
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        CocukSayi[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        TabanMaas[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        MakamTazminat[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        IdGrTaz[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        FazlaMesaiS[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        FazlaMesaiU[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        VergiMatrahı[x] = yedek.Substring(0, yedeksayi);
                                        yedek = yedek.Remove(0, yedeksayi + 1);
                                        yedeksayi = yedek.IndexOf(" ");
                                        PersonelResim[x] = yedek;

                                        dogrulama--;
                                    }
                                }
                            }
                        }
                    }
                }
                if(dogrulama < 0)
                {
                    SaveFileDialog save = new SaveFileDialog();
                    save.Filter = "Metin Dosyası|*.txt";
                    if (save.ShowDialog() == DialogResult.OK)
                    {
                        StreamWriter Kayit = new StreamWriter(save.FileName);
                        Kayit.Write(richTextBox1.Text);
                        Kayit.Close();
                    }
                    dogrulama = 0;
                }
                else
                {
                    
                }
            }
        }
    }
}
