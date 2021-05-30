#include <TCS3200.h>

// TCS3200::TCS3200(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t OUT){
//     _S0 = S0;
//     _S1 = S1;
//     _S2 = S2;
//     _S3 = S3;
//     _OUT = OUT;
// }

TCS3200::~TCS3200(void){}

void TCS3200::begin(){
    pinMode(_S0, OUTPUT);
    pinMode(_S1, OUTPUT);
    pinMode(_S2, OUTPUT);
    pinMode(_S3, OUTPUT);
    pinMode(_OUT, INPUT);
}

void TCS3200::setFrequency(int f){
    switch (f)
    {
        case TCS230_FREQ_HI:
            digitalWrite(_S0, HIGH);  
            digitalWrite(_S1, HIGH);  
            break;
        case TCS230_FREQ_MID:
            digitalWrite(_S0, HIGH);
            digitalWrite(_S1, LOW);
            break;
        case TCS230_FREQ_LO:
            digitalWrite(_S0, LOW);
            digitalWrite(_S1, HIGH);
            break;
        case TCS230_FREQ_OFF: 
            digitalWrite(_S0, LOW);
            digitalWrite(_S1, LOW);
            break;
    default:
        break;
    }
}

void TCS3200::setred(){
    // Setting red filtered photodiodes to be read
    digitalWrite(_S2,LOW);
    digitalWrite(_S3,LOW);
    // Reading the output frequency
    redfrequency = pulseIn(_OUT, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    redfrequency = map(redfrequency, 25,72,255,0);
    if (redfrequency > 255){
        redfrequency = 255;  
    }  
    else if (redfrequency < 0){
        redfrequency = 0;  
    }
}

void TCS3200::setgreen(){
    // Setting Green filtered photodiodes to be read
    digitalWrite(_S2,HIGH);
    digitalWrite(_S3,HIGH);
    // Reading the output frequency
    greenfrequency = pulseIn(_OUT, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    greenfrequency = map(greenfrequency, 30,90,255,0);
    if (greenfrequency > 255){
        greenfrequency = 255;  
    }  
    else if (greenfrequency < 0){
        greenfrequency = 0;  
    }  
}

void TCS3200::setblue(){
    // Setting Blue filtered photodiodes to be read
    digitalWrite(_S2,LOW);
    digitalWrite(_S3,HIGH);
    // Reading the output frequency
    bluefrequency = pulseIn(_OUT, LOW);
    //Remaping the value of the frequency to the RGB Model of 0 to 255
    bluefrequency = map(bluefrequency, 25,70,255,0);
    if (bluefrequency > 255){
        bluefrequency = 255;  
    }  
    else if (bluefrequency < 0){
        bluefrequency = 0;  
    }  
}