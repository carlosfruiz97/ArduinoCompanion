
#ifndef __TYPES_H
#define __TYPES_H

/* -- Constants---------------------------------------------------------------*/
#define MS_PER_SECOND       (1000)
#define BUTTON_INTERVAL     25


/* -- Game config ------------------------------------------------------------*/
#define BAUD_RATE           9600
#define CMD_STR             "CUSTOM-VARIABLE ard_d%d SET-VALUE %d\n"


const uint8_t ENABLED_PINS[] = {
  2,3,4,5,6,7,8,9,10,11,12,13,
  22,23,24,25,26,27,28,29,
  30,31,32,33,34,35,36,37,38,39,
  40,41,42,43,44,45,46,47,48,49,
  50,51,52,53
  };
const uint16_t NB_PINS = sizeof(ENABLED_PINS);

/* -- Types ------------------------------------------------------------------*/

/* -- DEBUG ------------------------------------------------------------------*/
#define LOG(x) Serial.print(x)
#define LOGX(x) Serial.print(x, HEX)
#define LOGS(s, x)      \
  {                     \
    Serial.print(F(s)); \
    Serial.print(" ");  \
    Serial.print(x);    \
  }
#define LOGSX(s, x)       \
  {                       \
    Serial.print(F(s));   \
    Serial.print(" ");    \
    Serial.print(x, HEX); \
  }
#define LOGSN(s, x) { LOGS(s,x); LOGF("\n"); } 
#define LOGF(s) Serial.print(F(s))


#endif /* __TYPES_H */
