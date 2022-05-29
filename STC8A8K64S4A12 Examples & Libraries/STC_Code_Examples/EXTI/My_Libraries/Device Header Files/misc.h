/***************************************************************************************************
    Some commonly used definitions
 ***************************************************************************************************/

#define LOW                               0
#define HIGH                              1

#define FALSE                             0
#define TRUE                              1

#define NO                                0
#define YES                               1

#define DISABLE                           0
#define ENABLE                            1

/***************************************************************************************************/


/***************************************************************************************************
    Basic data types
 ***************************************************************************************************/

typedef signed char           sint8_t;
typedef unsigned char         uint8_t;

typedef signed int            sint16_t;
typedef unsigned int          uint16_t;

typedef signed long int       sint32_t;
typedef unsigned long int     uint32_t;

#define C_SINT8_MAX           0x7F
#define C_SINT8_MIN           -128

#define C_UINT8_MAX           0xFF
#define C_UINT8_MIN           0x00

#define C_SINT16_MAX          32767
#define C_SINT16_MIN          -32768

#define C_UINT16_MAX          0xFFFF
#define C_UINT16_MIN          0x0000

#define C_SINT32_MAX          2147483647
#define C_SINT32_MIN          -2147483648

#define C_UINT32_MAX          0xFFFFFFFF
#define C_UINT32_MIN          0x00000000

/***************************************************************************************************/


/***************************************************************************************************
                                Macros for Bit Manipulation
 ****************************************************************************************************/

#define bit_shift_right(val, shift_size)                    (val >> shift_size)
#define bit_shift_left(val, shift_size)                     (val << shift_size)
#define bit_mask(bit_pos)                                   bit_shift_left(1, bit_pos)

#define bit_set(val, bit_val)                               (val |= bit_mask(bit_val))
#define bit_clr(val, bit_val)                               (val &= (~bit_mask(bit_val)))
#define bit_tgl(val, bit_val)                               (val ^= bit_mask(bit_val))
#define get_bit(val, bit_val)                               (val & bit_mask(bit_val))
#define get_reg(val, msk)                                   (val & msk)

#define set_bits(reg, val, pos)                             (reg |= bit_shift_left(val, pos))    
#define clr_bits(reg, val, pos)                             (reg &= ~bit_shift_left(val, pos)) 

#define or_mask(val, msk)                                   (val |= msk)
#define and_mask(val, msk)                                  (val &= msk)   

#define test_if_bit_set(val, bit_val)                       (get_bit(val, bit_val) != FALSE)
#define test_if_bit_cleared(val, bit_val)                   (get_bit(val, bit_val) == FALSE)

#define test_if_all_bits_set(val, msk)                      (get_reg(val, msk) == msk)
#define test_if_any_bit_set(val, msk)                       (get_reg(val, msk) != FALSE)

/**************************************************************************************************/


/***************************************************************************************************
                           Definition of common Bit-Masks
 ***************************************************************************************************/

#define BIT0            bit_mask(0)
#define BIT1            bit_mask(1)
#define BIT2            bit_mask(2)
#define BIT3            bit_mask(3)
#define BIT4            bit_mask(4)
#define BIT5            bit_mask(5)
#define BIT6            bit_mask(6)
#define BIT7            bit_mask(7)
#define BIT8            bit_mask(8)
#define BIT9            bit_mask(9)
#define BIT10           bit_mask(10)
#define BIT11           bit_mask(11)
#define BIT12           bit_mask(12)
#define BIT13           bit_mask(13)
#define BIT14           bit_mask(14)
#define BIT15           bit_mask(15)
#define BIT16           bit_mask(16)
#define BIT17           bit_mask(17)
#define BIT18           bit_mask(18)
#define BIT19           bit_mask(19)
#define BIT20           bit_mask(20)
#define BIT21           bit_mask(21)
#define BIT22           bit_mask(22)
#define BIT23           bit_mask(23)
#define BIT24           bit_mask(24)
#define BIT25           bit_mask(25)
#define BIT26           bit_mask(26)
#define BIT27           bit_mask(27)
#define BIT28           bit_mask(28)
#define BIT29           bit_mask(29)
#define BIT30           bit_mask(30)
#define BIT31           bit_mask(31)

/**************************************************************************************************/


/***************************************************************************************************
                             Macros to find the mod of a number
 ***************************************************************************************************/

#define get_mod_8(dividend, divisor)   ((uint8_t)(dividend - (divisor * (uint8_t) (dividend / divisor))))
#define get_mod_16(dividend, divisor) ((uint16_t)(dividend - (divisor * (uint16_t)(dividend / divisor))))
#define get_mod_32(dividend, divisor) ((uint32_t)(dividend - (divisor * (uint32_t)(dividend / divisor))))

/***************************************************************************************************/


/***************************************************************************************************
                  Macros for Dec t0 ASCII, HeX to ASCII and ASCII to Hex conversion
 ****************************************************************************************************/

#define conv_dec_to_ASCII(value)              (0x30 + value)
#define conv_hex_to_ASCII(value)              ((value > 0x09) ? (0x37 + value) : (0x30 + value)) 
#define conv_ASCII_to_hex(value)              ((value > 0x39) ? (value - 0x37) : (value - 0x30))

/***************************************************************************************************/


/***************************************************************************************************
                     Macros to extract the nibbles
 ***************************************************************************************************/

#define extract_nibble_0to3(reg)             ((uint8_t)(reg & 0x0F))
#define extract_nibble_4to7(reg)             ((uint8_t)(bit_shift_right(reg, 4) & 0x0F))
#define extract_nibble_8to11(reg)            ((uint8_t)(bit_shift_right(reg, 8) & 0x0F))
#define extract_nibble_12to15(reg)           ((uint8_t)(bit_shift_right(reg, 12) & 0x0F))
#define extract_nibble_16to19(reg)           ((uint8_t)(bit_shift_right(reg, 16) & 0x0F))
#define extract_nibble_20to23(reg)           ((uint8_t)(bit_shift_right(reg, 20) & 0x0F))
#define extract_nibble_24to27(reg)           ((uint8_t)(bit_shift_right(reg, 24) & 0x0F))
#define extract_nibble_28to31(reg)           ((uint8_t)(bit_shift_right(reg, 28) & 0x0F))

/**************************************************************************************************/


/***************************************************************************************************
                     Macros to extract the Byte
 ***************************************************************************************************/

#define extract_byte_0to7(reg)              ((uint8_t)(reg & 0xFF))
#define extract_byte_8to15(reg)             ((uint8_t)(bit_shift_right(reg, 8) & 0xFF))
#define extract_byte_16to23(reg)            ((uint8_t)(bit_shift_right(reg, 16) & 0xFF))
#define extract_byte_24to31(reg)            ((uint8_t)(bit_shift_right(reg, 24) & 0xFF))

/**************************************************************************************************/