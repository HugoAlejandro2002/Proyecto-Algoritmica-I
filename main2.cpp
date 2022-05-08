#include <bits/stdc++.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream lector;

string grafoshow [150][150];
int grafomain [150][150];
bool visitado [150][150];
int marcados [150][150];
bool marcado [150][150];

int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

bool win;
bool play;

int fila,columna;
int contadorBombas=0;
int contadorEspacios;
int contadorLiberados = contadorEspacios = 0;

void menu();

//JUEGO

void floodfill(int x,int y) {
    if (grafomain[x][y]==-1 && !marcado[x][y]){
        grafoshow[x][y]= "x";
        play=false;
        win=false;
    } else if(grafomain[x][y]!=-1) {
        if(!visitado[x][y]){
            grafoshow[x][y] =to_string(grafomain[x][y]);
            visitado[x][y]=true;
            contadorLiberados++;
        }
    }
    if(marcados[x][y] == grafomain[x][y]){

        for(int i=0;i<8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<fila && ny>=0 && ny<columna && !marcado[nx][ny] && !visitado[nx][ny]) {
                floodfill(nx,ny);
            }
        }
    }

    
}

void marcar(int x, int y){
    marcado[x][y] = true;
    grafoshow[x][y]="+";
    for(int i=0;i<8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            marcados[nx][ny]++;
    }
}

void desmarcar(int x, int y){
    marcado[x][y] =false;
    grafoshow[x][y]="*";
    for(int i=0;i<8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            marcados[nx][ny]--;
    }
}

void verificar(){
    if(contadorLiberados == contadorEspacios){
        play=false;
        win=true;
    }
}

//INICIALIZACION

void loadLevel(int i){
    string archivo;
    archivo = "ejemplo"+ std::to_string(i)+".txt";
    lector.open(archivo);

    if(!lector){
        cout << "No existe el archivo";
        exit(2);
    } else {
        lector >> fila >> columna;

        for(int i=0; i<fila;i++){
            for(int j=0;j<columna;j++){
                lector>>grafomain[i][j];
                grafoshow[i][j]="*";
                if(grafomain[i][j]!=-1){
                    contadorEspacios++; //cuenta espacios libres en la matriz
                }
            }
        }
        
        for(int x=0; x<fila;x++){
            for(int y=0;y<columna;y++){
                int bombs=0;
                if(grafomain[x][y]!=-1){
                    for(int k=0;k<8;k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx>=0 && nx<fila && ny>=0 && ny<columna && grafomain[nx][ny]==-1) {
                            bombs++;
                        }
                    }   
                    grafomain[x][y]=bombs;
                } 
            }
        }

        memset(marcados, 0, sizeof(marcados));
        memset(marcado, 0, sizeof(marcado));
    }

    
}

//MOSTRAR MATRIZ

void showmatrixplayer(){
    for(int i=0; i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<grafoshow[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void showmatrixfinal(){
    for(int i=0; i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<grafomain[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/* void buildMatrix(int i){
    string archivo;
    archivo = "ejemplo"+ std::to_string(i)+".txt";
    lector.open(archivo);

    if(!lector){
        cout << "No existe el archivo";
        exit(2);
    } else {
        lector >> fila >> columna;
        loadLevel(i);
        showmatrixplayer();
        verificar(0,0);
        showmatrixplayer();
    }

} */

//MENU 

void juego(int i){
        loadLevel(i);
        play = true;
        while(play){
            showmatrixplayer();
            int p, m, n;
            p=3;
            while(p>2){
                cin>> p >> m>> n;
            }
            cout<< "\n";
            if(p==0){
                floodfill(m,n);
            } else if(p==1){
                marcar(m,n);
            } else if(p==2){
                desmarcar(m,n);
            }
            verificar();
        }
        if(win){
            showmatrixplayer();
            cout<< "GANASTE \n";
        } else {
            showmatrixplayer();
            cout<< "PERDISTE \n";
        }
}

void reglas(){
        cout << "--------------------------Buscaminas-------------------------- \n";
        cout << "-----------------------------Reglas----------------------------- \n";
        cout << "Algunas celdas contienen bombas. Aquellas que no, contienen el \n";
        cout << "número de bombas que se encuentran en las celdas a su alrededor.\n";
        cout << "Si revela una bomba, pierde. Si revela todas las celdas sin\n";
        cout << "bombas, gana.\n";
        cout << "Las bombas pueden ser marcadas y las celdas pueden ser reveladas\n";
        cout << "en grupo si se han marcado el número de bombas a su alrededor o si\n";
        cout << "no tiene bombas alrededor.\n";
        cout << "Para jugar, debe ingresar 3 digitos: P, M y N. P sera el boton a\n";
        cout << "presionar, donde 0 sera 'revelar', 1 'marcar' y 2 'desmarcar. \n"; 
        cout << "M y N son las coordenadas del cuadro con el que se interactuara.\n";
        cout << "M representa la fila seleccionada y N la columna seleccionada. \n";
        cout << "--------------------------Buscaminas-------------------------- \n";
        cout << "Ingresar cualquier número \n";
        int x;
        cin>>x;
        menu();
}

void menu(){
    cout << "--------------------------Buscaminas-------------------------- \n";
    cout << "-----------------------Menu Principal----------------------- \n";
    cout << "1. Ejemplo 1 \n";
    cout << "2. Ejemplo 2 \n";
    cout << "3. Ejemplo 3 \n";
    cout << "4. Ejemplo 4 \n";
    cout << "5. Ejemplo 5 \n";
    cout << "6. Ejemplo 6 \n";
    cout << "7. Reglas \n";
    cout << "0. Salir \n";
    cout << "--------------------------Buscaminas--------------------------\n";
    cout << "Ingresar opcion: ";
    int i=8;
    while(i>7){
        cin>>i;
    }
    if(i==0){
        exit;
    } else if (i>0 && i<7){
        cout<< "\n";
        juego(i);
    } else if (i==7){
        reglas();
    }
}

int main(){
    menu();
    return 0;
}