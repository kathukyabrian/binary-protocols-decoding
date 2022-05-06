#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Decoding an ip header for the love of the bytes\n");
    printf("========================================================\n");

    int hexInputs[100] = {
        0x45,
        0x00,
        0x00,
        0x3c,
        0x73,
        0xa3,
        0x40,
        0x00,
        0x40,
        0x06,
        0x5d,
        0xa0,
        0xc0,
        0xa8,
        0x00,
        0x1c,
        0x9f,
        0xdf,
        0x74,
        0xd5};

    // version - obtain the first nibble in first element in array
    // shift 4 bits right - we are talking about a nibble
    int version = hexInputs[0] >> 4;
    printf("Version is %d - (ipv%d)\n", version, version);

    // header-length - second nibble in first byte in the array
    // & with 0b00001111
    int headerLength = hexInputs[0] & 0b00001111;
    printf("Header length is %d bytes\n", headerLength << 2);

    int serviceType = hexInputs[1];
    // to come back here

    int totalLength = 0x0;
    totalLength = totalLength | hexInputs[2];
    totalLength = totalLength << 8;
    totalLength = totalLength | hexInputs[3];
    printf("Total length is %d\n", totalLength);

    int identification = 0x0;
    identification = identification | hexInputs[4];
    identification = identification << 8;
    identification = identification | hexInputs[5];
    printf("Identification is %d\n", identification);

    int flagsAndFragmentOffset = 0x0;
    flagsAndFragmentOffset = flagsAndFragmentOffset | hexInputs[6];
    flagsAndFragmentOffset = flagsAndFragmentOffset << 8;
    flagsAndFragmentOffset = flagsAndFragmentOffset | hexInputs[7];
    int reservedFlag = flagsAndFragmentOffset & 0b1000000000000000;
    int dontFragmentFlag = flagsAndFragmentOffset & 0b0100000000000000;
    int moreFragmentFlag = flagsAndFragmentOffset & 0b0010000000000000;

    char *reservedFlagStr = "not set";
    if (reservedFlag != 0)
    {
        reservedFlagStr = "set";
    }

    char *dontFragmentFlagStr = "not set";
    if (dontFragmentFlag != 0)
    {
        dontFragmentFlagStr = "set";
    }

    char *moreFragmentFlagStr = "not set";
    if (moreFragmentFlag != 0)
    {
        moreFragmentFlagStr = "set";
    }

    printf("Flags are set as follows:\n reserved = %s\n dontfragmentFlag = %s\n moreFragmentFlag = %s\n", reservedFlagStr, dontFragmentFlagStr, moreFragmentFlagStr);

    int fragmentOffset = flagsAndFragmentOffset & 0b0001111111111111;
    printf("Fragment offset is %d\n", fragmentOffset);

    int timeToLive = hexInputs[8];
    printf("Time to live is %d\n", timeToLive);

    int protocol = hexInputs[9];
    // what exactly is 6?
    printf("Protocol is %d. You can refer to https://en.wikipedia.org/wiki/List_of_IP_protocol_numbers for the protocol name\n", protocol);

    int headerCheckSum = 0x0;
    headerCheckSum = headerCheckSum | hexInputs[10];
    headerCheckSum = headerCheckSum << 8;
    headerCheckSum = headerCheckSum | hexInputs[11];
    printf("Header checksum is %x - used to check if datagram was corrupted\n", headerCheckSum);

    int sourceIpFirstPart = hexInputs[12];
    int sourceIpsecondPart = hexInputs[13];
    int sourceIpthirdPart = hexInputs[14];
    int sourceIpfourthPart = hexInputs[15];
    printf("Source ip adress is %d.%d.%d.%d\n", sourceIpFirstPart, sourceIpsecondPart, sourceIpthirdPart, sourceIpfourthPart);

    int destinationIpFirstPart = hexInputs[16];
    int destinationIpsecondPart = hexInputs[17];
    int destinationIpthirdPart = hexInputs[18];
    int destinationIpfourthPart = hexInputs[19];
    printf("Destination ip adress is %d.%d.%d.%d\n", destinationIpFirstPart, destinationIpsecondPart, destinationIpthirdPart, destinationIpfourthPart);
    return 0;
}