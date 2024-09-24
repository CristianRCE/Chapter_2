//=====[LIBRERIES]============================================
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of pins]============================================
DigitalIn gasDetector(D2);
DigitalIn overTempDetector(D3);
DigitalIn alarmOffButton(D4);
DigitalOut alarmLed(LED1);

//=====[Serial Terminal]==============================
UnbufferedSerial serial_port(USBTX,USBRX);

//=====[Declaration and Initialization of global variables]============================================
bool alarmState = OFF;

//=====[Declaration (prototypes) of publics functions]==================

void inputsInit();
void outputsInit();

void gasTempDetection();
void uartTask();
void uartInit();

//=====[Main Function]==================

int main()
{
    inputsInit();
    outputsInit();
    uartInit();

    while (true){
        gasTempDetection();
        uartTask();
    }
}

void inputsInit()
{
    gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown);
    alarmOffButton.mode(PullDown);
}

void outputsInit()
{
    alarmLed=OFF;
}

void gasTempDetection()
{
    if(overTempDetector || gasDetector)
    {
        alarmState = ON;
    }
    if(alarmOffButton)
    {
        alarmState = OFF;
    }
    alarmLed = alarmState;
}

void uartInit()
{
    //PROPERTIES:
    serial_port.baud(9600);
    serial_port.format(
        /*bits*/ 8,
        /*parity*/ SerialBase::None,
        /*stop bit*/ 1
    );
}

void uartTask()
{
    char receivedChar = '\0';
    if(uartUsb.readable())
    {
        uartUsb.read( &receivedChar,1);
        if(receivedChar == '1')
        {
            if(alarmState)
            {
                uartUsb.write("The alarm is activated\r\n",24);
            }
            else
            {
                uartUsb.write("The alarm is not activated\r\n",28);
            }
        }
    }
}