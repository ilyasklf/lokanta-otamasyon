/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**				BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSÝ
**					2022-2023 BAHAR DÖNEMÝ
**
**				ÖDEV NUMARASI..........: 1. PROJE
**				ÖÐRENCÝ ADI............: ÝLYAS KALFA	
**				ÖÐRENCÝ NUMARASI.......: G211210056
**              DERSÝN ALINDIÐI GRUP...: 1-A
****************************************************************************/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
void ciz();

std::vector<std::string> split(const std::string& str, char delimiter) {        //DEPODAKÝ DEÐERLÝER ' ' ÞEKLÝNDE BÖLERMEK ÝÇÝN FONKSÝYON
	std::vector<std::string> result;
	std::string current;

	for (char c : str) {
		if (c == delimiter) {
			result.push_back(current);
			current.clear();
		}
		else {
			current += c;
		}
	}

	if (!current.empty()) {
		result.push_back(current);
	}

	return result;
}



class Yemek {                             // Yemek ile ilgili Bilgiler Tutulacak
public:
	string yemekadi;
	int yemeksatisfiyati;
	int yemekuretimFiyati;
	string malzeme;

};


class Urun {                                    // Ürün ile ilgili Bilgiler Tutulacak
public:
	string urunKodu;
	string urunAdi;
	string uretimTarihi;
	string sonKullanmaTarihi;
	float kaloriGram;
	float stokAdet;
	float fiyat;
	string tedarik;
	void urunGir();
	void urunYazdir();
};



class Restoran {                                // Restoran ile ilgili Bilgiler Tutulacak
public:
	
	Urun urunler[100];
	Yemek yemekler[100];
	Yemek malzemeler[100];

	void urunSilme();
	void urunEkle();
	void urunGuncelleme();
	void urunListele();
	int sayac = 0;
	int uretim_ucreti[100], satis_ucreti[100], kar[100], kisiSayisi[100];
	int urunSayisi, yemekSayisi, malzemeSayisi;
	Restoran() {
		urunSayisi = 0;
		yemekSayisi = 0;
		malzemeSayisi = 0;
	}

};

