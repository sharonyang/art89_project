/*
 * Convert string to ASCII in the format matching Atmel
 * datasheet. This is not done.
 */

#include <stdio.h>
#include <string.h>

void string_to_hex(const char* str, unsigned char* hexstring) {
    unsigned char ch, i, j, len;
    len = strlen(str);

    for(i = 0, j = 0; i < len; i++ , j += 2) {
        ch = str[i];

        if( ch >= 0 && ch <= 0x0F) {
            hexstring[j] = 0x30;
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;

        }
        else if( ch >= 0x10 && ch <= 0x1F) {
            hexstring[j] = 0x31;
            ch -= 0x10;
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else if( ch >= 0x20 && ch <= 0x2F) {
            hexstring[j] = 0x32;
            ch -= 0x20;
 
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else if( ch >= 0x30 && ch <= 0x3F) {
            hexstring[j] = 0x33;
            ch -= 0x30;

            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else if( ch >= 0x40 && ch <= 0x4F) {
            hexstring[j] = 0x34;
            ch -= 0x40;

            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else if( ch >= 0x50 && ch <= 0x5F){
            hexstring[j] = 0x35;
            ch -= 0x50;
 
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else if( ch >= 0x60 && ch <= 0x6F) {
            hexstring[j] = 0x36;
            ch -= 0x60;
 
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        } 
        else  if( ch >= 0x70 && ch <= 0x7F) {
            hexstring[j] = 0x37;
            ch -= 0x70;
 
            if(ch >= 0 && ch <= 9)
                hexstring[j+1] = 0x30 + ch;
            else
                hexstring[j+1] = 0x37 + ch;
        }
        else {
            printf("Error: does not recognize char.");
        }
    }
    hexstring[j] = 0x00;
}

int main() {
    const char* data = "Test hex string view";
    int len = strlen(data);
    unsigned char output[len];
    string_to_hex(data, output);

    for (int i = 0; i < len; i++)
        printf("%#04x\n", (data[i] - 0x36));

    // TODO: Handle strange symbol to ASCII conversion.

    printf("\n");
}

