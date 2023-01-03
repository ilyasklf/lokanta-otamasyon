# lokanta-otamasyon

Depo.txt isimli bir dosya oluşturalım dosyaya yiyecek ve içecek ürünlerini kayıt edelim. 
Örneğin aşağıdakine benzer bir urun sınıfı oluşturarak dosyaya kayıtta bu sınıf nesneleri kullanılabilir.
Class Urun
{
Private:
String urunAdi;
Tarih UretimTarihi;
Tarih sonKullanmaTarihi;
Float kaloriGram
Float StokAdet;
Float fiyat;
….
}
Bu dosya üzerinde: Kayıt ekleme, kayıt silme, kayıt güncelleme ve rapor alma operasyonları yapılabilsin.
Restoran en az 20 farklı yemek çeşiti pişirsin.
İkinci bir dosya oluşturulsun(yemekcesit.txt”). Bu dosyaya en az yirmi yemek çeşiti eklensin yemek çeşiti için kullanılacak malzemeler (malzeme.txt) dosyasına kaydedilsin.
Bu iki dosya bir birine bağlı bir dosyadır. Yemekcesit dosyasına bir yemek eklendiğinde bu yemek için malzeme.txt dosyasına malzeme listeleri eklensin. Benzer şekilde bir yemek çeşiti silindiğinde bu dosyadan o yemeğe ait malzemelerde silinsin.
 Yemek çesiti ile ilgili: Kayıt ekleme, kayıt silme, kayıt güncelleme ve rapor alma operasyonları yapılabilsin.
Genel Yapılacaklar
1-Restoran günlük her bir yemek çesitinden yemek üretimi belirlesin (her bir yemekten kaç kişilik yemek).Bunun için gerekli malzeme çıkarılsın.  Malzeme stoktan öncelikle kullanılsın(depo.txt dosyası). Stokta olmayan veya yetersiz olan malzeme için sipariş listesi oluştursun.  Stoktan kullanılan malzemeler depo.txt dosyasından miktar veya kg olarak düşülsün. Her bir yemek için genel tutar ve kişi başı maliyet tutarı hesaplansın.
2- Üretilen yemeklerden gün içerisinde yemek satışı yapılsın. 
3- gün içerisinde üretilen yemek, satılan yemek. Maliyet ve kar ve elde kalan yemek raporu alınsın.