int main() {
	// main ekraný yüklenince bu dosyalarý siler
	remove("kullanilanmalzeme.txt");   
	remove("uretilenyemek.txt");

	int satisfiyati;  // yemek satýþ fiyatý
	int uretimfiyati; // yemek üretim fiyatý

	string yemek;  //yemekekle

	string yemek_ismi; //yemekekle
	string malzemeler;  //yemekekle
	string yemek_sil;// yemeksil
	string eski_yemek_ismi;//yemekguncelle
	string yeni_yemek_ismi;//yemekguncelle
	string yemeklistele;//yemeklistele
	bool control = true;
	int uretme;       // kaç yemek üreteceksin
	int alma;   // kaç yemek alýcaksan o
	Restoran u1;
	Urun u2;
	int secim;
	setlocale(LC_ALL, "Turkish");
	while (control) {
		do {
			cout << "\n      -------------------------------" << endl;
			cout << "\n      Restorantýmýza Hoþgeliniz..." << endl;
			cout << "\n      -------------------------------" << endl;
			cout << "\n      Yapmak Ýstediðiniz Ýþlemi Seçiniz:" << endl;
			cout << "\n      1-)Depo Üzerinde Ýþlem Yapma " << endl;
			cout << "\n      2-)Yemek  Üzerinde Ýþlem Yapma " << endl;
			cout << "\n      3-)Genel Ýþlemler ( YEMEK ÜRETÝMÝ , YEMEK SATIÞI , KAR/ZARAR BELÝRLEME ) " << endl;
			cin >> secim;
			system("cls");
		} while (!(secim >= 1 && secim < 4));
	    if (secim == 1) {
				int sec;
				cout << "\n      1-)Depoya Ürün Ekleme..." << endl;
				cout << "\n      2-)Depoya Ürün Silme..." << endl;
				cout << "\n      3-)Depoya Ürün Güncelleme..." << endl;
				cout << "\n      4-)Depoya Ürün Rapor Alma ..." << endl;
			
				cin >> sec;
				if (sec == 1) {
					u1.urunEkle();         // Ürün Ekle Fonksiyonu Çaðýrýlýyor
				}
				if (sec == 2) {
					u1.urunSilme();         // Ürün Ekle Silme Çaðýrýlýyor
				}
				if (sec == 3) {
					u1.urunGuncelleme();         // Ürün Ekle Güncelleme Çaðýrýlýyor
				}
				if (sec == 4)
				{
					u1.urunListele();         // Ürün Ekle Listele Çaðýrýlýyor
				}
		}
		// yemek classý
		   else if (secim == 2) {
			cout << "\n      1-)Yemek Ekleme..." << endl;
			cout << "\n      2-)Yemek Silme..." << endl;
			cout << "\n      3-)Yemek Güncelleme..." << endl;
			cout << "\n      4-Yemek Hakkýnda Rapor Alma ..." << endl;
			cout << "\n      5-)Çýkýþ ..." << endl;
			int sec;
			cin >> sec;
			fstream yemek_dosya;
			fstream malzeme_dosya;
			string yemek;
			string malzeme;
			// yemekEkle()
			if (sec == 1) {
				cin.ignore();
				cout << "Yemek ismini girin: ";
				string yemek_ismi;
				getline(cin, yemek_ismi);
				
				// Yemek ismini dosyaya yazýn
				ofstream dosya("yemekcesit.txt", ios::app);
				dosya << yemek_ismi << endl;
				dosya.close();

				
				cout << "Yemeðin Satýþ Fiyatýný Giriniz:" << endl;
				cin >> satisfiyati;
				cout << "Yemeðin Üretim Fiyatýný Giriniz:" << endl;
				cin >> uretimfiyati;
				ofstream dosyafiyat("yemekfiyatlari.txt", ios::app);
				dosyafiyat << satisfiyati << " " << uretimfiyati << endl;
				dosyafiyat.close();


				cin.ignore();
				// Malzemeleri alýn
				cout << "Malzemeleri girin (; ile ayýrýn): ";
				string malzemeler;
				getline(cin, malzemeler);

				// Malzemeleri dosyaya yazýn
				dosya.open("malzeme.txt", ios::app);
				dosya <<yemek_ismi<<" : " << malzemeler << endl;
				dosya.close();


			}
			//yemekSil()
			if (sec == 2) {
				cin.ignore();
				// Yemek ismini alýn
				cout << "Silinecek yemek ismini girin: ";
				string yemek_sil;
				getline(cin, yemek_sil);
				// Dosyalarý okuyun ve verileri vectorler içine saklayýn
				ifstream dosya1("yemekcesit.txt");
				ifstream dosya2("malzeme.txt");
				string satir;
				vector<string> yemekler;
				vector<string> malzemeler;
				while (getline(dosya1, satir)) {
					if (satir != yemek_sil) {
						yemekler.push_back(satir);
					}
				}
				while (getline(dosya2, satir)) {
					if (satir.find(yemek_sil) == string::npos) {
						malzemeler.push_back(satir);
					}
				}
				dosya1.close();
				dosya2.close();

				// Vectorlerdeki verileri dosyalara yazýn
				ofstream dosya3("yemekcesit.txt");
				ofstream dosya4("malzeme.txt");

				for (string yemek : yemekler) {
					dosya3 << yemek << endl;
				}
				for (string malzeme : malzemeler) {
					dosya4 << malzeme << endl;
				}
			}
			//yemekGuncelle()
			if (sec == 3) {
				cin.ignore();
				cout << "Güncellenecek yemek ismini girin: ";
				getline(cin, eski_yemek_ismi);
				// Yeni yemek ismini alýn
				cout << "Yeni yemek ismini girin: ";
				getline(cin, yeni_yemek_ismi);
				// Dosyayý okuyun ve verileri vector içine saklayýn
				ifstream dosya("yemekcesit.txt");
				string satir;
				vector<string> yemekler;
				while (getline(dosya, satir)) {
					if (satir == eski_yemek_ismi) {
						yemekler.push_back(yeni_yemek_ismi);
					}
					else {
						yemekler.push_back(satir);
					}
				}
				dosya.close();
				// Vectordeki verileri dosyaya yazýn
				ofstream dosya2("yemekcesit.txt");
				for (string yemek : yemekler) {
					dosya2 << yemek << endl;
				}
				dosya2.close();
			}
			//yemekListele()
			if (sec == 4) {
				cin.ignore();
				cout << "YEMEKLER:" << endl;
				ciz();
				ifstream dosya("yemekcesit.txt");

				while (getline(dosya, yemeklistele)) {
					cout << yemeklistele << endl;
				}
				dosya.close();
				ciz();
				cout << "MALZEMELER:" << endl;
				ifstream dosya1("malzeme.txt");
				string malzeme;
				while (getline(dosya1, malzeme)) {
					cout << malzeme << endl;
				}
				ciz();
				dosya1.close();
			}
		}
		// genelisler classý
		else if (secim == 3) {
		    cout<< " \n     UYARI!!! YEMEK ÜRETÝP YEMEK SAT" << endl;
			cout << "\n     1-) Günlük Yemek Üretimi Belirleme" << endl;
			cout << "\n     2-) Üretilen Yemeklerden Satýþ Yapma" << endl;
			cout << "\n     3-) Satýþ Kar Zarar Belirleme" << endl;
			int sec;
			cin >> sec;
			//gunlukYemekuretimi()
			if (sec == 1) {
				cout << "Olan Yemeklerden Kaç Tane Üretmek Ýster siniz?:" << endl;
				cin >> uretme;   // a = yemek üretim sayisi

				std::ifstream input_file("depo.txt");
				std::ofstream output_file("yeni_depo.txt");              //DEPODAN EKSÝLÝNCE OLUÞACAK TXT

				// dosyadaki satýrlarý okumak için bir string deðiþkeni oluþturun
				std::string p_line;
				std::vector<std::string> values = split(p_line, ' ');
				// dosyayý satýr satýr okuyarak iþlemleri gerçekleþtirin
				while (std::getline(input_file, p_line)) {
					// satýrý parçalara ayýrýn ve deðerleri okuyun
					std::vector<std::string> values = split(p_line, ' ');
					std::string name = values[0];
					string a = values[1];
					int b = std::stoi(values[2]);
					int c = std::stoi(values[3]);
					int d = std::stoi(values[4]);
					int e = std::stoi(values[5]);
					std::string f = values[6];
					string g = values[7];
					// iþlemleri gerçekleþtirin
					e -= uretme;

					// dosyaya yazdýrýn
					output_file << name << " " << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl;   // EKSÝLMÝÞ ÞEKÝLDE YENÝ TXT YE YAZIYOR
				}
				ifstream dosyaOku("malzeme.txt");
				if (!dosyaOku.is_open())
				{
					cerr << "Dosya açýlamadý!" << endl;
					return 1;
				}
				// Dosyayý yazmak için ofstream nesnesi oluþturun ve dosyayý açýn
				ofstream dosyaYaz("kullanilanmalzeme.txt", ios::out | ios::in | ios::app);
				if (!dosyaYaz.is_open())
				{
					cerr << "Dosya açýlamadý!" << endl;
					return 1;
				}
				// Dosyadaki tüm satýrlarý okuyun ve sayýlarý bulun
				string satir;
				while (getline(dosyaOku, satir))
				{
					// Satýrý parçalayýn
					stringstream ss(satir);
					string parca;
					while (getline(ss, parca, ' '))
					{
						// Parçayý sayý mý yoksa kelime mi olduðunu kontrol edin
						if (isdigit(parca[0]))
						{
							// Sayý ise, sayýyý int deðiþkenine dönüþtürün ve 2 ile çarpýn
							int sayi = stoi(parca);
							int carpim = sayi * uretme;

							// Çarpýmý string deðiþkene dönüþtürün ve dosyaya yazýn
							string carpimStr = to_string(carpim);
							dosyaYaz << carpimStr << " ";
						}
						else
						{
							// Kelime ise, dosyaya yazýn
							dosyaYaz << parca << " ";
						}
					}
					dosyaYaz << endl;
				}
				cout << "Yemeklerin Üretiminde Kullanýlacak Malzemeler uretilen.txt ye Yazýldý Malzemeleri yine de Görmek Ýster misinz (E/H)" << endl;
				char cevap;
				cin >> cevap;
				if (cevap == 'E' || cevap == 'e') {

					ifstream dosya("kullanilanmalzeme.txt");  // malzemelerdir
					// Dosyadaki tüm satýrlarý okuyun ve ekrana yazdýrýn
					string satir;
					while (getline(dosya, satir))
						cout << satir << endl;

					// Dosyayý kapatýn ve ifstream nesnesini yok edin
					dosya.close();
				}
				// Dosyalarý kapatýn
				dosyaOku.close();
				dosyaYaz.close();

				ifstream inputFile("yemekcesit.txt");
				ofstream outputFile("uretilenyemek.txt");

				std::string line;
				while (getline(inputFile, line))
				{
					outputFile << uretme << " " << line << endl;
				}
				inputFile.close();
				outputFile.close();
				cout << "Üretilen Yemek Sayýsý uretilenyemek.txt ye yazýldý Yazýlan Yemekleri Görmek Ýster misiniz?" << endl;
				char cevapp;
				cin >> cevapp;
				if (cevapp == 'E' || cevapp == 'e') {

					ifstream dosya("uretilenyemek.txt");
					// Dosyadaki tüm satýrlarý okuyun ve ekrana yazdýrýn
					string satir;
					while (getline(dosya, satir))
						cout << satir << endl;

					// Dosyayý kapatýn ve ifstream nesnesini yok edin
					dosya.close();
				}
			}
			//yemekSatis()
			if (sec == 2) {
				cout << "FÝYAT LÝSTESÝNÝ GÖRMEK ÝSTER MÝSÝNÝZ (E/H)...:" << endl;
				char cevapver;
				cin >> cevapver;
				if (cevapver == 'e' || cevapver == 'E') {
					cout << "YEMEKLER:" << endl;
					ciz();
					ifstream dosya("yemekcesit.txt");

					while (getline(dosya, yemeklistele)) {
						cout << yemeklistele << endl;
					}
					dosya.close();
					ciz();
					cout << "FÝYATLAR:" << endl;
					ciz();
					ifstream m_dosya("yemekfiyatlari.txt");
					// Dosya açýlýrsa, dosyanýn her satýrýný okuyun
					string m_satir;
					while (getline(m_dosya, m_satir)) {
						// Sayýyý tutacak string'i oluþturun
						string sayi_str = "";
						// Satýrdaki her karakteri kontrol edin
						for (char c : m_satir) {
							// Karakter bir sayý ise, string'e ekleyin
							if (isdigit(c)) {
								sayi_str += c;
							}
							// Karakter sayý deðilse, string'i sayýya çevirin ve sayýyý ekrana yazdýrýn
							else {
								int sayi = stoi(sayi_str);
								cout << sayi << endl;
								break;
							}
						}
					}
					// Dosyayý kapatýn
					dosya.close();
					ciz();
				}
				int value;
				ifstream inputFile3("uretilenyemek.txt");
				string line3;
				while (getline(inputFile3, line3))
				{
					stringstream lineStream(line3);
					string firstElement;
					lineStream >> firstElement;
					if (isdigit(firstElement[0]))
					{
						value = stoi(firstElement);
					}
				}
				cout << "ELÝMÝZDE OLAN YEMEKLER:" << endl;
				ciz();
				ifstream dosya("uretilenyemek.txt");
				// Dosyadaki tüm satýrlarý okuyun ve ekrana yazdýrýn
				string satir;
				while (getline(dosya, satir))
					cout << satir << endl;

				// Dosyayý kapatýn ve ifstream nesnesini yok edin
				dosya.close();
				ciz();

				cout << "KAÇ TANE ALMAK ÝSTERSÝNÝZ:" << endl;

				cin >> alma;
				value = value - alma;

				if (value > 0) {
					remove("uretilenyemek.txt");

					std::ifstream inputFile("yemekcesit.txt");
					std::ofstream outputFile("uretilenyemek.txt");

					std::string line;
					while (std::getline(inputFile, line))
					{
						outputFile << value << " " << line << std::endl;
					}

					inputFile.close();
					outputFile.close();
					cout << "ELÝMÝZDE KALAN YEMEK:" << endl;
					ciz();
					ifstream dosya3("uretilenyemek.txt");
					// Dosyadaki tüm satýrlarý okuyun ve ekrana yazdýrýn
					string satir3;
					while (getline(dosya3, satir3))
						cout << satir3 << endl;

					// Dosyayý kapatýn ve ifstream nesnesini yok edin
					dosya3.close();
					ciz();
				}
				else if (value < 0) {
					cout << "ELÝMÝZDE ÝSTEDÝÐÝNÝZ MÝKTARDA YEMEK BULUNMUYOR.." << endl;
				}
			}
			//karBelirle()
			if (sec == 3) {
				cout << "Üretilen Yemekler...:" << endl;
				ifstream r_dosya("yemekcesit.txt");
				ciz();
				// Dosya açýlýrsa, dosyanýn her satýrýný okuyun ve ekrana yazýn
				string r_satir;
				while (getline(r_dosya, r_satir)) {
					// Satýra "a" ekleyin ve ekrana yazýn
					cout << uretme << " " << r_satir << endl;
				}

				// Dosyayý kapatýn
				r_dosya.close();
				ciz();
				cout << "Satýlan Yemekler...:" << endl;
				ifstream z_dosya("yemekcesit.txt");
				ciz();
				// Dosya açýlýrsa, dosyanýn her satýrýný okuyun ve ekrana yazýn
				string z_satir;
				while (getline(z_dosya, z_satir)) {
					// Satýra "10" ekleyin ve ekrana yazýn
					cout << alma << " " << z_satir << endl;
				}
				ciz();
				cout << "ELÝMÝZDE Kalan YEMEKLER:" << endl;
				ciz();
				ifstream k_dosya("uretilenyemek.txt");
				// Dosyadaki tüm satýrlarý okuyun ve ekrana yazdýrýn
				string k_satir;
				while (getline(k_dosya, k_satir))
					cout << k_satir << endl;

				// Dosyayý kapatýn ve ifstream nesnesini yok edin
				k_dosya.close();
				ciz();
				int maliyet;
				int x, y;
				cout << "YEMEKLERÝN ÜRETÝMÝNDE RESTORANTA OLAN MALÝYETÝ...:" << endl;
				ciz();
				int total = 0; // Toplam deðiþkenini 0 olarak baþlatýyoruz

				ifstream input("yemekfiyatlari.txt"); // yemekfiyatlari.txt dosyasýný açýyoruz

				while (input >> x >> y) // dosya sonuna kadar okuma yapar
				{
					total += y; // toplam deðiþkenine x deðerini ekliyoruz
				}

				input.close(); // dosyayý kapatýyoruz

				maliyet = uretme * total;
				cout << maliyet << endl;
				ciz();
				cout << "RESTORANTIN SATILAN YEMEKLERDEN KARI (SATILAN YEMEK - ÜRETÝLEN YEMEK)" << endl;
				int r_total = 0; // Toplam deðiþkenini 0 olarak baþlatýyoruz

				ifstream r_input("yemekfiyatlari.txt"); // yemekfiyatlari.txt dosyasýný açýyoruz

				while (r_input >> x >> y) // dosya sonuna kadar okuma yapar
				{
					r_total += x; // toplam deðiþkenine x deðerini ekliyoruz
				}

				r_input.close(); // dosyayý kapatýyoruz


				int kar;
				kar = (alma * r_total) - (maliyet);
				cout << kar << endl;
				ciz();
			}
		}
	}
	
}
		
	



