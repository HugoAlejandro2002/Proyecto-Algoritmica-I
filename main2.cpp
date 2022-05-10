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
        grafoshow[x][y]= "\033[1;31mx\033[0m";
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
    if(!visitado[x][y]){
    if(!marcado[x][y]){
        marcado[x][y] = true;
        grafoshow[x][y]="\033[1;31m+\033[0m";
        for(int i=0;i<8;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                marcados[nx][ny]++;
        }
    } else {
        marcado[x][y] =false;
        grafoshow[x][y]="*";
        for(int i=0;i<8;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                marcados[nx][ny]--;
        }
    }
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
    archivo = "ejemplo"+ to_string(i)+".txt";
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

        memset(visitado,0,sizeof(visitado));
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
            if(grafomain[i][j]==-1){
                grafoshow[i][j]="\033[1;31mx\033[0m";
            }
        }
    }
}

//MENU 

void juego(int i){
        loadLevel(i);
        play = true;
        while(play){
            showmatrixplayer();
            int p, m, n;
            p=2;
            while(p>1){
                cin>> p >> m>> n;
            }
            cout<< "\n";
            if(p==0){
                floodfill(m,n);
            } else if(p==1){
                marcar(m,n);
            }
            verificar();
        }
        if(win){
            showmatrixplayer();
            cout<< "\033[1;32mGANASTE\033[0m\n";
        } else {
            showmatrixfinal();
            showmatrixplayer();
            cout<< "\033[1;31mPERDISTE\033[0m\n";
        }
}

void reglas(){
        cout << "\033[1;36m---------------------------Buscaminas-------------------------\033[0m\n";
        cout << "\033[1;34m----------------------------Reglas----------------------------\033[0m\n";
        cout << "\033[1;37mAlgunas celdas contienen bombas. Aquellas que no, contienen el\033[0m\n";
        cout << "\033[1;37mnumero de bombas que se encuentran en las celdas a su alrededor.\033[0m\n";
        cout << "\033[1;37mSi revela una bomba, pierde. Si revela todas las celdas sin\033[0m\n";
        cout << "\033[1;37mbombas, gana.\033[0m\n";
        cout << "\033[1;37mLas bombas pueden ser marcadas y las celdas pueden ser reveladas\033[0m\n";
        cout << "\033[1;37men grupo si se han marcado el numero de bombas a su alrededor o si\033[0m\n";
        cout << "\033[1;37mno tiene bombas alrededor.\033[0m\n";
        cout << "\033[1;37mPara jugar, debe ingresar 3 digitos: P, M y N. P sera el boton a\033[0m\n";
        cout << "\033[1;37mpresionar, donde 0 sera 'revelar', y 1 'marcar' y 'desmarcar.\033[0m\n"; 
        cout << "\033[1;37mM y N son las coordenadas del cuadro con el que se interactuara.\033[0m\n";
        cout << "\033[1;37mM representa la fila seleccionada y N la columna seleccionada.\033[0m\n";
        cout << "\033[1;36m---------------------------Buscaminas-------------------------\033[0m\n";
        cout << "\033[1;37mIngresar cualquier numero\033[0m\n";
        int x;
        cin>>x;
        menu();
}

void menu(){
    cout << "\033[1;36m---------------------------Buscaminas-------------------------\033[0m\n";
    cout << "\033[1;34m------------------------Menu Principal------------------------\033[0m\n";
    cout << "\033[1;37m1. Ejemplo 1\033[0m\n";
    cout << "\033[1;37m2. Ejemplo 2\033[0m\n";
    cout << "\033[1;37m3. Ejemplo 3\033[0m\n";
    cout << "\033[1;37m4. Ejemplo 4\033[0m\n";
    cout << "\033[1;37m5. Ejemplo 5\033[0m\n";
    cout << "\033[1;37m6. Ejemplo 6\033[0m\n";
    cout << "\033[1;37m7. Reglas\033[0m\n";
    cout << "\033[1;37m8. Salir\033[0m\n";
    cout << "\033[1;35m----------------------------Comandos----------------------------\033[0m\n";
    cout << "\033[1;37mP M N\033[0m\n";
    cout << "\033[1;37mP= 0 liberar, 1 marcar, 1 (sobre '+') desmarcar\033[0m\n";
    cout << "\033[1;37mM= fila\033[0m\n";
    cout << "\033[1;37mN= columna\033[0m\n";
    cout << "\033[1;36m---------------------------Buscaminas-------------------------\033[0m\n";
    cout << "\033[1;37mIngresar opcion: \033[0m";
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
