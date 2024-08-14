#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Packet {
    int arrival_time ;
    int processing_time ;
    bool is_dropped ;
    int start ;
} Packet ;

void *emalloc(int n) {
    void *p ;

    p = malloc(n) ;
    if (p == NULL) {
        printf("malloc of %d bytes failed\n", n);
        exit(1);
    }

    return p ;
}

void *efree(void *p) {
    if (p == NULL) {
        printf("ptr points to NULL\n");
        exit(1);
    }
    free(p);
    return (p = NULL);
}

int processor(Packet *packets, int incoming_packets, int size_of_buffer) {
    int clock = 0 ;
    int buffer[size_of_buffer] ;
    int buffer_start = 0, buffer_end = 0, buffer_count = 0 ;

    for (int i = 0; i < incoming_packets; i++) {
        Packet *packet = &packets[i] ;

        if (buffer_count > 0) {
            int finish_time = clock + packets[buffer[buffer_start]].processing_time ;
            if (finish_time <= packet->arrival_time) {
                clock = finish_time ;
                buffer_start = (buffer_start + 1) % size_of_buffer ;
                buffer_count-- ;
            }
        }

        if (buffer_count == size_of_buffer) {
            packet->is_dropped = true ;
        } else {
            buffer[buffer_end] = i ;
            buffer_end = (buffer_end + 1) % size_of_buffer ;
            buffer_count++ ;

            if (clock < packet->arrival_time) {
                clock = packet->arrival_time ;
            }

            packet->start = clock ;
            clock += packet->processing_time ;
        }
    }

    return clock ;
}

int main(void) {
    int size_of_buffer, incoming_packets ;
    Packet *packets ;

    scanf("%d", &size_of_buffer) ;
    scanf("%d", &incoming_packets) ;

    if (incoming_packets == 0) {
        exit(0) ;
    }

    packets = emalloc(incoming_packets * sizeof(*packets)) ;

    for (int i = 0; i < incoming_packets; i++) {
        scanf("%d", &packets[i].arrival_time) ;
        scanf("%d", &packets[i].processing_time) ;
        packets[i].is_dropped = false ;
        packets[i].start = 0 ;
    }

    processor(packets, incoming_packets, size_of_buffer) ;

    for (int i = 0; i < incoming_packets; i++) {
        if (packets[i].is_dropped) {
            printf("%d\n", -1) ;
        } else {
            printf("%d\n", packets[i].start) ;
        }
    }

    packets = efree(packets) ;
    return 0 ;
}