void ciz() {
	cout << "-----------------------------------------------" << endl;
}



void Urun::urunGir() {
	cout << "Ürünün Kodu..:" << endl;
	cin >> urunKodu;
	cout << "Ürünün Adý..:" << endl;
	cin >> urunAdi;
	cout << "Ürünün Üretim Tarihi..:" << endl;
	cin >> uretimTarihi;
	cout << "Ürünün Son Kullanma Tarihi..:" << endl;
	cin >> sonKullanmaTarihi;
	cout << "Ürünün Kalorisi..:" << endl;
	cin >> kaloriGram;
	cout << "Ürünün Stok Adedi..:" << endl;
	cin >> stokAdet;
	cout << "Ürünün Fiyatý..:" << endl;
	cin >> fiyat;
	cout << "Ürünün Tedarikçisi ..:" << endl;
	cin >> tedarik;

}

void Urun::urunYazdir() {
	cout << "Ürünün Kodu..:" << urunKodu << endl;
	cout << "Ürünün Adý..:" << urunAdi << endl;
	cout << "Ürünün Üretim Tarihi..:" << uretimTarihi << endl;
	cout << "Ürünün Son Kullanma Tarihi..:" << sonKullanmaTarihi << endl;
	cout << "Ürünün Kalorisi..:" << kaloriGram << endl;
	cout << "Ürünün Stok Adedi..:" << stokAdet << endl;
	cout << "Ürünün Fiyatý..:" << fiyat << endl;
	cout << "Ürünün Tedarikçisi ..:" << tedarik << endl;
}

