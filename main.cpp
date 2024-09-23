//=====[LIBRERIES]============================================
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of pins]============================================
DigitalIn B1_USER(BUTTON1);
DigitalOut LD2(LED2);

//=====[Declaration and Initialization of global variables]============================================
int i = 0;

//=====[Declaration (prototypes) of publics functions]==================
void inputsInit();
void outputsInit();

void blinkingLed();

//=====[Main Function]==================

int main()
{
    inputsInit();
    outputsInit();

    while (true){
        blinkingLed();
    }
}

void inputsInit()
{
    B1_USER.mode(PullDown);
}

void outputsInit()
{
    LD2=OFF;
}


void blinkingLed()
{
    if(B1_USER)
        {
            for(i=0;i<5;i++)
            {
                LD2 = ON;
                delay(300);
                LD2 = OFF;
                delay(300);
            }
        }
}