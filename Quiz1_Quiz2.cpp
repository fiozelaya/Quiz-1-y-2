/*

Quiz 1 y 2 - Analisis de Algoritmos
02/03/2022

Fiorella Zelaya Coto
2021453615

*/

#include <iostream>
#include <vector>

using namespace std;

//enum para identificar el objeto Media
enum class TMedia {IMAGEN, VIDEO, AUDIO};

//definician de clase Media
class Media{
    private:
    TMedia tipo;
    string URL;
    public:
    Media(){
        
    }
    Media(TMedia pTipo, string pURL){
        tipo = pTipo;
        URL = pURL;
    }
    void toString(){
        string tipoMedia = "";
        switch(tipo){
            case TMedia::IMAGEN:
            tipoMedia = "Imagen";
            break;
            case TMedia::AUDIO:
            tipoMedia = "Audio";
            break;
            case TMedia::VIDEO:
            tipoMedia = "Video";
            break;
        }

        cout << "Tipo de archivo: " << tipoMedia << "\nLink del archivo: " << URL << endl;
    }
};

//definician de clase Noticia
class Noticia {
    public:
    Noticia(){
        titulo = "";
        fecha = "";
        reportero = "";
    }
    void setDatos(string t, string f, string r){
        titulo = t;
        fecha = f;
        reportero = r;
    }
    virtual void getInfo() = 0;
    protected:
    string titulo;
    string fecha;
    string reportero;
};

//definician de clase NoticiaPaper
class NoticiaPaper: public Noticia{
    public:
    NoticiaPaper(){
        ruta = "";
    }
    NoticiaPaper(string r){
        ruta = r;
    }
    virtual void getInfo(){
        cout << "Imprimiendo informacion de NoticiaPaper..." << endl;
        cout << "Titulo: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << endl;
        cout << "URL de imagen: " << ruta << endl;
    }
    private:
    string ruta;
};

//definician de clase NoticiaDigital
class NoticiaDigital: public Noticia{
    public:
    NoticiaDigital(vector<Media*> media_){
        media = media_;
    }
    virtual void getInfo(){
        cout << "Imprimiendo informacion de NoticiaDigital..." << endl;
        cout << "Titulo: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << "\n\nArchivos media:" << endl;
        
        for (Media* PtrMedia: media){
            PtrMedia->toString();
            cout << endl;
        }
    }
    private:
    vector<Media*> media;
};

//definician de clase NoticiaRadio
class NoticiaRadio: public Noticia{
    public:
    NoticiaRadio(){
        URL = "";
    }
    NoticiaRadio(string url){
        URL = url;
    }
    //definician del metodo abstracto getInfo
    virtual void getInfo(){
        cout << "Imprimiendo informacion de NoticiaRadio..." << endl;
        cout << "Titulo: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << endl;
        cout << "URL de audio: " << URL << endl;
    }
    private:
    string URL;
};

int main(){
    //lista de archivos media
    Media m1(TMedia::VIDEO, "https://www.youtube.com/watch?v=CUUy12SlmFM");
    Media m2(TMedia::IMAGEN, "https://www.nacion.com/resizer/vxbRNG3LTL5wgw1xYVh7S1aMRnM=/1440x0/filters:format(jpg):quality(70)/cloudfront-us-east-1.images.arcpublishing.com/gruponacion/NVAV4CCGMZFJFOUR5FYAKGFOZU.jpg");
    Media m3(TMedia::IMAGEN, "https://www.nacion.com/resizer/Hdzt3IXErrdWBvF2soYSJ-TRQ2w=/1440x0/filters:format(jpg):quality(70)/cloudfront-us-east-1.images.arcpublishing.com/gruponacion/AHIWMIGLVZG47FWB7OE6P4SXZ4.jpg");
    Media m4(TMedia::AUDIO, "https://www.google.com/podcasts?feed=aHR0cHM6Ly93d3cucmZpLmZyL2VzL3Byb2dyYW1hcy9ub3RpY2lhcy1hbWVyaWNhL3BvZGNhc3Q");
    vector<Media*> media = {&m1, &m2, &m3, &m4};

    //instanciacian de noticias y creacian de lista de noticias
    NoticiaPaper noticia1("https://www.nacion.com/resizer/d-i9KuY5vr2LlAfSpHYBAyn47P0=/1440x0/filters:format(png):quality(70)/cloudfront-us-east-1.images.arcpublishing.com/gruponacion/TXGB5FBOCFBLDGYVDZVIJ7GV3Q.png");
    NoticiaDigital noticia2(media);
    NoticiaRadio noticia3("https://www.abc.es/voz/noticias-del-dia/abci-escucha-noticias-abc-noche-2022-202203012211-2_7960_audio.html");

    noticia1.setDatos("ICE rebaja servicio de Internet con fibra aptica para seducir a clientes", "2 de marzo 2022, 8:08 AM", "Juan Fernando Lara S.");
    noticia2.setDatos("Rusia—Ucrania: Joe Biden no descarta sanciones contra importaciones de petraleo ruso", "2 de marzo 2022, 12:40 PM", "AFP y Fatima Jimanez Quiras");
    noticia3.setDatos("El 80 por ciento de las tropas rusas ya estan en sobre suelo ucraniano, pero no avanzan por problemas de suministro", "01/03/2022 22:11h", "ABC");

    vector<Noticia*> vector = {&noticia1, &noticia2, &noticia3};

    //se imprime el getInfo de cada objeto Noticia
    cout << "Imprimiendo noticias en la lista de noticias...\n" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for(Noticia* PtrNoticia: vector){
        PtrNoticia->getInfo();
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        
    }

    return 0; 
}