void Restoran::urunEkle() {

	bool kontrol = true; //urun varlýðýný kontrol etmekiçin

	urunler[urunSayisi].urunGir(); //girilen ürün bilgileri urunler dizisinde tutulur

	Urun temp = urunler[urunSayisi]; //urunler dizisinde tutulan bilgiler temp nesnesine atanýr
	Urun temp1;

	fstream depo;

	depo.open("depo.txt", ios::out | ios::in | ios::app); //depo.txt dosyasýný okuma ve ekleme modunda açar
	//while sorgusu içindeki ifade urun.txt dosyasýndan karakter okunabildiði sürece true döndürür ve döngüyü saðlar
	while (depo >> temp1.urunKodu >> temp1.urunAdi >> temp1.uretimTarihi
		>> temp1.sonKullanmaTarihi >> temp1.kaloriGram >> temp1.stokAdet >> temp1.fiyat >> temp1.tedarik)
	{
		if (temp1.urunKodu == temp.urunKodu)//girilen ürün kodu urun.txt de yazýlý ise kontrol=false atamasý yapýlýr 
		{
			cout << "zaten kayýtlý!.." << endl;
			kontrol = false;
			depo.close(); //dosya kapatýlýr
			break;
		}
	}
	depo.close(); //dosya kapatýlýr

	if (kontrol)  
	{
		depo.open("depo.txt", ios::out | ios::in | ios::app);  //depo.txt dosyasýný okuma ve ekleme modunda açar
		depo << temp.urunKodu
			<< " " << temp.urunAdi
			<< " " << temp.uretimTarihi
			<< " " << temp.sonKullanmaTarihi
			<< " " << temp.kaloriGram
			<< " " << temp.stokAdet
			<< " " << temp.fiyat
			<< " " << temp.tedarik
			<< endl;
		depo.close();  //dosya kapatýlýr
	}
}

