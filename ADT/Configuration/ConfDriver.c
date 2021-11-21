#include "Configuration.h"

int main() {
    sscanf("config.txt","%s",fileName);
    loadConfig();
    if (mapLenght != 20) {
        printf("Map lenght not set \n");
        return -1;
    }
    // map test
    if (map[0] != '.'){
        printf("Map properties not set \n");
        return -1;
    }
    //max dice role
    if (maxDiceRole != 10 ) {
        printf("Map properties not set \n");
        return -1;
    }
    
    for (int pepek = 0; pepek < teleportLenght;pepek++) {
        printf("start : %d , end : %d \n",teleporters[pepek].startPoint,teleporters[pepek].endPoint);
    }
    freeTeleporters();
    printf("Pass all test,gratio!\n");
    return 0;
}