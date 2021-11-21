#include "Configuration.h"

int mapLenght = 0;
int maxDiceRole = 0;
char map[255];
int teleportLenght = 0;

int converter(char pep){
    return pep - '0';
}

void setMap(Kata mapConfig) {
    for (int i = 0; i <= mapConfig.Length; i++){
        map[i] = mapConfig.TabKata[i];
    }
}
void setConfigFile(){
    printf("Remember to add .txt in the end, user! \n");
    printf("Configuration file name : ");
    scanf("%s", fileName);
    printf("\nLoading configuration...\n");
}
void loadConfig() {
    //int flag = 0;
    STARTKATA(1);

    int line = 1;
    int index = 0;
    while (!EndKata) {
        if (line == 1) {
            setMapLenght(atoi(CKata.TabKata));
        } 
        else if (line == 2) {
            setMap(CKata);
        }
        else if( line == 3) {
            setMaxDiceRole(atoi(CKata.TabKata));
        }
        else if( line == 4) {
            teleportLenght = atoi(CKata.TabKata);
            allocateTeleportersLenght(teleportLenght);
        } else {

            //MARK: PROBLEMATIC, need to fix ASAP!
            int start = 0;// atoi(CKata.TabKata[0]);
            int end = 0;//atoi(CKata.TabKata[2]);
            int flexing_lah = 1;
            for (int x = 0; x < CKata.Length; x++) {
                if (CKata.TabKata[x] == ' ') {
                    flexing_lah = 2;
                }
                if (flexing_lah == 1 && CKata.TabKata[x] != ' ') {
                    start *= 10;
                    start += converter(CKata.TabKata[x]);
                   // printf(" yg di convert : %c, hasil  : %d\n",CKata.TabKata[x],converter(CKata.TabKata[x]));
                } else  if (flexing_lah == 2 && CKata.TabKata[x] != ' ') {
                    end *= 10;
                    end += converter(CKata.TabKata[x]);
                  //  printf(" yg di convert : %c, hasil  : %d\n",CKata.TabKata[x],converter(CKata.TabKata[x]));
                }
            }
            setTeleporter(index,start,end);
            index ++;
        }
        line++;
        ADVKATA();
    }
    printf("Configuration has been loaded successfully\n");
}

void setMapLenght(int lenght) {
    mapLenght = lenght;
}
void allocateTeleportersLenght(int lenght){
    teleporters = calloc(lenght, sizeof(teleport));
}
void freeTeleporters(){
    free(teleporters);
}

void setTeleporter(int index,int start,int end) {
    teleport temp;
    temp.startPoint = start;
    temp.endPoint = end;
    teleporters[index] = temp;
}

void setMaxDiceRole(int value){
   maxDiceRole = value;
}