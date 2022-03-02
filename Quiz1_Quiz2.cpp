#include <iostream>
#include <vector>

using namespace std;

class INoticia{
    public:
    INoticia(){}
    
};

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

class NoticiaPaper: public Noticia{
    public:
    NoticiaPaper(){
        ruta = "";
    }
    NoticiaPaper(string r){
        ruta = r;
    }
    virtual void getInfo(){
        cout << "Imprimiendo información de NoticiaPaper..." << endl;
        cout << "Título: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << endl;
        cout << "Ruta: " << ruta << endl;
    }
    private:
    string ruta;
};

class NoticiaDigital: public Noticia{
    public:
    NoticiaDigital(vector<string> media_){
        media = media_;
    }
    virtual void getInfo(){
        cout << "Imprimiendo información de NoticiaDigital..." << endl;
        cout << "Título: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << "\nImprimiendo archivos media..." << endl;
        
        for (int i = 0; i < 5; i++){
            cout << media[i] << endl;
        }
    }
    private:
    vector<string> media;
};

class NoticiaRadio: public Noticia{
    public:
    NoticiaRadio(){
        URL = "";
    }
    NoticiaRadio(string url){
        URL = url;
    }
    virtual void getInfo(){
        cout << "Imprimiendo información de NoticiaRadio..." << endl;
        cout << "Título: " << titulo << "\nFecha: " << fecha << "\nReportero: " << reportero << endl;
        cout << "URL: " << URL << endl;
    }
    private:
    string URL;
};

int main(){
    //  Noticia *vector[3];

    //  string media[5] = {"Video1", "Imagen1", "Video2", "Audio1", "Video3"};
    //  vector[0]= new NoticiaPaper("images/foto.png");
    //  vector[0]->setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");
    //  vector[1]= new NoticiaDigital(media);
    //  vector[1]->setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");
    //  vector[2]= new NoticiaRadio("images/audio.mp3");
    //  vector[2]->setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");

    //  for(int i = 0; i < 3; i++){
    //      vector[i]->getInfo();
    //      cout << endl;
    //  }

     vector<string> media = {"Video1", "Imagen1", "Video2", "Audio1", "Video3"};
     NoticiaPaper noticia1("images/foto.png");
     NoticiaDigital noticia2(media);
     NoticiaRadio noticia3("images/audio.mp3");

     noticia1.setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");
     noticia2.setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");
     noticia3.setDatos("Titulo", "Fecha", "Fiorella Zelaya Coto");

     vector<Noticia*> vector = {&noticia1, &noticia2, &noticia3};

     for(Noticia* PtrNoticia: vector){
         PtrNoticia->getInfo();
         cout << endl;
     }

 
    return 0; 
}