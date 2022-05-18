#include <stdlib.h>
#include <stdio.h>

int main()
{
    int hexInput[200] = {
        0x01,
        0x00,
        0x00,
        0xc8,
        0x80,
        0x00,
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x20,
        0x4a,
        0x16,
        0x67,
        0x70,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x08,
        0x40,
        0x00,
        0x00,
        0x1f,
        0x62,
        0x61,
        0x63,
        0x6b,
        0x65,
        0x6e,
        0x64,
        0x2e,
        0x65,
        0x61,
        0x70,
        0x2e,
        0x74,
        0x65,
        0x73,
        0x74,
        0x62,
        0x65,
        0x64,
        0x2e,
        0x61,
        0x61,
        0x61,
        0x00,
        0x00,
        0x00,
        0x01,
        0x28,
        0x40,
        0x00,
        0x00,
        0x17,
        0x65,
        0x61,
        0x70,
        0x2e,
        0x74,
        0x65,
        0x73,
        0x74,
        0x62,
        0x65,
        0x64,
        0x2e,
        0x61,
        0x61,
        0x61,
        0x00,
        0x00,
        0x00,
        0x01,
        0x16,
        0x40,
        0x00,
        0x00,
        0x0c,
        0x4b,
        0xed,
        0x16,
        0x77,
        0x00,
        0x00,
        0x01,
        0x01,
        0x40,
        0x00,
        0x00,
        0x0e,
        0x00,
        0x01,
        0xc0,
        0xa8,
        0x69,
        0x14,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x01,
        0x40,
        0x00,
        0x00,
        0x1a,
        0x00,
        0x02,
        0xfd,
        0xe4,
        0x2c,
        0x6e,
        0x55,
        0xc4,
        0x01,
        0x05,
        0x0a,
        0x00,
        0x27,
        0xff,
        0xfe,
        0x0b,
        0x78,
        0x59,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x0a,
        0x40,
        0x00,
        0x00,
        0x0c,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x0d,
        0x00,
        0x00,
        0x00,
        0x14,
        0x66,
        0x72,
        0x65,
        0x65,
        0x44,
        0x69,
        0x61,
        0x6d,
        0x65,
        0x74,
        0x65,
        0x72,
        0x00,
        0x00,
        0x01,
        0x0b,
        0x00,
        0x00,
        0x00,
        0x0c,
        0x00,
        0x00,
        0x00,
        0x64,
        0x00,
        0x00,
        0x01,
        0x2b,
        0x40,
        0x00,
        0x00,
        0x0c,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x03,
        0x40,
        0x00,
        0x00,
        0x0c,
        0x00,
        0x00,
        0x00,
        0x03};

    int version = hexInput[0];
    printf("Diameter Version is %d\n", version);

    int messageLength = 0x0 & 0xff;
    messageLength = messageLength | hexInput[1];
    messageLength = messageLength << 16;
    int secondByte = hexInput[2] & 0xff;
    secondByte = secondByte << 8;
    messageLength = messageLength | secondByte;
    messageLength = messageLength | hexInput[3];
    printf("Message length is %d\n", messageLength);

    int requestFlag = hexInput[4] & 0b10000000;
    char *requestFlagStr = "Unset";
    if (requestFlag != 0)
    {
        requestFlagStr = "Set";
    }

    int proxiableFlag = hexInput[4] & 0b01000000;
    char *proxiableFlagStr = "Unset";
    if (proxiableFlag != 0)
    {
        proxiableFlagStr = "Set";
    }

    int errorFlag = hexInput[4] & 0b00100000;
    char *errorFlagStr = "Unset";
    if (errorFlag != 0)
    {
        errorFlagStr = "Set";
    }

    int potentiallyRetransmittedFlag = hexInput[4] & 0b00010000;
    char *potentiallyRetransmittedFlagStr = "Unset";
    if (potentiallyRetransmittedFlag != 0)
    {
        potentiallyRetransmittedFlagStr = "Set";
    }
    printf("Flags are set as follows\n Request Flag = %s\n Proxiable Flag = %s\n Error Flag = %s\n Potentially Retransmitted Flag = %s\n", requestFlagStr, proxiableFlagStr, errorFlagStr, potentiallyRetransmittedFlagStr);

    int commandCode = 0x0 & 0xff;
    commandCode |= hexInput[5] & 0xff;
    commandCode <<= 16;
    int secondByteInCommandCode = 0x0 & 0xff;
    secondByteInCommandCode |= hexInput[6] & 0xff;
    secondByteInCommandCode <<= 8;
    commandCode |= secondByteInCommandCode;
    commandCode |= hexInput[7];
    printf("Command code is %d\n", commandCode);

    int applicationId = 0x0 & 0xff;
    applicationId |= hexInput[8];
    applicationId <<= 24;
    int secondByteInApplicationId = 0x0 & 0xff;
    secondByteInApplicationId |= hexInput[9];
    secondByteInApplicationId <<= 8;
    secondByteInApplicationId |= hexInput[10];
    int thirdByteInApplicationId = 0x0 & 0xff;
    thirdByteInApplicationId |= secondByteInApplicationId;
    thirdByteInApplicationId <<= 8;
    thirdByteInApplicationId |= hexInput[11];
    applicationId |= thirdByteInApplicationId;
    printf("Application id is %d\n", applicationId);

    int hopToHopIdentifier = 0x0 & 0xff;
    hopToHopIdentifier |= hexInput[12] << 24;
    hopToHopIdentifier |= hexInput[13] << 16;
    hopToHopIdentifier |= hexInput[14] << 8;
    hopToHopIdentifier |= hexInput[15];
    printf("Hop to hop identifier is %d\n", hopToHopIdentifier);

    int endToEndIdentifier = 0x0 & 0xff;
    endToEndIdentifier |= hexInput[16] << 24;
    endToEndIdentifier |= hexInput[17] << 16;
    endToEndIdentifier |= hexInput[18] << 8;
    endToEndIdentifier |= hexInput[19];
    printf("End to end identifier is %d\n", endToEndIdentifier);

    // the rest are AVPs

    return 1;
}