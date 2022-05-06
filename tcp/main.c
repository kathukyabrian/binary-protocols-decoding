#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hexInput[100] = {
        0xc3,
        0x46,
        0x01,
        0xbb,
        0x44,
        0x0f,
        0x85,
        0xd9,
        0x00,
        0x00,
        0x00,
        0x00,
        0xa0,
        0x02,
        0xfa,
        0xf0,
        0x6c,
        0x4f,
        0x00,
        0x00,
        0x02,
        0x04,
        0x05,
        0xb4,
        0x04,
        0x02,
        0x08,
        0x0a,
        0x08,
        0x7c,
        0x72,
        0x3b,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x03,
        0x03,
        0x07};

    printf("Decoding tcp header for the love of the bytes\n");
    printf("========================================================\n");

    int sourcePort = 0x0 & 0xff;
    sourcePort |= hexInput[0];
    sourcePort = sourcePort << 8;
    sourcePort |= hexInput[1];
    printf("Source port is %d\n", sourcePort);

    int destinationPort = 0x0 & 0xff;
    destinationPort |= hexInput[2];
    destinationPort = destinationPort << 8;
    destinationPort |= hexInput[3];
    printf("Destination port is %d\n", destinationPort);

    int sequenceNumber = 0x0 & 0xff;
    // or with a 32 bit value to avoid errors
    // therefore and value with 0xff
    sequenceNumber |= ((hexInput[4] & 0xff) << 24);
    sequenceNumber |= ((hexInput[5] & 0xff) << 16);
    sequenceNumber |= ((hexInput[6] & 0xff) << 8);
    sequenceNumber |= ((hexInput[7] & 0xff) << 0);
    printf("Sequence number is %d\n", sequenceNumber);

    int acknowledgementNumber = 0x00 & 0xff;
    acknowledgementNumber |= ((hexInput[8] & 0xff) << 24);
    acknowledgementNumber |= ((hexInput[9] & 0xff) << 16);
    acknowledgementNumber |= ((hexInput[10] & 0xff) << 8);
    acknowledgementNumber |= ((hexInput[11] & 0xff) << 0);
    printf("Acknowledgement number is %d\n", acknowledgementNumber);

    // combine both 12 and 13 - there are 3 and 9 bits in this
    int doRsvAndFlags = 0x0 & 0xff;
    doRsvAndFlags |= hexInput[12];
    doRsvAndFlags = doRsvAndFlags << 8;
    doRsvAndFlags |= hexInput[13];

    int headerLength = (doRsvAndFlags >> 12) << 2;
    printf("Header Length(DO) is %d bytes\n", headerLength);

    int rsv = doRsvAndFlags & 0b0000111000000000;
    printf("rsv is %d\n", rsv);

    int flags = (doRsvAndFlags & 0b0000000111111111) & 0xff;

    int nonce = flags & 0b100000000;
    char *nonceStr = "unset";
    if (nonce != 0)
    {
        nonceStr = "set";
    }

    int congestionWindowReduced = flags & 0b010000000;
    char *congestionWindowReducedStr = "unset";
    if (congestionWindowReduced != 0)
    {
        congestionWindowReducedStr = "set";
    }

    int ecnEcho = flags & 0b001000000;
    char *ecnEchoStr = "unset";
    if (ecnEcho != 0)
    {
        ecnEchoStr = "set";
    }

    int urgent = flags & 0b000100000;
    char *urgentStr = "unset";
    if (urgent != 0)
    {
        urgentStr = "set";
    }

    int ack = flags & 0b000010000;
    char *ackStr = "unset";
    if (ack != 0)
    {
        ackStr = "set";
    }

    int push = flags & 0b000001000;
    char *pushStr = "unset";
    if (push != 0)
    {
        pushStr = "set";
    }

    int reset = flags & 0b000000100;
    char *resetStr = "unset";
    if (reset != 0)
    {
        resetStr = "set";
    }

    int syn = flags & 0b000000010;
    char *synStr = "unset";
    if (syn != 0)
    {
        synStr = "set";
    }

    int fin = flags & 0b000000001;
    char *finStr = "unset";
    if (fin != 0)
    {
        finStr = "set";
    }

    printf("Flags are set as follows:\n nonce = %s\n congestion window reduced = %s\n ecn-echo = %s\n urgent = %s\n ack = %s\n push = %s\n reset = %s\n syn = %s\n fin = %s\n", nonceStr, congestionWindowReducedStr, ecnEchoStr, urgentStr, ackStr, pushStr, resetStr, synStr, finStr);

    int window = 0x0 & 0xff;
    window |= hexInput[14];
    window = window << 8;
    window |= hexInput[15];
    printf("window is %d\n", window);

    int checksum = 0x0 & 0xff;
    checksum |= hexInput[16];
    checksum = checksum << 8;
    checksum |= hexInput[17];
    printf("check sum is %x\n", checksum);

    int urgentPointer = 0x0 & 0xff;
    urgentPointer |= hexInput[18];
    urgentPointer = urgentPointer << 8;
    urgentPointer |= hexInput[19];
    printf("urgent pointer is %d\n", urgentPointer);

    return 1;
}