/*
 Copyright (c) 2017 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef GIMX_NETWORK_PROTOCOL_H_
#define GIMX_NETWORK_PROTOCOL_H_

#include <stdint.h>

#ifdef WIN32
#define PACKED __attribute__((gcc_struct, packed))
#else
#define PACKED __attribute__((packed))
#endif

typedef enum {
    E_NETWORK_PACKET_CONTROLLER,
    E_NETWORK_PACKET_IN_REPORT,
} e_network_packet_type;

typedef struct PACKED
{
  unsigned char packet_type; // E_NETWORK_PACKET_IN_REPORT
  unsigned char nbAxes; // number of elements in the following array
  struct
  {
    unsigned char index; // 1 MSB: 0 = relative axis, 1 = absolute axis, 7 LSB = index
    int value;
  } axes[0];
} s_network_packet_in_report;

typedef struct PACKED
{
  unsigned char packet_type; // E_NETWORK_PACKET_CONTROLLER
  unsigned char controller_type;
} s_network_packet_controller;

#endif /* GIMX_NETWORK_PROTOCOL_H_ */
