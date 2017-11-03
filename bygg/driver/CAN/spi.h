/*
 * SPIdriver.h
 *
 * Created: 27.10.2017 15:47:21
 *  Author: sondstaf
 */ 


#ifndef SPI_H_
#define SPI_H_

uint8_t spi_send(uint8_t cData);
uint8_t spi_read();
void spi_init();
void spi_chipselect(uint8_t select);




#endif /* SPI_H_ */