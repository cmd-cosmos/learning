#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <windows.h>

#define MAX_PDU_PER_TRANSPORT 1000
#define MAX_DATA_SIZE         1460 // bytes
#define PACKET_LOSS_RATE      10   // % loss in UDP transport


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
    uint32_t id;
    uint32_t sequence;
    uint16_t length;
    uint8_t  data[MAX_DATA_SIZE];
}pdu_t;

typedef struct
{
    uint32_t received;
    uint32_t dropped;
}udp_t;

typedef struct
{
    uint32_t expectedSeq;
    uint32_t received;
    uint32_t dropped;
}tcp_t;

typedef enum 
{
    MODE_UDP=0, // 0
    MODE_TCP  // 1
} mode_t;

int packet_drop(void)
{
    return (rand() % 100) < PACKET_LOSS_RATE;
}

void udp_transport(void)
{
    udp_t udpStats = {0};
    puts("---- UDP Transmission ----");
    
    for (uint32_t i = 0; i < MAX_PDU_PER_TRANSPORT; i++)
    {
        if (packet_drop())
        {
            udpStats.dropped++;
            printf("[UDP] PDU %u DROPPED\n", i);
        }
        else
        {
            udpStats.received++;
            printf("[UDP] PDU %u RECEIVED\n", i);
        }
    }

    puts("\nUDP Results: ");
    printf("Received: %u\n", udpStats.received);
    printf("Dropped:  %u\n", udpStats.dropped);
}

int main(void)
{
    int selectedProtocol = MessageBox(NULL, "Transport Layer Protocol Selection", "TCP - YES, UDP - NO", MB_YESNO);
    if (selectedProtocol == IDYES)
    {
        puts("TCP Selected");
    }
    else if (selectedProtocol == IDNO)
    {
        puts("UDP Selected");
    }
    

    return EXIT_SUCCESS;
}