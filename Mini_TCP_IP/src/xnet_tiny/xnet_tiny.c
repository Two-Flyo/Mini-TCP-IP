#include "xnet_tiny.h"

#define min(a, b)	((a)>(b) ? (b):(a))

static xnet_packet_t tx_packet, rx_packet;

//发送
xnet_packet_t* xnet_alloc_for_send(uint16_t data_size)
{
	// 给协议的包头预留空间
	tx_packet.data = tx_packet.payload + XNET_CFG_PACKET_MAX_SIZE - data_size;
	tx_packet.size = data_size;

	return &tx_packet;
}

// 读取
xnet_packet_t* xnet_alloc_for_read(uint16_t data_size)
{
	rx_packet.data = rx_packet.payload;
	rx_packet.size = data_size;

	return &rx_packet;
}

//添加包头
static void add_header(xnet_packet_t* packet, uint16_t header_size)
{
	packet->data -= header_size;
	packet->size += header_size;
}

//移除包头
static void remove_header(xnet_packet_t* packet, uint16_t header_size)
{
	packet->data += header_size;
	packet->size -= header_size;
}


static void truncate_packet(xnet_packet_t* packet, uint16_t size)
{
	packet->size = min(packet->size, size);
}

void xnet_init(void)
{

}

void xnet_poll(void)
{

}

