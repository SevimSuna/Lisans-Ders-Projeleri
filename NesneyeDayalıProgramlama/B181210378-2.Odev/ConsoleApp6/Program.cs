/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				    NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:2. Odev
**				ÖĞRENCİ ADI............:Sevim Suna Kalaycı
**				ÖĞRENCİ NUMARASI.......:B181210378
**                         DERSİN ALINDIĞI GRUP...:1A
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Futbolcu //Asıl sınıfımızı oluşturdum.
    {
        public string AdSoyad;
        public int FormaNo;
        public int Hiz;
        public int Dayaniklilik;
        public int Pas;
        public int Sut;
        public int Yetenek;
        public int Karalilik;
        public int DogalForm;
        public int Sans;
        Random rastgeleSayi = new Random();
        public Futbolcu()
        {
            Hiz = 0;
            Dayaniklilik = 0;
            Pas = 0;
            Sut = 0;
            Yetenek = 0;
            Karalilik = 0;
            DogalForm = 0;
            Sans = 0;
        }

        public Futbolcu(string AdSoyad, int FormaNo)//İsim ve forma numaraları harici bütün bilgileri rastgele atadım.
        {
            this.AdSoyad = AdSoyad;
            this.FormaNo = FormaNo;
            Hiz = rastgeleSayi.Next(50, 100);
            Dayaniklilik = rastgeleSayi.Next(50, 100);
            Pas = rastgeleSayi.Next(50, 100);
            Sut = rastgeleSayi.Next(50, 100);
            Yetenek = rastgeleSayi.Next(50, 100);
            Karalilik = rastgeleSayi.Next(50, 100);
            DogalForm = rastgeleSayi.Next(50, 100);
            Sans = rastgeleSayi.Next(50, 100);
        }
        public virtual void EkranaYazdir()//Kontrol amaçlı ekrana yazdırdım.
        {
            Console.WriteLine("Ad Soyad: " + this.AdSoyad);
            Console.WriteLine("Forma: " + this.FormaNo.ToString());
            Console.WriteLine("Hiz: " + this.Hiz.ToString());
            Console.WriteLine("Dayaniklilik: " + this.Dayaniklilik.ToString());
            Console.WriteLine("Pas: " + this.Pas.ToString());
            Console.WriteLine("Sut" + this.Sut.ToString());
            Console.WriteLine("Yetenek: " + this.Yetenek.ToString());
            Console.WriteLine("Form: " + this.DogalForm.ToString());
            Console.WriteLine("Sans: " + this.Sans.ToString());
        }
        public virtual Boolean PasVer()//Futbolcu bilgileriyle pasvermeyi hesapladım. 
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklilik * 0.1 + DogalForm * 0.1 + Sans * 0.2;
            if (PasSkor > 60)
                return true;
            else
                return false;
        }
        public virtual Boolean GolVurusu()//Futbolcu bilgileriyle golvurusunu hesapladım.
        {
            double GolSkor = Yetenek * 0.3 + Sut * 0.2 + Karalilik * 0.1 + DogalForm * 0.1 + Hiz * 0.1 + Sans * 0.2;
            if (GolSkor > 70)
                return true;
            else
                return false;
        }
    }
    class Defans : Futbolcu
    {
        private int PozisyonAlma;
        private int Kafa;
        private int Sicrama;
        Random rastgeleSayi = new Random();

        public Defans(string AdSoyad, int FormaNo)//Türetilmis sınıf icin kurucu fonksiyon olusturdum.
            : base(AdSoyad, FormaNo)
        {
            
            Hiz = rastgeleSayi.Next(50, 90);
            Dayaniklilik = rastgeleSayi.Next(50, 90);
            Pas = rastgeleSayi.Next(50, 90);
            Sut = rastgeleSayi.Next(50, 90);
            Yetenek = rastgeleSayi.Next(50, 90);
            Karalilik = rastgeleSayi.Next(50, 90);
            DogalForm = rastgeleSayi.Next(50, 90);
            Sans = rastgeleSayi.Next(50, 90);
            PozisyonAlma = rastgeleSayi.Next(50, 90);
            Kafa = rastgeleSayi.Next(50, 90);
            Sicrama = rastgeleSayi.Next(50, 90);
        }
        public override void EkranaYazdir()
        {
            Console.WriteLine("Ad Soyad: " + this.AdSoyad);
            Console.WriteLine("Forma: " + this.FormaNo.ToString());
            Console.WriteLine("Hiz: " + this.Hiz.ToString());
            Console.WriteLine("Dayaniklilik: " + this.Dayaniklilik.ToString());
            Console.WriteLine("Pas: " + this.Pas.ToString());
            Console.WriteLine("Sut" + this.Sut.ToString());
            Console.WriteLine("Yetenek: " + this.Yetenek.ToString());
            Console.WriteLine("Form: " + this.DogalForm.ToString());
            Console.WriteLine("Sans: " + this.Sans.ToString());
            Console.WriteLine("Pozisyon: " + this.PozisyonAlma.ToString());
            Console.WriteLine("Kafa: " + this.Kafa.ToString());
            Console.WriteLine("Sicrama: " + this.Sicrama.ToString());
        }
        public override Boolean PasVer()
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklilik * 0.1 + DogalForm * 0.1 + PozisyonAlma * 0.1 + Sans * 0.2;
            if (PasSkor > 60)
                return true;
            else
                return false;
        }
        public override Boolean GolVurusu()
        {
            double GolSkor = Yetenek * 0.3 + Sut * 0.3 + Karalilik * 0.1 + DogalForm * 0.1 + Kafa * 0.1 + Sicrama * 0.1 + Sans * 0.1;
            if (GolSkor > 70)
                return true;
            else
                return false;
        }
    }
    class OrtaSaha : Futbolcu
    {
        private int UzunTop;
        private int IlkDokunus;
        private int Uretkenlik;
        private int TopSurme;
        private int OzelYetenek;
        Random rastgeleSayi = new Random();
        public OrtaSaha(string AdSoyad, int FormaNo)
            : base(AdSoyad, FormaNo)
        {
            
            Hiz = rastgeleSayi.Next(60, 100);
            Dayaniklilik = rastgeleSayi.Next(60, 100);
            Pas = rastgeleSayi.Next(60, 100);
            Sut = rastgeleSayi.Next(60, 100);
            Yetenek = rastgeleSayi.Next(60, 100);
            Karalilik = rastgeleSayi.Next(60, 100);
            DogalForm = rastgeleSayi.Next(60, 100);
            Sans = rastgeleSayi.Next(60, 100);
            UzunTop = rastgeleSayi.Next(60, 100);
            IlkDokunus = rastgeleSayi.Next(60, 100);
            Uretkenlik = rastgeleSayi.Next(60, 100);
            TopSurme = rastgeleSayi.Next(60, 100);
            OzelYetenek = rastgeleSayi.Next(60, 100);
        }
        public override void EkranaYazdir()
        {
            Console.WriteLine("Ad Soyad: " + this.AdSoyad);
            Console.WriteLine("Forma: " + this.FormaNo.ToString());
            Console.WriteLine("Hiz: " + this.Hiz.ToString());
            Console.WriteLine("Dayaniklilik: " + this.Dayaniklilik.ToString());
            Console.WriteLine("Pas: " + this.Pas.ToString());
            Console.WriteLine("Sut" + this.Sut.ToString());
            Console.WriteLine("Yetenek: " + this.Yetenek.ToString());
            Console.WriteLine("Form: " + this.DogalForm.ToString());
            Console.WriteLine("Sans: " + this.Sans.ToString());
            Console.WriteLine("Uzuntop: " + this.IlkDokunus.ToString());
            Console.WriteLine("Uretkenlik: " + this.Uretkenlik.ToString());
            Console.WriteLine("Top Surme: " + this.TopSurme.ToString());
            Console.WriteLine("Ozel Yetenek: " + this.OzelYetenek.ToString());
        }
        public override Boolean PasVer()
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + UzunTop * 0.1 + TopSurme * 0.1 + Sans * 0.1;
            if (PasSkor > 60)
                return true;
            else
                return false;
        }
        public override Boolean GolVurusu()
        {
            double GolSkor = Yetenek * 0.3 + OzelYetenek * 0.2 + Sut * 0.2 + IlkDokunus * 0.1 + Karalilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (GolSkor > 70)
                return true;
            else
                return false;
        }
    }
    class Forvet : Futbolcu
    {
        
        private int Bitiriciklik;
        private int IlkDokunus;
        private int Kafa;
        private int OzelYetenek;
        private int SogukKanlilik;
        

        public Forvet(string Adsoyad, int FormaNo)
            : base(Adsoyad, FormaNo)
        {
            Random rastgeleSayi = new Random();
            Hiz = rastgeleSayi.Next(70, 100);
            Dayaniklilik = rastgeleSayi.Next(70, 100);
            Pas = rastgeleSayi.Next(70, 100);
            Sut = rastgeleSayi.Next(70, 100);
            Yetenek = rastgeleSayi.Next(70, 100);
            Karalilik = rastgeleSayi.Next(70, 100);
            DogalForm = rastgeleSayi.Next(70, 100);
            Sans = rastgeleSayi.Next(70, 100);
            Bitiriciklik = rastgeleSayi.Next(70, 100);
            IlkDokunus = rastgeleSayi.Next(70, 100);
            Kafa = rastgeleSayi.Next(70, 100);
            OzelYetenek = rastgeleSayi.Next(70, 100);
            SogukKanlilik = rastgeleSayi.Next(70, 100);
        }
        public override void EkranaYazdir()
        {
            Console.WriteLine("Ad Soyad: " + this.AdSoyad);
            Console.WriteLine("Forma: " + this.FormaNo.ToString());
            Console.WriteLine("Hiz: " + this.Hiz.ToString());
            Console.WriteLine("Dayaniklilik: " + this.Dayaniklilik.ToString());
            Console.WriteLine("Pas: " + this.Pas.ToString());
            Console.WriteLine("Sut" + this.Sut.ToString());
            Console.WriteLine("Yetenek: " + this.Yetenek.ToString());
            Console.WriteLine("Form: " + this.DogalForm.ToString());
            Console.WriteLine("Sans: " + this.Sans.ToString());
            Console.WriteLine("Uzuntop: " + this.IlkDokunus.ToString());
            Console.WriteLine("Bitiricilik: " + this.Bitiriciklik.ToString());
            Console.WriteLine("Kafa: " + this.Kafa.ToString());
            Console.WriteLine("Ozel Yetenek: " + this.OzelYetenek.ToString());
            Console.WriteLine("Sogukkanlılık: " + this.SogukKanlilik.ToString());
        }
        public override Boolean PasVer()
        {
            double PasSkor;
            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (PasSkor > 60)
                return true;
            else
                return false;
        }
        public override Boolean GolVurusu()
        {
            double GolSkor = Yetenek * 0.2 + OzelYetenek * 0.2 + Sut * 0.1 + Kafa * 0.1 + IlkDokunus * 0.1 + Bitiriciklik * 0.1 + SogukKanlilik * 0.1 + Karalilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
            if (GolSkor > 70)
                return true;
            else
                return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int OyuncuSirasi;
            Boolean GolOlabilir = true;
            Random rastgeleSayi = new Random();
            int Kontrol;
            OyuncuSirasi = rastgeleSayi.Next(0, 10);
            Console.WriteLine("OYUNCULAR YÜKLENİYOR LÜTFEN BEKLEYİNİZ");// Yüklenmede oluşan ufak bekleme için uyarı koydum.
            Futbolcu[] Oyuncu = new Futbolcu[11];
            Oyuncu[0] = new Futbolcu("Koray", 1);
            
            Oyuncu[1] = new Defans("Tugay", 2);
            System.Threading.Thread.Sleep(100);//Saniye başı değiştiği için bekletmek zorunda kaldım.(Farklı değerler için.)
            Oyuncu[2] = new Defans("Enes", 4);
            System.Threading.Thread.Sleep(100);
            Oyuncu[3] = new Defans("Hakan", 3);
            
            Oyuncu[4] = new OrtaSaha("Yasin", 5);
            System.Threading.Thread.Sleep(100);
            Oyuncu[5] = new OrtaSaha("Latif", 6);
            System.Threading.Thread.Sleep(100);
            Oyuncu[6] = new OrtaSaha("Oguz", 8);
            System.Threading.Thread.Sleep(100);
            Oyuncu[7] = new OrtaSaha("Şakir", 18);
            
            Oyuncu[8] = new Forvet("Ugur", 9);
            System.Threading.Thread.Sleep(100);
            Oyuncu[9] = new Forvet("Emre", 7);
            System.Threading.Thread.Sleep(100);
            Oyuncu[10] = new Forvet("Tan", 11);

            Console.WriteLine("\nOyuncular hazır. Karşılaşma başladı.\n");//Yüklenmenin bittiğini bildirdim.
            System.Threading.Thread.Sleep(1000);

            /*for (int i = 0; i < 11; i++) //Kontorl amaçlı aynı sonuçları alıp almadıklarını kontrol ettim.
            {
                Oyuncu[i].EkranaYazdir();
                Console.WriteLine("*************************************\n\n");
            }*/

            for(int i=0; i<3; i++)
            {
                
                Kontrol = OyuncuSirasi;
                Console.WriteLine("Top " + Oyuncu[OyuncuSirasi].FormaNo + " forma numaralı " + Oyuncu[OyuncuSirasi].AdSoyad + " isimli oyuncuda.");
                System.Threading.Thread.Sleep(1000);//Burda amacım oyun havası vermek için beklettim.

                if (!Oyuncu[OyuncuSirasi].PasVer())
                {
                    Console.WriteLine("Pas isabetli olmadi.");
                    GolOlabilir = false;
                    break;
                }
                else
                {
                    if(i==2)
                    {
                        Console.WriteLine("Kale Vurusu.");
                        GolOlabilir = true;
                        System.Threading.Thread.Sleep(1000);
                    }
                    else
                    {
                        Console.WriteLine("Pas isabetli.");
                        GolOlabilir = true;
                        OyuncuSirasi = rastgeleSayi.Next(0, 10);
                        if(Kontrol == OyuncuSirasi)
                        {
                            while(OyuncuSirasi == Kontrol)
                            {
                                OyuncuSirasi = rastgeleSayi.Next(0, 10);
                            }
                        }
                        System.Threading.Thread.Sleep(1000);
                    }
                    
                }
            }
            if(GolOlabilir)
            {
                OyuncuSirasi = rastgeleSayi.Next(0, 10);
                GolOlabilir = Oyuncu[OyuncuSirasi].GolVurusu();
                if(!GolOlabilir)
                {
                    Console.WriteLine("OUT!");
                }
                else
                {
                    Console.WriteLine("VE GOOOOOOL!");
                }
            }
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }
    }
}
