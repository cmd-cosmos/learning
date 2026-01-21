#include <stdio.h>
#include <windows.h>

#define MAX_PDU_PER_TRANSPORT 1000

typedef struct 
{
    
}segment_header_t;

typedef struct 
{
    
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