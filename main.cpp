#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

string grafoshow [150][150];
int grafomain [150][150];
bool visitado [150][150];

int dx[]={-1,0,1,0,-1,1,1,-1};
int dy[]={0,1,0,-1,1,1,-1,-1};

bool win;
int M,N;

int fila,columna;

void floodfill(int x,int y) {
 /*   string update= to_string(grafomain[x][y]);
    cout<<update<<endl;
    cout<<grafomain[x][y];*/
    grafoshow[x][y] =to_string(grafomain[x][y]);
    visitado[x][y]=true;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<fila && ny>=0 && ny<columna && grafomain[nx][ny]!=-1&&!visitado[nx][ny]) {
            floodfill(nx,ny);
        }
    }
}


void verificar(int x, int y){
    if(grafomain[x][y]==-1){
        win=false;
    }else{
        floodfill(x,y);
    }

}

void loadLevel(){
    for(int i=0; i<fila;i++){
        for(int j=0;j<columna;j++){
            cin>>grafomain[i][j];
            grafoshow[i][j]="*";
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
}

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

int main(){
    input;
    cin>>fila>>columna;
/*    for(int i=0; i<M;i++){
        for(int j=0;j<N;j++){
            int number;
            cin>>number;
            if(number==-1){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
*/
    loadLevel();
    showmatrixplayer();
    //showmatrixfinal();
    verificar(0,0);
    showmatrixplayer();


    return 0;
}