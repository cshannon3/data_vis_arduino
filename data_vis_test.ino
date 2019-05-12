
#include "data_vis.h"


int iterator = 0;
int bufferLeng=20;
int runs = 100;
uint16_t readingsPerUpdate = 5;
uint16_t updatesPerRun = 50; 
uint16_t updateDelay = 100;
int rar1, rar2,rar3, rar4;
DataVis dv = DataVis();
String cmd= "";

void setup(){
    Serial.begin(115200);
    randomSeed(analogRead(0));
    //printHeader();
    dv.addParam("Param 1","p1",52);
    dv.addParam("Param 2","p2",60);
    dv.addParam("Param 3","p3",22);
    dv.addInput("Input 1","mL","Top Right",true, &rar1);
    dv.addInput("Input 2","mL","Top Left", true, &rar2);
    dv.addInput("Input 3","mL","Bottom Right",true, &rar3);

    dv.waitForInitCmd();

}

void loop(){
    dv.waitForStartRunCmd();

    //dv.initRun(readingsPerUpdate, updatesPerRun, updateDelay);
    //while (dv.isRunning()) {
        
    uint16_t upr = 0;
    uint16_t rpu = 0;
    while (upr<updatesPerRun){
        while(rpu<readingsPerUpdate){
            rar1 = random(300);
            rar2 = random(200);
            rar3 = random(100);
            dv.read();
            delay(updateDelay);
            rpu+=1;
        }
        dv.update();
        rpu=0;
        upr+=1;
    }
}
  