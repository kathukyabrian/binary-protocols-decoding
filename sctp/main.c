#include <stdlib.h>
#include <stdio.h>

int main()
{

    int hexInput[50] = {
        0x89, // source port
        0x3c, // source port
        0x0f, // destination port
        0x1c, // destination port
        0xa8, // verification tag
        0x1d, // verification tag
        0x03, // verification tag
        0xc5, // verification tag
        0xe5, // checksum
        0xd7, // checksum
        0x9a, // checksum
        0xa5, // checksum
        0x00,
        0x03,
        0x00,
        0xd8,
        0xe7,
        0x0b,
        0x81,
        0x46,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00};

    int sourcePort = 0x0 & 0xff;
    sourcePort |= hexInput[0] & 0xff;
    sourcePort <<= 8;
    sourcePort |= hexInput[1] & 0xff;
    printf("Source port is %d\n", sourcePort);

    int destinationPort = 0x0 & 0xff;
    destinationPort |= hexInput[2] & 0xff;
    destinationPort <<= 8;
    destinationPort |= hexInput[3] & 0xff;
    printf("Destination port is %d\n", destinationPort);

    int verificationTag = 0x0 & 0xff;
    verificationTag |= hexInput[4] << 24;
    verificationTag |= hexInput[5] << 16;
    verificationTag |= hexInput[6] << 8;
    verificationTag |= hexInput[7];
    printf("Verification tag is %x\n", verificationTag);

    int checkSum = 0x0 & 0xff;
    checkSum |= hexInput[8] << 24;
    checkSum |= hexInput[9] << 16;
    checkSum |= hexInput[10] << 8;
    checkSum |= hexInput[11];
    printf("Checksum is %x\n", checkSum);

    int type = 0x0 & 0xff;
    type |= hexInput[12];
    printf("Type is %d\n", type);

    int possibleDelaySACK = hexInput[13] & 0b1000;
    char *possibleDelaySACKStr = "Unset";
    if (possibleDelaySACK != 0)
    {
        possibleDelaySACKStr = "Set";
    }

    int orderedDelivery = hexInput[13] & 0b0100;
    char *orderedDeliveryStr = "Unset";
    if (orderedDelivery != 0)
    {
        orderedDeliveryStr = "Set";
    }

    int firstSegment = hexInput[13] & 0b0010;
    char *firstSegmentStr = "Unset";
    if (firstSegment != 0)
    {
        firstSegmentStr = "Set";
    }

    int lastSegment = hexInput[13] & 0b0001;
    char *lastSegmentStr = "Unset";
    if (lastSegment != 0)
    {
        lastSegmentStr = "Set";
    }
    printf("Flags are set as follows\n possible delay SACK = %s\n ordered delivery = %s\n first segment = %s\n last segment = %s\n", possibleDelaySACKStr, orderedDeliveryStr, firstSegmentStr, lastSegmentStr);

    int length = 0x0 & 0xff;
    length |= hexInput[14];
    length <<= 8;
    length |= hexInput[15];
    printf("Length is %d\n", length);

    return 1;
}