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
    puts("\n---- UDP Transmission ----");
    
    for (uint32_t i = 0; i < MAX_PDU_PER_TRANSPORT; i++)
    {
        if (packet_drop())
        {
            udpStats.dropped++;
            printf("[UDP] PDU %u DROPPED\n", i);
            Sleep(300);
        }
        else
        {
            udpStats.received++;
            printf("[UDP] PDU %u RECEIVED\n", i);
            Sleep(300);
        }
    }
    Sleep(2000);
    puts("\nUDP Results: ");
    printf("Received: %u\n", udpStats.received);
    printf("Dropped:  %u\n", udpStats.dropped);
}

void tcp_transport(void)
{
    tcp_t tcpStats = {0};
    tcpStats.expectedSeq = 0;

    puts("\n---- TCP Transmission ----");

    for (uint32_t seq = 0; seq < MAX_PDU_PER_TRANSPORT; seq++)
    {
        if (packet_drop())
        {
            tcpStats.dropped++;
            printf("[TCP] PDU %u LOST -> Retransmission Required\n", seq);
            Sleep(300);
            continue;
        }
        if (seq == tcpStats.expectedSeq)
        {
            tcpStats.received++;
            tcpStats.expectedSeq++;
            printf("[TCP] PDU %u RECEIVED (IN ORDER)\n", seq);
            Sleep(300);
        }
        else
        {
            tcpStats.dropped++;
            printf("[TCP] PDU %u OUT OF ORDER (expected %u)\n", seq, tcpStats.expectedSeq);
            Sleep(300);
        }
    }
    Sleep(2000);
    puts("\nTCP Results: ");
    printf("Received: %u\n", tcpStats.received);
    printf("Dropped:  %u\n", tcpStats.dropped);
}

int main(void)
{
    srand((unsigned int)time(NULL));

    int selectedProtocol = MessageBox(NULL, "TCP - YES, UDP - NO", "Transport Layer Protocol Selection", MB_YESNO);

    if (selectedProtocol == IDYES)
    {
        puts("TCP Selected");
        tcp_transport();
    }
    else if (selectedProtocol == IDNO)
    {
        puts("UDP Selected");
        udp_transport();
    }

    return EXIT_SUCCESS;
}