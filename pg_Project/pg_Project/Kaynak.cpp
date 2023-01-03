/****************************************************************************
**					SAKARYA �N�VERS�TES�
**				B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				   NESNEYE DAYALI PROGRAMLAMA DERS�
**					2022-2023 BAHAR D�NEM�
**
**				�DEV NUMARASI..........: 1. PROJE
**				��RENC� ADI............: �LYAS KALFA	
**				��RENC� NUMARASI.......: G211210056
**              DERS�N ALINDI�I GRUP...: 1-A
****************************************************************************/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
void ciz();

std::vector<std::string> split(const std::string& str, char delimiter) {        //DEPODAK� DE�ERL�ER ' ' �EKL�NDE B�LERMEK ���N FONKS�YON
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


class Urun {                                    // �r�n ile ilgili Bilgiler Tutulacak
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
	// main ekran� y�klenince bu dosyalar� siler
	remove("kullanilanmalzeme.txt");   
	remove("uretilenyemek.txt");

	int satisfiyati;  // yemek sat�� fiyat�
	int uretimfiyati; // yemek �retim fiyat�

	string yemek;  //yemekekle

	string yemek_ismi; //yemekekle
	string malzemeler;  //yemekekle
	string yemek_sil;// yemeksil
	string eski_yemek_ismi;//yemekguncelle
	string yeni_yemek_ismi;//yemekguncelle
	string yemeklistele;//yemeklistele
	bool control = true;
	int uretme;       // ka� yemek �reteceksin
	int alma;   // ka� yemek al�caksan o
	Restoran u1;
	Urun u2;
	int secim;
	setlocale(LC_ALL, "Turkish");
	while (control) {
		do {
			cout << "\n      -------------------------------" << endl;
			cout << "\n      Restorant�m�za Ho�geliniz..." << endl;
			cout << "\n      -------------------------------" << endl;
			cout << "\n      Yapmak �stedi�iniz ��lemi Se�iniz:" << endl;
			cout << "\n      1-)Depo �zerinde ��lem Yapma " << endl;
			cout << "\n      2-)Yemek  �zerinde ��lem Yapma " << endl;
			cout << "\n      3-)Genel ��lemler ( YEMEK �RET�M� , YEMEK SATI�I , KAR/ZARAR BEL�RLEME ) " << endl;
			cin >> secim;
			system("cls");
		} while (!(secim >= 1 && secim < 4));
	    if (secim == 1) {
				int sec;
				cout << "\n      1-)Depoya �r�n Ekleme..." << endl;
				cout << "\n      2-)Depoya �r�n Silme..." << endl;
				cout << "\n      3-)Depoya �r�n G�ncelleme..." << endl;
				cout << "\n      4-)Depoya �r�n Rapor Alma ..." << endl;
			
				cin >> sec;
				if (sec == 1) {
					u1.urunEkle();         // �r�n Ekle Fonksiyonu �a��r�l�yor
				}
				if (sec == 2) {
					u1.urunSilme();         // �r�n Ekle Silme �a��r�l�yor
				}
				if (sec == 3) {
					u1.urunGuncelleme();         // �r�n Ekle G�ncelleme �a��r�l�yor
				}
				if (sec == 4)
				{
					u1.urunListele();         // �r�n Ekle Listele �a��r�l�yor
				}
		}
		// yemek class�
		   else if (secim == 2) {
			cout << "\n      1-)Yemek Ekleme..." << endl;
			cout << "\n      2-)Yemek Silme..." << endl;
			cout << "\n      3-)Yemek G�ncelleme..." << endl;
			cout << "\n      4-Yemek Hakk�nda Rapor Alma ..." << endl;
			cout << "\n      5-)��k�� ..." << endl;
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
				
				// Yemek ismini dosyaya yaz�n
				ofstream dosya("yemekcesit.txt", ios::app);
				dosya << yemek_ismi << endl;
				dosya.close();

				
				cout << "Yeme�in Sat�� Fiyat�n� Giriniz:" << endl;
				cin >> satisfiyati;
				cout << "Yeme�in �retim Fiyat�n� Giriniz:" << endl;
				cin >> uretimfiyati;
				ofstream dosyafiyat("yemekfiyatlari.txt", ios::app);
				dosyafiyat << satisfiyati << " " << uretimfiyati << endl;
				dosyafiyat.close();


				cin.ignore();
				// Malzemeleri al�n
				cout << "Malzemeleri girin (; ile ay�r�n): ";
				string malzemeler;
				getline(cin, malzemeler);

				// Malzemeleri dosyaya yaz�n
				dosya.open("malzeme.txt", ios::app);
				dosya <<yemek_ismi<<" : " << malzemeler << endl;
				dosya.close();


			}
			//yemekSil()
			if (sec == 2) {
				cin.ignore();
				// Yemek ismini al�n
				cout << "Silinecek yemek ismini girin: ";
				string yemek_sil;
				getline(cin, yemek_sil);
				// Dosyalar� okuyun ve verileri vectorler i�ine saklay�n
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

				// Vectorlerdeki verileri dosyalara yaz�n
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
				cout << "G�ncellenecek yemek ismini girin: ";
				getline(cin, eski_yemek_ismi);
				// Yeni yemek ismini al�n
				cout << "Yeni yemek ismini girin: ";
				getline(cin, yeni_yemek_ismi);
				// Dosyay� okuyun ve verileri vector i�ine saklay�n
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
				// Vectordeki verileri dosyaya yaz�n
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
		// genelisler class�
		else if (secim == 3) {
		    cout<< " \n     UYARI!!! YEMEK �RET�P YEMEK SAT" << endl;
			cout << "\n     1-) G�nl�k Yemek �retimi Belirleme" << endl;
			cout << "\n     2-) �retilen Yemeklerden Sat�� Yapma" << endl;
			cout << "\n     3-) Sat�� Kar Zarar Belirleme" << endl;
			int sec;
			cin >> sec;
			//gunlukYemekuretimi()
			if (sec == 1) {
				cout << "Olan Yemeklerden Ka� Tane �retmek �ster siniz?:" << endl;
				cin >> uretme;   // a = yemek �retim sayisi

				std::ifstream input_file("depo.txt");
				std::ofstream output_file("yeni_depo.txt");              //DEPODAN EKS�L�NCE OLU�ACAK TXT

				// dosyadaki sat�rlar� okumak i�in bir string de�i�keni olu�turun
				std::string p_line;
				std::vector<std::string> values = split(p_line, ' ');
				// dosyay� sat�r sat�r okuyarak i�lemleri ger�ekle�tirin
				while (std::getline(input_file, p_line)) {
					// sat�r� par�alara ay�r�n ve de�erleri okuyun
					std::vector<std::string> values = split(p_line, ' ');
					std::string name = values[0];
					string a = values[1];
					int b = std::stoi(values[2]);
					int c = std::stoi(values[3]);
					int d = std::stoi(values[4]);
					int e = std::stoi(values[5]);
					std::string f = values[6];
					string g = values[7];
					// i�lemleri ger�ekle�tirin
					e -= uretme;

					// dosyaya yazd�r�n
					output_file << name << " " << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << endl;   // EKS�LM�� �EK�LDE YEN� TXT YE YAZIYOR
				}
				ifstream dosyaOku("malzeme.txt");
				if (!dosyaOku.is_open())
				{
					cerr << "Dosya a��lamad�!" << endl;
					return 1;
				}
				// Dosyay� yazmak i�in ofstream nesnesi olu�turun ve dosyay� a��n
				ofstream dosyaYaz("kullanilanmalzeme.txt", ios::out | ios::in | ios::app);
				if (!dosyaYaz.is_open())
				{
					cerr << "Dosya a��lamad�!" << endl;
					return 1;
				}
				// Dosyadaki t�m sat�rlar� okuyun ve say�lar� bulun
				string satir;
				while (getline(dosyaOku, satir))
				{
					// Sat�r� par�alay�n
					stringstream ss(satir);
					string parca;
					while (getline(ss, parca, ' '))
					{
						// Par�ay� say� m� yoksa kelime mi oldu�unu kontrol edin
						if (isdigit(parca[0]))
						{
							// Say� ise, say�y� int de�i�kenine d�n��t�r�n ve 2 ile �arp�n
							int sayi = stoi(parca);
							int carpim = sayi * uretme;

							// �arp�m� string de�i�kene d�n��t�r�n ve dosyaya yaz�n
							string carpimStr = to_string(carpim);
							dosyaYaz << carpimStr << " ";
						}
						else
						{
							// Kelime ise, dosyaya yaz�n
							dosyaYaz << parca << " ";
						}
					}
					dosyaYaz << endl;
				}
				cout << "Yemeklerin �retiminde Kullan�lacak Malzemeler uretilen.txt ye Yaz�ld� Malzemeleri yine de G�rmek �ster misinz (E/H)" << endl;
				char cevap;
				cin >> cevap;
				if (cevap == 'E' || cevap == 'e') {

					ifstream dosya("kullanilanmalzeme.txt");  // malzemelerdir
					// Dosyadaki t�m sat�rlar� okuyun ve ekrana yazd�r�n
					string satir;
					while (getline(dosya, satir))
						cout << satir << endl;

					// Dosyay� kapat�n ve ifstream nesnesini yok edin
					dosya.close();
				}
				// Dosyalar� kapat�n
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
				cout << "�retilen Yemek Say�s� uretilenyemek.txt ye yaz�ld� Yaz�lan Yemekleri G�rmek �ster misiniz?" << endl;
				char cevapp;
				cin >> cevapp;
				if (cevapp == 'E' || cevapp == 'e') {

					ifstream dosya("uretilenyemek.txt");
					// Dosyadaki t�m sat�rlar� okuyun ve ekrana yazd�r�n
					string satir;
					while (getline(dosya, satir))
						cout << satir << endl;

					// Dosyay� kapat�n ve ifstream nesnesini yok edin
					dosya.close();
				}
			}
			//yemekSatis()
			if (sec == 2) {
				cout << "F�YAT L�STES�N� G�RMEK �STER M�S�N�Z (E/H)...:" << endl;
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
					cout << "F�YATLAR:" << endl;
					ciz();
					ifstream m_dosya("yemekfiyatlari.txt");
					// Dosya a��l�rsa, dosyan�n her sat�r�n� okuyun
					string m_satir;
					while (getline(m_dosya, m_satir)) {
						// Say�y� tutacak string'i olu�turun
						string sayi_str = "";
						// Sat�rdaki her karakteri kontrol edin
						for (char c : m_satir) {
							// Karakter bir say� ise, string'e ekleyin
							if (isdigit(c)) {
								sayi_str += c;
							}
							// Karakter say� de�ilse, string'i say�ya �evirin ve say�y� ekrana yazd�r�n
							else {
								int sayi = stoi(sayi_str);
								cout << sayi << endl;
								break;
							}
						}
					}
					// Dosyay� kapat�n
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
				cout << "EL�M�ZDE OLAN YEMEKLER:" << endl;
				ciz();
				ifstream dosya("uretilenyemek.txt");
				// Dosyadaki t�m sat�rlar� okuyun ve ekrana yazd�r�n
				string satir;
				while (getline(dosya, satir))
					cout << satir << endl;

				// Dosyay� kapat�n ve ifstream nesnesini yok edin
				dosya.close();
				ciz();

				cout << "KA� TANE ALMAK �STERS�N�Z:" << endl;

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
					cout << "EL�M�ZDE KALAN YEMEK:" << endl;
					ciz();
					ifstream dosya3("uretilenyemek.txt");
					// Dosyadaki t�m sat�rlar� okuyun ve ekrana yazd�r�n
					string satir3;
					while (getline(dosya3, satir3))
						cout << satir3 << endl;

					// Dosyay� kapat�n ve ifstream nesnesini yok edin
					dosya3.close();
					ciz();
				}
				else if (value < 0) {
					cout << "EL�M�ZDE �STED���N�Z M�KTARDA YEMEK BULUNMUYOR.." << endl;
				}
			}
			//karBelirle()
			if (sec == 3) {
				cout << "�retilen Yemekler...:" << endl;
				ifstream r_dosya("yemekcesit.txt");
				ciz();
				// Dosya a��l�rsa, dosyan�n her sat�r�n� okuyun ve ekrana yaz�n
				string r_satir;
				while (getline(r_dosya, r_satir)) {
					// Sat�ra "a" ekleyin ve ekrana yaz�n
					cout << uretme << " " << r_satir << endl;
				}

				// Dosyay� kapat�n
				r_dosya.close();
				ciz();
				cout << "Sat�lan Yemekler...:" << endl;
				ifstream z_dosya("yemekcesit.txt");
				ciz();
				// Dosya a��l�rsa, dosyan�n her sat�r�n� okuyun ve ekrana yaz�n
				string z_satir;
				while (getline(z_dosya, z_satir)) {
					// Sat�ra "10" ekleyin ve ekrana yaz�n
					cout << alma << " " << z_satir << endl;
				}
				ciz();
				cout << "EL�M�ZDE Kalan YEMEKLER:" << endl;
				ciz();
				ifstream k_dosya("uretilenyemek.txt");
				// Dosyadaki t�m sat�rlar� okuyun ve ekrana yazd�r�n
				string k_satir;
				while (getline(k_dosya, k_satir))
					cout << k_satir << endl;

				// Dosyay� kapat�n ve ifstream nesnesini yok edin
				k_dosya.close();
				ciz();
				int maliyet;
				int x, y;
				cout << "YEMEKLER�N �RET�M�NDE RESTORANTA OLAN MAL�YET�...:" << endl;
				ciz();
				int total = 0; // Toplam de�i�kenini 0 olarak ba�lat�yoruz

				ifstream input("yemekfiyatlari.txt"); // yemekfiyatlari.txt dosyas�n� a��yoruz

				while (input >> x >> y) // dosya sonuna kadar okuma yapar
				{
					total += y; // toplam de�i�kenine x de�erini ekliyoruz
				}

				input.close(); // dosyay� kapat�yoruz

				maliyet = uretme * total;
				cout << maliyet << endl;
				ciz();
				cout << "RESTORANTIN SATILAN YEMEKLERDEN KARI (SATILAN YEMEK - �RET�LEN YEMEK)" << endl;
				int r_total = 0; // Toplam de�i�kenini 0 olarak ba�lat�yoruz

				ifstream r_input("yemekfiyatlari.txt"); // yemekfiyatlari.txt dosyas�n� a��yoruz

				while (r_input >> x >> y) // dosya sonuna kadar okuma yapar
				{
					r_total += x; // toplam de�i�kenine x de�erini ekliyoruz
				}

				r_input.close(); // dosyay� kapat�yoruz


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
	cout << "�r�n�n Kodu..:" << endl;
	cin >> urunKodu;
	cout << "�r�n�n Ad�..:" << endl;
	cin >> urunAdi;
	cout << "�r�n�n �retim Tarihi..:" << endl;
	cin >> uretimTarihi;
	cout << "�r�n�n Son Kullanma Tarihi..:" << endl;
	cin >> sonKullanmaTarihi;
	cout << "�r�n�n Kalorisi..:" << endl;
	cin >> kaloriGram;
	cout << "�r�n�n Stok Adedi..:" << endl;
	cin >> stokAdet;
	cout << "�r�n�n Fiyat�..:" << endl;
	cin >> fiyat;
	cout << "�r�n�n Tedarik�isi ..:" << endl;
	cin >> tedarik;

}

void Urun::urunYazdir() {
	cout << "�r�n�n Kodu..:" << urunKodu << endl;
	cout << "�r�n�n Ad�..:" << urunAdi << endl;
	cout << "�r�n�n �retim Tarihi..:" << uretimTarihi << endl;
	cout << "�r�n�n Son Kullanma Tarihi..:" << sonKullanmaTarihi << endl;
	cout << "�r�n�n Kalorisi..:" << kaloriGram << endl;
	cout << "�r�n�n Stok Adedi..:" << stokAdet << endl;
	cout << "�r�n�n Fiyat�..:" << fiyat << endl;
	cout << "�r�n�n Tedarik�isi ..:" << tedarik << endl;
}

void Restoran::urunEkle() {

	bool kontrol = true; //urun varl���n� kontrol etmeki�in

	urunler[urunSayisi].urunGir(); //girilen �r�n bilgileri urunler dizisinde tutulur

	Urun temp = urunler[urunSayisi]; //urunler dizisinde tutulan bilgiler temp nesnesine atan�r
	Urun temp1;

	fstream depo;

	depo.open("depo.txt", ios::out | ios::in | ios::app); //depo.txt dosyas�n� okuma ve ekleme modunda a�ar
	//while sorgusu i�indeki ifade urun.txt dosyas�ndan karakter okunabildi�i s�rece true d�nd�r�r ve d�ng�y� sa�lar
	while (depo >> temp1.urunKodu >> temp1.urunAdi >> temp1.uretimTarihi
		>> temp1.sonKullanmaTarihi >> temp1.kaloriGram >> temp1.stokAdet >> temp1.fiyat >> temp1.tedarik)
	{
		if (temp1.urunKodu == temp.urunKodu)//girilen �r�n kodu urun.txt de yaz�l� ise kontrol=false atamas� yap�l�r 
		{
			cout << "zaten kay�tl�!.." << endl;
			kontrol = false;
			depo.close(); //dosya kapat�l�r
			break;
		}
	}
	depo.close(); //dosya kapat�l�r

	if (kontrol)  
	{
		depo.open("depo.txt", ios::out | ios::in | ios::app);  //depo.txt dosyas�n� okuma ve ekleme modunda a�ar
		depo << temp.urunKodu
			<< " " << temp.urunAdi
			<< " " << temp.uretimTarihi
			<< " " << temp.sonKullanmaTarihi
			<< " " << temp.kaloriGram
			<< " " << temp.stokAdet
			<< " " << temp.fiyat
			<< " " << temp.tedarik
			<< endl;
		depo.close();  //dosya kapat�l�r
	}
}

void Restoran::urunGuncelleme() {

	fstream depo, gecici;
	string kod;
	Urun temp;
	bool kontrol = true;  //g�ncellenecek �r�n�n e�lendi�ini kontrol etmek i�in

	cout << "urun kodu giriniz: ";
	cin >> kod;

	depo.open("depo.txt", ios::out | ios::in | ios::app);  //depo.txt okuma, yazma ve ekleme modunda a��l�r
	gecici.open("temp.txt", ios::out | ios::in | ios::app); //temp.txt olu�turulur ve okuma, yazma ve ekleme modunda a��l�r

	//while sorgusu i�indeki ifade depo.txt dosyas�ndan karakter okunabildi�i s�rece true d�nd�r�r ve d�ng�y� sa�lar
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		if (kod == temp.urunKodu) //girilen kod ile okunan e�le�irse �r�n bilgileri tekrar al�r ve temp.txt ye yazar kontrol=false atamas� yap�l�r
		{
			kontrol = false;


			cout << "�r�n�n Kodu..:" << endl;
			cin >> temp.urunKodu;
			cout << "�r�n�n Ad�..:" << endl;
			cin >> temp.urunAdi;
			cout << "�r�n�n �retim Tarihi..:" << endl;
			cin >> temp.uretimTarihi;
			cout << "�r�n�n Son Kullanma Tarihi..:" << endl;
			cin >> temp.sonKullanmaTarihi;
			cout << "�r�n�n Kalorisi..:" << endl;
			cin >> temp.kaloriGram;
			cout << "�r�n�n Stok Adedi..:" << endl;
			cin >> temp.stokAdet;
			cout << "�r�n�n Fiyat�..:" << endl;
			cin >> temp.fiyat;
			cout << "�r�n�n Tedarik�isi ..:" << endl;
			cin >> temp.tedarik;



			//dosyaya yazma i�lemi
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
		else//kodun e�le�memesi durumunda okunan bilgiler temp.txt ye yaz�l�r
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
	//a��lan dosyalar�n kapat�lmas�

	remove("depo.txt"); //depo.txt silinir
	rename("temp.txt", "depo.txt"); //temp.txt ye depo.txt ad� verilir

	if (kontrol) //kontrol = false atamas� yap�lmam��sa hata mesaj�n� ekrana yazd�r�r
		cout << "�r�n bulunamad�!.." << endl;
}

void Restoran::urunSilme() {
	fstream depo, gecici;
	string kod;
	Urun temp;
	bool kontrol = true;  //silinecek �r�n�n e�lendi�ini kontrol etmek i�in

	cout << "urun kodu giriniz: ";
	cin >> kod;

	depo.open("depo.txt", ios::out | ios::in | ios::app);   //depo.txt okuma, yazma ve ekleme modunda a��l�r
	gecici.open("temp.txt", ios::out | ios::in | ios::app);  //temp.txt okuma, yazma ve ekleme modunda a��l�r
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		if (kod == temp.urunKodu)  //girilen kod e�le�tiyse bu �r�n� temp.txt yazd�rmadan atlayacakt�r
		{
			kontrol = false; //kontrol de�i�kenine false de�erini atar
			continue;
		}
		else //girilen kod e�le�mediyse okunan �r�n aynen temp.txt ye yaz�l�r
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
	rename("temp.txt", "depo.txt"); //temp.txt yi depo.txt olarak de�i�tirir

	if (kontrol)  //girilen kod herhangi bir �r�n�n kodu de�ilse hata mesaj� verir
		cout << "�r�n bulunamad�!.." << endl;
	else
		cout << "�r�n silindi.." << endl;

}

void Restoran::urunListele() {

	Urun temp;
	ifstream depo("depo.txt");//depo.txt nin okuma i�in a��lmas�

	//while sorgusu i�indeki ifade depo.txt dosyas�ndan karakter okunabildi�i s�rece true d�nd�r�r ve d�ng�y� sa�lar
	while (depo >> temp.urunKodu >> temp.urunAdi >> temp.uretimTarihi
		>> temp.sonKullanmaTarihi >> temp.kaloriGram >> temp.stokAdet >> temp.fiyat >> temp.tedarik)
	{
		temp.urunYazdir(); //urun bilgilerini ekrana yazd�r�r
		ciz(); //ciz fonk. �a�r�l�r
	}
	depo.close();//dosyan�n kapat�lmas�
}