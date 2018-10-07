#include <iostream>
using namespace std;

class server{

public:
    virtual void download(string source, string country){


    }

};


class realServer : public server{

private:
    int port;
    string address;

public:

    realServer(int p, string a){
        port = p;
        address = a;
        cout << "Initializing server "<< endl;
    }


    void download(string source, string country){

        cout << "downloading " << source << " from the server in "<< country <<endl;

    }
    string getAddress(){
        return address;
    }

};

class proxyServer : public server{



private:
    int port;
    string address;
    realServer server  = realServer(port, address);

public:
    proxyServer(int p, string a){
        port = p;
        address = a;
        cout << "Initializing Proxy "<< endl;
    }

    void download (string source, string country){

        if (country != "Costa Rica"){

            server.download(source, country);

        }else{
            cout << "In this country is not allowed to download this" << endl;

        }

    }


};


int main() {

    int numero;
    string pais;
    string descarga;

    cout << "Select the numbre of the country" << endl;
    cout << "1: Costa Rica" << endl;
    cout << "2: USA" << endl;
    cout << "3: Colombia" << endl;

    cin >> numero;

    if(numero == 1){pais = "Costa Rica";}
    else if (numero == 2){pais = "USA";}
    else{pais = "Colombia";}


    cout << "what do you want to download" << endl;
    cin >> descarga;

    proxyServer s = proxyServer(8000, "http://downloadE.com");

    s.download(descarga, pais);

    cout << "example obtained and adapted from: https://programacion.net/articulo/patrones_de_diseno_xiii_patrones_estructurales_proxy_1016" << endl;


}