#include <avr/io.h>
#include <util/delay.h>

static unsigned int delays[] = {
	50,
	55,
	61,
	67,
	73,
	81,
	89,
	97,
	107,
	118,
	130,
	143,
	157,
	173,
	190,
	209,
	230,
	253,
	278,
	306,
	336,
	370,
	407,
	448,
	492,
	542,
	596,
	655,
	721,
	793,
	872,
	960,
	1056,
	1161,
	1277,
	1405,
	1546,
	1700,
	1870,
	2057,
	2263,
	2489,
	2738,
	3012,
};


static unsigned int delays2[] = {
	100,
	110,
	121,
	133,
	146,
	161,
	177,
	195,
	214,
	236,
	259,
	285,
	314,
	345,
	380,
	418,
	459,
	505,
	556,
	612,
	673,
	740,
	814,
	895,
	985,
	1083,
	1192,
	1311,
	1442,
	1586,
	1745,
	1919,
	2111,
	2323,
	2555,
	2810,
	3091,
	3400,
	3740,
	4114,
	4535,
	4978,
};
static int last_delay_index = 43;


#define PIN_HIGH() PORTB |= 1 << 4;
#define PIN_LOW() PORTB &= ~(1 << 4);

#define MAGIC(x) PIN_HIGH(); _delay_us(delays[x]); PIN_LOW(); _delay_us(10000 - delays[x]); break;


/*** MAIN ***/

int __attribute__((noreturn)) main(void)
{
	// outputs
	DDRB |= 1 << 4;
	PORTB &= ~(1 << 4);

	char d = 1;

	unsigned char delay_index = 0;

	unsigned char repeat;

	while (1) {

		for (repeat = 0; repeat < 6; repeat++) {

			switch (delay_index) {
				case 0: MAGIC(delay_index);
				case 1: MAGIC(delay_index);
				case 2: MAGIC(delay_index);
				case 4: MAGIC(delay_index);
				case 5: MAGIC(delay_index);
				case 6: MAGIC(delay_index);
				case 7: MAGIC(delay_index);
				case 8: MAGIC(delay_index);
				case 9: MAGIC(delay_index);
				case 10: MAGIC(delay_index);
				case 11: MAGIC(delay_index);
				case 12: MAGIC(delay_index);
				case 13: MAGIC(delay_index);
				case 14: MAGIC(delay_index);
				case 15: MAGIC(delay_index);
				case 16: MAGIC(delay_index);
				case 17: MAGIC(delay_index);
				case 18: MAGIC(delay_index);
				case 19: MAGIC(delay_index);
				case 20: MAGIC(delay_index);
				case 21: MAGIC(delay_index);
				case 22: MAGIC(delay_index);
				case 24: MAGIC(delay_index);
				case 25: MAGIC(delay_index);
				case 26: MAGIC(delay_index);
				case 27: MAGIC(delay_index);
				case 28: MAGIC(delay_index);
				case 29: MAGIC(delay_index);
				case 30: MAGIC(delay_index);
				case 31: MAGIC(delay_index);
				case 32: MAGIC(delay_index);
				case 34: MAGIC(delay_index);
				case 35: MAGIC(delay_index);
				case 36: MAGIC(delay_index);
				case 37: MAGIC(delay_index);
				case 38: MAGIC(delay_index);
				case 39: MAGIC(delay_index);
				case 40: MAGIC(delay_index);
				case 41: MAGIC(delay_index);
			}
		}

		delay_index += d;

		if (delay_index >= last_delay_index) {
			d = -1;
			delay_index = last_delay_index;
		}

		if (delay_index <= 0) {
			d = 1;
			delay_index = 0;
		}

	}

}
