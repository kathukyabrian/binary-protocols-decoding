#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
    int hexInput[120] = {
        0x0b,
        0x05,
        0x00,
        0x6d,
        0xf0,
        0x50,
        0x64,
        0x91,
        0x84,
        0x62,
        0x5d,
        0x36,
        0xf1,
        0x4c,
        0x90,
        0x75,
        0xb7,
        0xa4,
        0x8b,
        0x83,
        0x08,
        0x06,
        0xff,
        0xff,
        0xff,
        0xfe,
        0x0c,
        0x06,
        0x00,
        0x00,
        0x02,
        0x40,
        0x06,
        0x06,
        0x00,
        0x00,
        0x00,
        0x02,
        0x12,
        0x0b,
        0x48,
        0x65,
        0x6c,
        0x6c,
        0x6f,
        0x2c,
        0x20,
        0x25,
        0x75,
        0x4f,
        0x18,
        0x01,
        0x01,
        0x00,
        0x16,
        0x04,
        0x10,
        0x26,
        0x6b,
        0x0e,
        0x9a,
        0x58,
        0x32,
        0x2f,
        0x4d,
        0x01,
        0xab,
        0x25,
        0xb3,
        0x5f,
        0x87,
        0x94,
        0x64,
        0x50,
        0x12,
        0x11,
        0xb5,
        0x04,
        0x3c,
        0x8a,
        0x28,
        0x87,
        0x58,
        0x17,
        0x31,
        0x33,
        0xa5,
        0xe0,
        0x74,
        0x34,
        0xcf,
        0x18,
        0x12,
        0xc6,
        0xd1,
        0x95,
        0x03,
        0x2f,
        0xdc,
        0x30,
        0x24,
        0x0f,
        0x73,
        0x13,
        0xb2,
        0x31,
        0xef,
        0x1d,
        0x77
    };

    int code = 0x0 & 0xff;
    code |= hexInput[0];
    printf("Code is %d\n", code);

    int packetIdentifier = 0x0 & 0xff;
    packetIdentifier |= hexInput[1];
    printf("Packet identifier is %d\n", packetIdentifier);

    int length = 0x0 & 0xff;
    length |= hexInput[2];
    length <<= 8;
    length |= hexInput[3];
    printf("Length is %d\n", length);

    // int authenticator = 0x0 & 0xff;
    // authenticator |= hexInput[4] << 120;
    // authenticator |= hexInput[5] << 112;
    // authenticator |= hexInput[6] << 104;
    // authenticator |= hexInput[7] << 96;
    // authenticator |= hexInput[8] << 88;
    // authenticator |= hexInput[9] << 80;
    // authenticator |= hexInput[10] << 72;
    // authenticator |= hexInput[11] << 64;
    // authenticator |= hexInput[12] << 56;
    // authenticator |= hexInput[13] << 48;
    // authenticator |= hexInput[14] << 40;
    // authenticator |= hexInput[15] << 32;
    // authenticator |= hexInput[16] << 24;
    // authenticator |= hexInput[17] << 16;
    // authenticator |= hexInput[18] << 8;
    // authenticator |= hexInput[19];
    // printf("The authenticator is %x\n", authenticator);
    // printf("The authenticator is a 128 bit\n");


    return 1;
}