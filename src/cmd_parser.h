#pragma once 
enum {
	CMD_ID_DNAME    = 0x01, // Get/Set device name, "\0" - default: ATC_xxxx
	CMD_MI_ID_MAC	= 0x10, // Get/Set MAC [+RandMAC], [size][mac[6][randmac[2]]]
	CMD_MI_ID_DNAME = 0x11, // Get/Set Mi key: DevNameId, [size]["\0"+miDevName]
	CMD_MI_ID_TBIND = 0x12, // Get/Set Mi keys: Token & Bind, [size][keys]
	CMD_MI_ID_CFG   = 0x13, // Mi cfg data, [size][data]
	CMD_MI_ID_KDEL  = 0x14, // Mi marked as deleted keys, [size][data]
	CMD_MI_ID_KALL  = 0x15, // Get all mi keys
	CMD_MI_ID_REST  = 0x16, // Restore prev mi token & bindkeys
	CMD_MI_ID_CLR	= 0x17, // Delete all mi keys
	CMD_ID_COMFORT  = 0x20, // Get/set comfort parameters
	CMD_ID_EXTDATA  = 0x22, // Get/set show ext. data
	CMD_ID_UTC_TIME = 0x23, // Get/set utc time (if USE_CLOCK = 1)
	CMD_ID_MEASURE  = 0x33, // Start/stop notify measures in connection mode
	CMD_ID_LOGGER   = 0x35, // Read memory measures
	CMD_ID_TRG      = 0x44, // Get/set trg data
	CMD_ID_TRG_OUT  = 0x45, // Set trg out
	CMD_ID_TRG_NS   = 0x4A, // Get/set trg data (not save to Flash)
	CMD_ID_CFG      = 0x55,	// Get/set config
	CMD_ID_CFG_DEF  = 0x56,	// Get default config
	CMD_ID_CFG_NS   = 0x5A,	// Get/set config (not save to Flash)
	CMD_ID_LCD_DUMP = 0x60, // Get/set lcd buf
	CMD_ID_LCD_FLG  = 0x61, // Start/stop notify lcd dump and ...
	CMD_ID_PINCODE  = 0x70, // Set new PinCode 0..999999
	// Debug commands (unsupported in different versions!):
	CMD_ID_MTU		= 0x71, // Request Mtu Size Exchange (23..255)
	CMD_ID_REBOOT	= 0x72, // Set Reboot on disconnect
	CMD_ID_DEBUG    = 0xDE  // Test/Debug
} CMD_MI_ID_KEYS;

#define MI_KEYTBIND_ID  0x10 // id token + bindkey
#define MI_KEYSEQNUM_ID 0x04 // id mibeacon SEQNUM
#define MI_KEYDNAME_ID  0x01 // id device name
#define MI_KEYDELETE_ID 0x00 // mark delete key
#define MI_KEYTBIND_SIZE (12+16) // buf token + bindkey size
#define MI_KEYDNAME_SIZE (20) // device name buf size

typedef struct __attribute__((packed)) _blk_mi_keys_t {
	uint8_t id;
	uint8_t klen;	// max length, end length, current length, ...
	uint8_t data[MI_KEYTBIND_SIZE]; // token + bindkey
} blk_mi_keys_t, * pblk_mi_keys_t;
extern blk_mi_keys_t keybuf;

uint8_t * find_mi_keys(uint16_t chk_id, uint8_t cnt);

uint8_t mi_key_stage;
uint8_t get_mi_keys(uint8_t chk_stage);

void cmd_parser(void * p);
