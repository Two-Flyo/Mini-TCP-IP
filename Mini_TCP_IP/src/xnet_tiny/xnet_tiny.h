#ifndef XNET_TINY_H
#define XNET_TINY_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define XNET_CFG_PACKET_MAX_SIZE 1516

typedef struct _xnet_packet_t
{
	uint16_t size;	// 包中有效数据大小
	uint8_t* data;	// 包的数据起始地址
	uint8_t payload[XNET_CFG_PACKET_MAX_SIZE];	// 最大负载数据量
}xnet_packet_t;

typedef enum _xnet_err_t
{
	XNET_ERR_OK = 0,
	XNET_ERR_IO = -1
}xnet_err_t;



xnet_packet_t* xnet_alloc_for_send(uint16_t data_size);
xnet_packet_t* xnet_alloc_for_read(uint16_t data_size);

// 初始化
void xnet_init(void);
// 查询
void xnet_poll(void);


//对pcap_device库的封装
xnet_err_t xnet_driver_open(uint8_t* mac_addr);
xnet_err_t xnet_driver_send(xnet_packet_t* packet);
xnet_err_t xnet_driver_read(xnet_packet_t** packet);

#endif // XNET_TINY_H


