#pragma once 
enum {
	CMD_MI_ID_MAC	= 0x10, // MAC+RandMAC
	CMD_MI_ID_DNAME = 0x11, // Mi key: DevNameId
	CMD_MI_ID_TBIND = 0x12, // Mi keys: Token & Bind
	CMD_MI_ID_CFG = 0x13,	// Mi cfg data
	CMD_MI_ID_KDEL = 0x14, // Mi marked as deleted keys
	CMD_MI_ID_KALL = 0x15, // get all mi keys
	CMD_MI_ID_REST = 0x16, // restore prev mi token & bindkeys
	CMD_ID_EXTDATA = 0x22, // Get/set show ext. data
	CMD_ID_MEASURE = 0x33, // Start/stop measures in connection mode
	CMD_ID_CFG = 0x55,		// Get/set config
	CMD_ID_CFG_NS = 0x5A	// Get/set config (not save to Flash)
} CMD_MI_ID_KEYS;

uint8_t mi_key_stage;
uint8_t get_mi_keys(uint8_t chk_stage);

void cmd_parser(void * p);