void Restoran::urunGuncelleme() {

	fstream depo, gecici;
	string kod;
	Urun temp;
	bool kontrol = true;  //güncellenecek ürünün eþlendiðini kontrol etmek için

	cout << "urun kodu giriniz: ";
	cin >> kod;

	depo.open("depo.txt", ios::out | ios::in | ios::app);  //depo.txt okuma, yazma ve ekleme modunda açýlýr
	gecici.open("temp.txt", ios::out | ios::in | ios::app); //temp.txt oluþturulur ve okuma, yazma ve ekleme modunda açýlýr

	//while sorgusu içindeki ifade depo.txt dosyasýndan karakter okunabildiði sürece true döndürür ve döngüyü saðlar
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		if (kod == temp.urunKodu) //girilen kod ile okunan eþleþirse ürün bilgileri tekrar alýr ve temp.txt ye yazar kontrol=false atamasý yapýlýr
		{
			kontrol = false;


			cout << "Ürünün Kodu..:" << endl;
			cin >> temp.urunKodu;
			cout << "Ürünün Adý..:" << endl;
			cin >> temp.urunAdi;
			cout << "Ürünün Üretim Tarihi..:" << endl;
			cin >> temp.uretimTarihi;
			cout << "Ürünün Son Kullanma Tarihi..:" << endl;
			cin >> temp.sonKullanmaTarihi;
			cout << "Ürünün Kalorisi..:" << endl;
			cin >> temp.kaloriGram;
			cout << "Ürünün Stok Adedi..:" << endl;
			cin >> temp.stokAdet;
			cout << "Ürünün Fiyatý..:" << endl;
			cin >> temp.fiyat;
			cout << "Ürünün Tedarikçisi ..:" << endl;
			cin >> temp.tedarik;



			//dosyaya yazma iþlemi
			gecici << temp.urunKodu
				<< " " << temp.urunAdi
				<< " " << temp.uretimTarihi
				<< " " << temp.sonKullanmaTarihi
				<< " " << temp.kaloriGram
				<< " " << temp.stokAdet
				<< " " << temp.fiyat
				<< " " << temp.tedarik
				<< endl;
		}
		else//kodun eþleþmemesi durumunda okunan bilgiler temp.txt ye yazýlýr
		{
			gecici << temp.urunKodu
				<< " " << temp.urunAdi
				<< " " << temp.uretimTarihi
				<< " " << temp.sonKullanmaTarihi
				<< " " << temp.kaloriGram
				<< " " << temp.stokAdet
				<< " " << temp.fiyat
				<< " " << temp.tedarik
				<< endl;
		}
	}
	depo.close();
	gecici.close();
	//açýlan dosyalarýn kapatýlmasý

	remove("depo.txt"); //depo.txt silinir
	rename("temp.txt", "depo.txt"); //temp.txt ye depo.txt adý verilir

	if (kontrol) //kontrol = false atamasý yapýlmamýþsa hata mesajýný ekrana yazdýrýr
		cout << "ürün bulunamadý!.." << endl;
}

