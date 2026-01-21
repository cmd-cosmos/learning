#include <stdio.h>
#include <stdint.h>
#include <windows.h>

#define MAX_PDU_PER_TRANSPORT 1000
#define MAX_DATA_SIZE         1460 // bytes


/**
 * @brief TCP segment header format 
 * 
 */
typedef struct 
{
    uint16_t sourcePort;
    uint16_t destinationPort;
    uint32_t sequenceNumber;
    uint32_t offsetAndFlags;
    uint16_t checksum;
    uint16_t urgentPointer;
    uint16_t options;
    uint16_t padding;
}segment_header_t;


/**
 * @brief UDP datagram header format 
 * 
 */
typedef struct 
{
    uint16_t sourcePort;
    uint16_t destinationPort;
    uint16_t length;
    uint16_t checksum;   
}datagram_header_t;

typedef struct
{

}segment_t;

typedef struct
{

}datagram_t;


typedef struct
{

}udp_t;

typedef struct
{

}tcp_t;

typedef enum mode{
    UDP, // 0
    TCP  // 1
} mode_t;

int main(void)
{
    int numPDU      = MAX_PDU_PER_TRANSPORT - 1000;
    mode_t protocol = 0;

    return EXIT_SUCCESS;
}