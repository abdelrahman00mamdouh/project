#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED

#define SET_BIT(REG,BIT) REG|=(1<<BIT)

#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)

#define GET_BIT(REG,BIT) ((REG>>BIT)&1)

#define TGL_BIT(REG,BIT) REG^=(1<<BIT)


#endif // BIT_MATH_H_INCLUDED