void Restoran::urunSilme() {
	fstream depo, gecici;
	string kod;
	Urun temp;
	bool kontrol = true;  //silinecek ürünün eþlendiðini kontrol etmek için

	cout << "urun kodu giriniz: ";
	cin >> kod;

	depo.open("depo.txt", ios::out | ios::in | ios::app);   //depo.txt okuma, yazma ve ekleme modunda açýlýr
	gecici.open("temp.txt", ios::out | ios::in | ios::app);  //temp.txt okuma, yazma ve ekleme modunda açýlýr
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		if (kod == temp.urunKodu)  //girilen kod eþleþtiyse bu ürünü temp.txt yazdýrmadan atlayacaktýr
		{
			kontrol = false; //kontrol deðiþkenine false deðerini atar
			continue;
		}
		else //girilen kod eþleþmediyse okunan ürün aynen temp.txt ye yazýlýr
		{
			gecici << temp.urunKodu
				<< " " << temp.urunAdi
				<< " " << temp.uretimTarihi
				<< " " << temp.sonKullanmaTarihi
				<< " " << temp.kaloriGram
				<< " " << temp.stokAdet
				<< " " << temp.fiyat
				<< " " << temp.tedarik
				<< endl;
		}
	}
	depo.close();
	gecici.close();

	remove("depo.txt");  //depo.txt yi siler
	rename("temp.txt", "depo.txt"); //temp.txt yi depo.txt olarak deðiþtirir

	if (kontrol)  //girilen kod herhangi bir ürünün kodu deðilse hata mesajý verir
		cout << "ürün bulunamadý!.." << endl;
	else
		cout << "ürün silindi.." << endl;

}

void Restoran::urunListele() {

	Urun temp;
	ifstream depo("depo.txt");//depo.txt nin okuma için açýlmasý

	//while sorgusu içindeki ifade depo.txt dosyasýndan karakter okunabildiði sürece true döndürür ve döngüyü saðlar
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		temp.urunYazdir(); //urun bilgilerini ekrana yazdýrýr
		ciz(); //ciz fonk. çaðrýlýr
	}
	depo.close();//dosyanýn kapatýlmasý
}