#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn B1_USER(BUTTON1);
    DigitalOut LD2(LED2);
    
    while (true){
        int i;
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
}
