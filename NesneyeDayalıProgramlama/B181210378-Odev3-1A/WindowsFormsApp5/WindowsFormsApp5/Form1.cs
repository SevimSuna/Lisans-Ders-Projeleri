/*****************
*
* OgrenciNo: B181210378
* OgrenciAdıSoyadı: Sevim Suna Kalayci
* OdevNo: 3.Odev
* Sube: 1A
*
******************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string girdi = textBox1.Text+'@'; //Degerleri atamak için sonuna ayırt edici bir ifade koydum
            int deger = 0, diziDeger = 0, karakterDeger = 0, diziGecici = 0, islemGecici = 0;
            int[] dizi = new int[100];
            char[] islem = new char[100];
            int i, j;
            while (girdi[deger] != '@')
            {
                if(girdi[deger] == '+' || girdi[deger] == '-' || girdi[deger] == '*' || girdi[deger] == '/')//İşlem gördükçe öndeki değerleri diziye islemleri islem dizisine aktardım.
                {
                    dizi[diziDeger] = Convert.ToInt32(girdi.Substring(0, deger));
                    girdi = girdi.Remove(0,deger);
                    islem[karakterDeger] = girdi[0];
                    girdi = girdi.Remove(0, 1);
                    diziDeger++;
                    karakterDeger++;
                    deger = 0;
                    
                }
                else
                {
                    deger++;
                }
            }
            dizi[diziDeger] = Convert.ToInt32(girdi.Substring(0, deger));
            diziDeger++;
            for(j=0; j<karakterDeger; j++)
            {
                if(islem[j] == '/')//İslem önceliği olan işlemleri hespaladım.
                {
                    dizi[j] = dizi[j] / dizi[j + 1];
                    for(i=j; i<karakterDeger; i++)
                    {
                        dizi[i + 1] = dizi[i + 2];
                        islem[i] = islem[i + 1];
                    }
                    diziGecici++;
                    islemGecici++;
                    j--;
                }
                else if (islem[j] == '*')
                {
                    dizi[j] = dizi[j] * dizi[j + 1];
                    for (i = j; i < karakterDeger; i++)
                    {
                        dizi[i + 1] = dizi[i + 2];
                        islem[i] = islem[i + 1];
                    }
                    diziGecici++;
                    islemGecici++;
                    if(islem[j+1] == ' ')
                    {
                        islem[j]='#';
                    }
                    --j;
                }
            }
            karakterDeger -= islemGecici;
            diziDeger -= diziGecici;
            for(i=0; i<karakterDeger; i++)
            {
                if (islem[i] == '+')
                {
                    dizi[i] = dizi[i] + dizi[i + 1];
                    for(j=i; j<karakterDeger; j++)
                    {
                        dizi[j + 1] = dizi[j + 2];
                        islem[j] = islem[j + 1];
                    }
                    --i;
                }
                else if (islem[i] == '-')
                {
                    dizi[i] = dizi[i] - dizi[i + 1];
                    for (j = i; j < karakterDeger; j++)
                    {
                        dizi[j + 1] = dizi[j + 2];
                        islem[j] = islem[j + 1];
                    }
                    --i;
                }
            }
            textBox2.Text = dizi[0].ToString();//Tüm işlemler yapıldıktan sonra sonuç dizinin ilk elemanında toplanmış oldu.

        }
    }
}
