/* Copyright 2008-2009 The MathWorks, Inc. */

/*********************************************
 *                                           *  
 *   TI_C28x fuction lib for S16 operations  *
 *                                           *  
 *********************************************/

#ifndef MW_C28X_S16_H
#define MW_C28X_S16_H

/*
 * operation:         s16 * s16
 * saturation:        Yes
 * rounding mode:     N/A 
 */
inline int16_T c28x_mul_s16_s16_s16_sat(int16_T a, int16_T b)
{
	return __satlow16((int32_T)a * b);
}

/*
 * operation:         (s16 * s16) <<
 * saturation:        Yes
 * rounding mode:     N/A 
 */
inline int16_T c28x_mul_s16_s16_s16_sl_sat(int16_T a, int16_T b, uint16_T s)
{
	int16_T tmp;
	tmp = __satlow16((int32_T)a * b);
	return __satlow16((int32_T)tmp << s);
}

/*
 * operation:         (s16 * s16) >>
 * saturation:        Yes
 * rounding mode:     Floor 
 */
inline int16_T c28x_mul_s16_s16_s16_sr_sat(int16_T a, int16_T b, uint16_T s)
{
	int32_T tmp;
	tmp = ((int32_T)a * b) >> s;
	return __satlow16(tmp);
}

/*
 * operation:         (s16 * s16) >>
 * saturation:        Yes
 * rounding mode:     Ceil 
 */
inline int16_T c28x_mul_s16_s16_s16_sr_sat_ceil(int16_T a, int16_T b, uint16_T s)
{
	int32_T tmp;
	int32_T tmp_1;

	tmp_1 = (int32_T)a * b;
	tmp = ((tmp_1 & ((1 << s) - 1)) != 0) + (tmp_1 >> s);

	return __satlow16(tmp);
}

/*
 * operation:         (s16 * s16) >>
 * saturation:        Yes
 * rounding mode:     Zero 
 */
inline int16_T c28x_mul_s16_s16_s16_sr_sat_zero(int16_T a, int16_T b, uint16_T s)
{
	int32_T tmp;
	int32_T tmp_1;

	tmp_1 = (int32_T) a * b;
	tmp = ((tmp_1 < 0) && (tmp_1 & ((1 << s) - 1))) + (tmp_1 >> s);

	return __satlow16(tmp);
}

/*
 * operation:         (s16 * s16) >>
 * saturation:        Yes
 * rounding mode:     Nearest 
 */
inline int16_T c28x_mul_s16_s16_s16_sr_sat_near(int16_T a, int16_T b, uint16_T s)
{
	int32_T tmp;
	int32_T tmp_1;

	tmp_1 = (int32_T) a * b;
	tmp = ((tmp_1 & (1 << (s - 1)) ) != 0) + (tmp_1 >> s);

	return __satlow16(tmp);
}

/*
 * operation:         s16 + s16
 * saturation:        Yes
 * rounding mode:     N/A 
 */
inline int16_T c28x_add_s16_s16_s16_sat(int16_T a, int16_T b)
{
	return __satlow16((int32_T)a + b);
}

/*
 * operation:         s16 - s16
 * saturation:        Yes
 * rounding mode:     N/A 
 */
inline int16_T c28x_sub_s16_s16_s16_sat(int16_T a, int16_T b)
{
	return __satlow16((int32_T)a - b);
}


/*
 * operation:         s16 <<
 * saturation:        Yes
 * rounding mode:     N/A 
 */
inline int16_T c28x_sh_s16_s16_sl_sat(int16_T a, int16_T s)
{
	return __satlow16((int32_T)a << s);
}

#endif
