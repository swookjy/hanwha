//#include "Port.h"

#include <stdint.h>

#define PORT_E_0 0x0000
#define PORT_E_1 0x0001

//cpu 32bit processor
typedef unsigned char boolean;
typedef unsigned char uint8;//unsigned 8bit integer : 0x00 ~ 0xFF
typedef unsigned short uint16;//unsigned 16bit integer : 0x00 ~ 0xFFFF
typedef unsigned long uint32;//unsigned 32bit integer : 0x00 ~ 0xFFFFFFFF
typedef unsigned long long uint64;//unsigned 64bit integer : 0x00 ~ 0xFFFFFFFFFFFFFFFF

typedef struct
{
    uint16  vendorID;               /**< @brief vendor ID */
    uint16  moduleID;               /**< @brief BSW module ID */
    uint8   sw_major_version;       /**< @brief BSW module software major version */
    uint8   sw_minor_version;       /**< @brief BSW module software minor version */
    uint8   sw_patch_version;       /**< @brief BSW module software patch version */
} Std_VersionInfoType;//defined in Std_Types.h


typedef uint32 Port_PinType;//uint8, uint16, uint32 based on the specific MCU -> s32k : uint32
typedef uint8_t Port_PinModeType;//data type for the number, mentioned in platform spec, of a port pin. It's same with the index of the PCR Register

typedef enum{
    PORT_PIN_IN,//set port pin as input
    PORT_PIN_OUT//set port pin as output
} Port_PinDirectionType;

//port_configType structure : configure each PIN
typedef struct{
	Port_PinModeType mode; //pin mode(DIO, ADC, SPI ,,,)
	Port_PinDirectionType direction;//pin direction(input, output)
	uint8_t init_value;//pin level init value
	uint8_t direction_change;//pin direction changeable during runtime(STD_ON/STD_OFF)
	uint8_t mode_change;//pin mode changeable during runtime(STD_ON/STD_OFF)
}Port_configType;
//type of the external data structure containing the initialization for this module. <- 기존구조체값 + 해당 모듈의 초기값 <- 모르겟당ㅎ


//port configuration
void Port_Init(const Port_configType* ConfigPtr);

//set the direction of a port pin
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

//refresh the direction of all port pins
void Port_RefreshPortDirection(void);

//change the mode of a port pin
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);