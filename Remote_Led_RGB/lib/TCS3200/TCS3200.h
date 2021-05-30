#include <Arduino.h>

// Frequency setting defines
const int TCS230_FREQ_HI = 0;  // 100% prescaler
const int TCS230_FREQ_MID = 1; // 20% prescaler
const int TCS230_FREQ_LO  = 2; // 2% prescaler
const int TCS230_FREQ_OFF = 3; // Power dowm

class TCS3200{
    public: 
        // Declare Pin on sensor 
        int _S0 = 3;
        int _S1 = 4;
        int _S2 = 5;
        int _S3 = 6;
        int _OUT = 2;

        // Declare Values of sensor
        int redfrequency = 0;
        int greenfrequency = 0;
        int bluefrequency = 0;

        void begin(void);
        void setFrequency(int f);
        void setred();
        void setgreen();
        void setblue();
        //TCS3200(int S0, int S1, int S2, int S3, int OUT);
        ~TCS3200(void);
};