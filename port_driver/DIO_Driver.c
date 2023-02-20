//#include "Dio.h"
//#include "StandardTypes.h"
//#include "Dio_cfg.h" <-여기에 dio port number가 모두 define되어있음.

//cpu 32bit processor
typedef unsigned char boolean;
typedef unsigned char uint8;//unsigned 8bit integer : 0x00 ~ 0xFF
typedef unsigned short uint16;//unsigned 16bit integer : 0x00 ~ 0xFFFF
typedef unsigned long uint32;//unsigned 32bit integer : 0x00 ~ 0xFFFFFFFF
typedef unsigned long long uint64;//unsigned 64bit integer : 0x00 ~ 0xFFFFFFFFFFFFFFFF

typedef uint16 Dio_ChannelType;//DIO channel의 숫자ID
typedef uint8 Dio_PortType; //DIO port의 숫자ID
typedef struct{
    uint8 mask;//DIO channel group 표현?
    uint8 offset;//LSB부터 count해서, channel group의 위치
    Dio_PortType port;//지정된 channel group에서 몇번째 포트인지.
} Dio_ChannelGroupType;
typedef uint8 Dio_LevelType;//DIO channel이 가질 수 있는 값 level : STD_LOW(0x00)은 physical state 0v, STD_HIGH(0x01)은 physical state 5V(or 3.3V)의미
typedef uint32 Dio_PortLevelType;//DIO port의 값

//함수정의 고고