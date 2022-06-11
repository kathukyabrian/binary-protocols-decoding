#include <stdlib.h>
#include <stdio.h>

char *resolveOpCode(int opcodeNumber)
{
    char *opCodeStr = "Unassigned";
    switch (opcodeNumber)
    {
    case 0:
        opCodeStr = "Standard Query";
        break;
    case 1:
        opCodeStr = "IQuery";
        break;
    case 2:
        opCodeStr = "Status";
        break;
    case 3:
        opCodeStr = "Unassigned";
        break;
    case 4:
        opCodeStr = "Notify";
        break;
    case 5:
        opCodeStr = "Update";
        break;
    case 6:
        opCodeStr = "DNS Stateful Operations";
        break;
    default:
        break;
    }

    return opCodeStr;
}

char *resolveRCode(int rCode)
{

    char *rCodeStr = "Unknown";
    if (rCode == 0)
    {
        rCodeStr = "No error";
    }
    else if (rCode == 3)
    {
        rCodeStr = "Name does not exist";
    }

    return rCodeStr;
}

int main()
{

    int hexInput[60] = {
        0xfd,
        0x1b,
        0x00,
        0x10,
        0x00,
        0x01,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x01,
        0x03,
        0x64,
        0x6c,
        0x76,
        0x03,
        0x69,
        0x73,
        0x63,
        0x03,
        0x6f,
        0x72,
        0x67,
        0x00,
        0x00,
        0x30,
        0x00,
        0x01,
        0x00,
        0x00,
        0x29,
        0x02,
        0x00,
        0x00,
        0x00,
        0x80,
        0x00,
        0x00,
        0x0c,
        0xfd,
        0xe9,
        0x00,
        0x08,
        0x23,
        0x34,
        0x3a,
        0x0f,
        0x34,
        0x11,
        0x60,
        0xad};

    int transactionId = 0;
    transactionId |= (hexInput[0] & 0xff) << 8;
    transactionId |= hexInput[1] & 0xff;
    printf("Transaction id is %x\n", transactionId);

    int flags = 0 & 0xff;
    flags |= (hexInput[2] & 0xff) << 8;
    flags |= hexInput[3] & 0xff;

    int queryResponseFlag = flags & 0b1000000000000000;
    char *queryResponseFlagStr = "Query";
    if (queryResponseFlag != 0)
    {
        queryResponseFlagStr = "Response";
    }

    int opcode = flags & 0b0111100000000000;

    int authoratitiveAnswer = flags & 0b0000010000000000;
    char *authoratitiveAnswerStr = "Unset";
    if (authoratitiveAnswer != 0)
    {
        authoratitiveAnswerStr = "Set";
    }

    int truncated = flags & 0b0000001000000000;
    char *truncatedStr = "Unset";
    if (truncated != 0)
    {
        truncatedStr = "Set";
    }

    int recursionDesired = flags & 0b0000000100000000;
    char *recursionDesiredStr = "Unset";
    if (recursionDesired != 0)
    {
        recursionDesiredStr = "Set";
    }

    int recursionAvailable = flags & 0b0000000010000000;
    char *recursionAvailableStr = "Unset";
    if (recursionAvailable != 0)
    {
        recursionAvailableStr = "Set";
    }

    int z = flags & 0b0000000001000000;
    char *zStr = "Unset";
    if (z != 0)
    {
        zStr = "Set";
    }

    int authenticData = flags & 0b0000000000100000;
    char *authenticDataStr = "Unset";
    if (authenticData != 0)
    {
        authenticDataStr = "Set";
    }

    int checkingDisabled = flags & 0b0000000000010000;
    char *checkingDisabledStr = "Unset";
    if (checkingDisabled != 0)
    {
        checkingDisabledStr = "Set";
    }

    int rCode = flags & 0b0000000000001111;

    printf("Flags are set as follows\n\t QR : %s\n\t Opcode : %s\n\t AA : %s\n\t TC : %s\n\t RD : %s\n\t RA : %s\n\t Z : %s\n\t AD : %s\n\t CD : %s\n\t Rcode : %s\n",
           queryResponseFlagStr,
           resolveOpCode(opcode),
           authoratitiveAnswerStr,
           truncatedStr,
           recursionDesiredStr,
           recursionAvailableStr,
           zStr,
           authenticDataStr,
           checkingDisabledStr,
           resolveRCode(rCode));

    int numberOfQuestions = 0;
    numberOfQuestions |= (hexInput[4] & 0xff) << 8;
    numberOfQuestions |= hexInput[5] & 0xff;
    printf("Number of questions is %d\n", numberOfQuestions);

    int numberOfAnswerRRs = 0;
    numberOfAnswerRRs |= (hexInput[6] & 0xff) << 8;
    numberOfAnswerRRs |= hexInput[7] & 0xff;
    printf("Number of Answer RRs is %d\n", numberOfAnswerRRs);

    int numberOfAuthorityRRs = 0;
    numberOfAuthorityRRs |= (hexInput[8] & 0xff) << 8;
    numberOfAuthorityRRs |= hexInput[9] & 0xff;
    printf("Number of Authority RRs is %d\n", numberOfAuthorityRRs);

    int numberOfAdditionalRRs = 0;
    numberOfAdditionalRRs |= (hexInput[10] & 0xff) << 8;
    numberOfAdditionalRRs |= hexInput[11] & 0xff;
    printf("Number of Additional RRs is %d\n", numberOfAdditionalRRs);

    return 1;
}